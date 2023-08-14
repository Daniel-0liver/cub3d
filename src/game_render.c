/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:55:33 by dateixei          #+#    #+#             */
/*   Updated: 2023/08/14 02:33:17 by dateixei         ###   ########.fr       */
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

	x = 0;
	if (game()->frame == 50)
	{
		mlx_clear_window(game()->mlx, game()->win.screen);
		game()->frame = 0;
	}
	else
		game()->frame++;
	while (x < game()->win.width)
	{
		ray()->camera_x = 2 * x / (double)game()->win.width - 1;
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
			if (game()->map[ray()->map_x][ray()->map_y] > 0)
				ray()->hit = 1;
		}
		if (ray()->side == 0)
			ray()->perp_wall_dist = (ray()->map_x - game()->pos_x + (1 - ray()->step_x) / 2) / ray()->dir_ray_x;
		else
			ray()->perp_wall_dist = (ray()->map_y - game()->pos_y + (1 - ray()->step_y) / 2) / ray()->dir_ray_y;
		ray()->line_height = (int)(game()->win.height / ray()->perp_wall_dist);
		ray()->draw_start = -ray()->line_height / 2 + game()->win.height / 2;
		if (ray()->draw_start < 0)
			ray()->draw_start = 0;
		ray()->draw_end = ray()->line_height / 2 + game()->win.height / 2;
		if (ray()->draw_end >= game()->win.height)
			ray()->draw_end = game()->win.height - 1;
		
		if (game()->map[(int)game()->pos_y][(int)game()->pos_x] == 1)
			game()->color = 0xFF0000;
		if (game()->map[(int)game()->pos_y][(int)game()->pos_x] == 2)
			game()->color = 0x00FF00;
		if (game()->map[(int)game()->pos_y][(int)game()->pos_x] == 3)
			game()->color = 0x0000FF;
		if (game()->map[(int)game()->pos_y][(int)game()->pos_x] == 4)
			game()->color = 0xFFFFFF;
		else
			game()->color = 0xFFFF00;
		while (ray()->draw_start <= ray()->draw_end)
		{
			mlx_pixel_put(game()->mlx, game()->win.screen, x, ray()->draw_start, game()->color);
			ray()->draw_start++;
		}		
		x++;
	}
	
}









	// int x = 0;
	// int y = 0;

	// while (x < 400)
	// {
	// 	y = 0;
	// 	while (y < 600)
	// 	{
	// 		if (y > (200 - game()->distance) && y < 400)
	// 		{
	// 			mlx_string_put(game()->mlx, game()->win.screen, x, y, 0xFFFFFFFF, "#");
	// 			y++;
	// 		}
	// 		else
	// 		{
	// 			mlx_pixel_put(game()->mlx, game()->win.screen, x, y, 0xFF333333);
	// 			y++;
	// 		}
	// 	} 
	// 	x++;
	// }
	// mlx_mouse_get_pos(game()->mlx, game()->win.screen, &x, &y);
	// mlx_pixel_put(game()->mlx, game()->win.screen, x, y, 0xFFFFFF00);
	// mlx_pixel_put(game()->mlx, game()->win.screen, x+10, y+10, 0xFFFFFF00);
	// mlx_pixel_put(game()->mlx, game()->win.screen, x+10, y+10, 0xFFFFFF00);
	// mlx_pixel_put(game()->mlx, game()->win.screen, x+10, y+10, 0xFFFFFF00);
	// mlx_pixel_put(game()->mlx, game()->win.screen, x+20, y+20, 0xFFFFFF00);
	// mlx_pixel_put(game()->mlx, game()->win.screen, x+20, y+20, 0xFFFFFF00);
	// mlx_pixel_put(game()->mlx, game()->win.screen, x+20, y+20, 0xFFFFFF00);
	// mlx_pixel_put(game()->mlx, game()->win.screen, x+30, y+30, 0xFFFFFF00);
	// mlx_pixel_put(game()->mlx, game()->win.screen, x+30, y+30, 0xFFFFFF00);
	// mlx_pixel_put(game()->mlx, game()->win.screen, x+30, y+30, 0xFFFFFF00);