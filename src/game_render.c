/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:55:33 by dateixei          #+#    #+#             */
/*   Updated: 2023/09/10 17:20:11 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray_var()
{
	ray()->dir_ray_x = game()->dir_x + game()->plane_x * ray()->camera_x;
	ray()->dir_ray_y = game()->dir_y + game()->plane_y * ray()->camera_x;
	ray()->map_x = (int)game()->pos_x;
	ray()->map_y = (int)game()->pos_y;
	ray()->delta_dist_x = fabs(1 / ray()->dir_ray_x);
	ray()->delta_dist_y = fabs(1 / ray()->dir_ray_y);
	ray()->hit = 0;
}

void	win_render(void)
{
	int	x;
	int	y;

	x = 0;
	if (game()->buf == 1)
		start_buffer();
	while (x < WIDTH)
	{
		ray()->camera_x = 2 * x / (double)WIDTH - 1;
		init_ray_var();
		if (ray()->dir_ray_x < 0)
		{
			ray()->step_x = -1;
			ray()->side_dist_x = (game()->pos_x - ray()->map_x) * ray()->delta_dist_x;
		}
		else
		{
			ray()->step_x = 1;
			ray()->side_dist_x = (ray()->map_x + 1.0 - game()->pos_x) * ray()->delta_dist_x;
		}
		if (ray()->dir_ray_y < 0)
		{
			ray()->step_y = -1;
			ray()->side_dist_y = (game()->pos_y - ray()->map_y) * ray()->delta_dist_y;
		}
		else
		{
			ray()->step_y = 1;
			ray()->side_dist_y = (ray()->map_y + 1.0 - game()->pos_y) * ray()->delta_dist_y;
		}
		while (ray()->hit == 0)
		{
			if (ray()->side_dist_x < ray()->side_dist_y)
			{
				ray()->side_dist_x += ray()->delta_dist_x;
				ray()->map_x += ray()->step_x;
				ray()->side = 0;
			}
			else
			{
				ray()->side_dist_y += ray()->delta_dist_y;
				ray()->map_y += ray()->step_y;
				ray()->side = 1;
			}
			if (game()->map[ray()->map_x][ray()->map_y] != '0')
			{
				ray()->hit = 1;
				if (ray()->side == 0)
				{
					if (ray()->step_x == -1)
						ray()->draw_side = 0;
					else
						ray()->draw_side = 1;
					
				}
				else
					if (ray()->step_y == -1)
						ray()->draw_side = 2;
					else
						ray()->draw_side = 3;
			}
		}
		
		if (ray()->side == 0)
			ray()->perp_wall_dist = (ray()->map_x - game()->pos_x + (1 - ray()->step_x) / 2) / ray()->dir_ray_x;
		else
			ray()->perp_wall_dist = (ray()->map_y - game()->pos_y + (1 - ray()->step_y) / 2) / ray()->dir_ray_y;
		
		ray()->line_height = (int)(HEIGHT / ray()->perp_wall_dist);
		
		ray()->draw_start = -ray()->line_height / 2 + HEIGHT / 2;
		if (ray()->draw_start < 0)
			ray()->draw_start = 0;
		ray()->draw_end = ray()->line_height / 2 + HEIGHT / 2;
		if (ray()->draw_end >= HEIGHT)
			ray()->draw_end = HEIGHT - 1;
		
		if (ray()->side == 0)
			ray()->wall_x = game()->pos_y + ray()->perp_wall_dist * ray()->dir_ray_y;
		else
			ray()->wall_x = game()->pos_x + ray()->perp_wall_dist * ray()->dir_ray_x;
		ray()->wall_x -= floor(ray()->wall_x);

		if (ray()->draw_side == 0 && game()->map[(int)ray()->map_x][ray()->map_y] == '1')
			game()->nbr_spr = 0;
		else if (ray()->draw_side == 1 && game()->map[(int)ray()->map_x][ray()->map_y] == '1')
			game()->nbr_spr = 1; 
		else if(ray()->draw_side == 2 && game()->map[(int)ray()->map_x][ray()->map_y] == '1')
			game()->nbr_spr = 2;
		else if(ray()->draw_side == 3 && game()->map[(int)ray()->map_x][ray()->map_y] == '1')
			game()->nbr_spr = 3;
		else
			game()->nbr_spr = 4;

		ray()->tex_x = (int)(ray()->wall_x * (double)game()->img[game()->nbr_spr].width);
		if (ray()->side == 0 && ray()->dir_ray_x > 0)
			ray()->tex_x = game()->img[game()->nbr_spr].width - ray()->tex_x - 1;
		if (ray()->side == 1 && ray()->dir_ray_y < 0)
			ray()->tex_x = game()->img[game()->nbr_spr].width - ray()->tex_x - 1;

		ray()->step = 1.0 * game()->img[game()->nbr_spr].width / ray()->line_height;

		ray()->tex_pos = (ray()->draw_start - HEIGHT / 2 + ray()->line_height / 2) * ray()->step;
		
		y = 0;
		while (y < HEIGHT)
		{
			if (y <= ray()->draw_start)
				game()->color = 0x32a873;
			else if (y > ray()->draw_start && y < ray()->draw_end)
			{
				ray()->tex_y = (int)ray()->tex_pos & (game()->img[game()->nbr_spr].height - 1);
				ray()->tex_pos += ray()->step;
				game()->color = game()->sprite[game()->nbr_spr][game()->img[game()->nbr_spr].height * ray()->tex_y  + ray()->tex_x];
			}
			else
				game()->color = 0x3d3329;
			game()->buffer[y][x] = game()->color;
			game()->buf = 1;
			y++;
		}
		x++;
	}
}

void	draw()
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			game()->mlx_data[i * WIDTH + j] = game()->buffer[i][j];
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game()->mlx, game()->win, game()->mlx_img, 0, 0);
}
		// if (ray()->draw_side == 0 && game()->map[(int)ray()->map_x][ray()->map_y] == '1')
		// 	game()->color = 0xfc5e03;
		// else if (ray()->draw_side == 1 && game()->map[(int)ray()->map_x][ray()->map_y] == '1')
		// 	game()->color = 0x372491; 
		// else if(ray()->draw_side == 2 && game()->map[(int)ray()->map_x][ray()->map_y] == '1')
		// 	game()->color = 0x372491;
		// else if(ray()->draw_side == 3 && game()->map[(int)ray()->map_x][ray()->map_y] == '1')
		// 	game()->color = 0xb51991;
		// else
		// 	game()->color = 0xc40a23;
		// int y = 0;
		// while (y <= HEIGHT)
		// {
		// 	if (y <= ray()->draw_start)
		// 		mlx_pixel_put(game()->mlx, game()->win, x, y, 0x6770cf);
		// 	else if (y <= ray()->draw_end && y >= ray()->draw_start)
		// 		mlx_pixel_put(game()->mlx, game()->win, x, y, game()->color);
		// 	else if (y > ray()->draw_end)
		// 		mlx_pixel_put(game()->mlx, game()->win, x, y, 0x8f462e);
		// 	y++;
		// }
		// x++;