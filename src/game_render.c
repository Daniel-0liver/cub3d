/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:55:33 by dateixei          #+#    #+#             */
/*   Updated: 2023/09/29 21:52:38 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray_var(int x)
{
	ray()->camera_x = 2 * x / (double)WIDTH - 1;
	ray()->dir_ray_x = game()->dir_x + game()->plane_x * ray()->camera_x;
	ray()->dir_ray_y = game()->dir_y + game()->plane_y * ray()->camera_x;
	ray()->map_x = (int)game()->pos_x;
	ray()->map_y = (int)game()->pos_y;
	ray()->delta_dist_x = fabs(1 / ray()->dir_ray_x);
	ray()->delta_dist_y = fabs(1 / ray()->dir_ray_y);
	ray()->hit = 0;
}

int	my_mlx_pixel_get(t_img *img, int x, int y)
{
	return (*(unsigned int *)(img->data + (y * img->size_l + \
x * (img->bits_per_pixel / 8))));
}

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	dst = game()->mlx_data + (y * game()->size_l + x \
		* (game()->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	calc_step_side(void)
{
	if (ray()->dir_ray_x < 0)
	{
		ray()->step_x = -1;
		ray()->side_dist_x = (game()->pos_x \
			- ray()->map_x) * ray()->delta_dist_x;
	}
	else
	{
		ray()->step_x = 1;
		ray()->side_dist_x = (ray()->map_x \
			+ 1.0 - game()->pos_x) * ray()->delta_dist_x;
	}
	if (ray()->dir_ray_y < 0)
	{
		ray()->step_y = -1;
		ray()->side_dist_y = (game()->pos_y \
			- ray()->map_y) * ray()->delta_dist_y;
	}
	else
	{
		ray()->step_y = 1;
		ray()->side_dist_y = (ray()->map_y + 1.0 \
			- game()->pos_y) * ray()->delta_dist_y;
	}
}

void	calc_hit_wall(void)
{
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
		if (game()->map[ray()->map_x][ray()->map_y] == '1')
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
			{
				if (ray()->step_y == -1)
					ray()->draw_side = 2;
				else
					ray()->draw_side = 3;
			}
		}
	}
}

void	calc_perp_draw(void)
{
	if (ray()->side == 0)
		ray()->perp_wall_dist = (ray()->map_x - game()->pos_x \
			+ (1 - ray()->step_x) / 2) / ray()->dir_ray_x;
	else
		ray()->perp_wall_dist = (ray()->map_y - game()->pos_y \
			+ (1 - ray()->step_y) / 2) / ray()->dir_ray_y;
	ray()->line_height = (int)(HEIGHT / ray()->perp_wall_dist);
	ray()->draw_start = -ray()->line_height / 2 + HEIGHT / 2;
	if (ray()->draw_start < 0)
		ray()->draw_start = 0;
	ray()->draw_end = ray()->line_height / 2 + HEIGHT / 2;
	if (ray()->draw_end >= HEIGHT)
		ray()->draw_end = HEIGHT - 1;
	if (ray()->side == 0)
		ray()->wall_x = game()->pos_y + ray()->perp_wall_dist \
			* ray()->dir_ray_y;
	else
		ray()->wall_x = game()->pos_x + ray()->perp_wall_dist \
			* ray()->dir_ray_x;
	ray()->wall_x -= floor(ray()->wall_x);
}

void	define_wall_side(void)
{
	if (ray()->draw_side == 0 && game()->map[(int)ray()->map_x] \
		[ray()->map_y] == '1')
		game()->nbr_spr = 0;
	else if (ray()->draw_side == 1 && game()->map[(int)ray()->map_x] \
		[ray()->map_y] == '1')
		game()->nbr_spr = 1; 
	else if (ray()->draw_side == 2 && game()->map[(int)ray()->map_x] \
		[ray()->map_y] == '1')
		game()->nbr_spr = 2;
	else if (ray()->draw_side == 3 && game()->map[(int)ray()->map_x] \
		[ray()->map_y] == '1')
		game()->nbr_spr = 3;
}

void	get_color(int x, int y)
{
	ray()->tex_x = (int)(ray()->wall_x * game()->img[game()->nbr_spr].height);
	ray()->step = 1.0 * game()->img[game()->nbr_spr].width / ray()->line_height;
	ray()->tex_y = (ray()->draw_start - HEIGHT / 2 \
		+ ray()->line_height / 2) * ray()->step;
	while (y < HEIGHT)
	{
		if (y < ray()->draw_start)
			game()->color = game()->c_color;
		else if (y >= ray()->draw_start && y <= ray()->draw_end)
		{
			ray()->tex_y += ray()->step;
			game()->color = my_mlx_pixel_get(&game()->img[game()->nbr_spr], ray()->tex_x, ray()->tex_y);
		}
		else
			game()->color = game()->f_color;
		my_mlx_pixel_put(x, y, game()->color);
		y++;
	}
}

void	win_render(void)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		init_ray_var(x);
		calc_step_side();
		calc_hit_wall();
		calc_perp_draw();
		define_wall_side();
		y = 0;
		get_color(x, y);
		x++;
	}
}
