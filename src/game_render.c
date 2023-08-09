/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:55:33 by dateixei          #+#    #+#             */
/*   Updated: 2023/08/09 02:25:38 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	win_render(void)
{
	int x = 0;
	int y = 0;

	while (x < 400)
	{
		y = 0;
		while (y < 600)
		{
			if (y > (200 - game()->distance) && y < 400)
			{
				mlx_string_put(game()->mlx, game()->win.screen, x, y, 0xFFFFFFFF, "#");
				y++;
			}
			else
			{
				mlx_pixel_put(game()->mlx, game()->win.screen, x, y, 0xFF333333);
				y++;
			}
		} 
		x++;
	}
}

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