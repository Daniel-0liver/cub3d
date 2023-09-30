/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:53:03 by dateixei          #+#    #+#             */
/*   Updated: 2023/09/30 13:56:07 by dateixei         ###   ########.fr       */
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

void	get_wall_side(void)
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
			get_wall_side();
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
