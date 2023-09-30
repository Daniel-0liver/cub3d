/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:55:33 by dateixei          #+#    #+#             */
/*   Updated: 2023/09/30 13:56:18 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
			(game()->color) = my_mlx_pixel_get(&game()->img[game()->nbr_spr], \
				ray()->tex_x, ray()->tex_y);
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
