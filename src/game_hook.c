/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:55:53 by dateixei          #+#    #+#             */
/*   Updated: 2023/09/10 23:27:24 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_win()
{
	mlx_destroy_window(game()->mlx, game()->win);
	return (0);
}

void	main_loop()
{
	win_render();
	draw();
}

int	key_hook(int keycode)
{
	if (keycode == 65307 || keycode == 113) //ESC and Q
		close_win();
	if (keycode == 100 || keycode == 65363) // D and ->
	{
		double olddir_x = game()->dir_x;
		game()->dir_x = game()->dir_x * cos(-game()->rot_speed) - game()->dir_y * sin(-game()->rot_speed);
		game()->dir_y = olddir_x * sin(-game()->rot_speed) + game()->dir_y * cos(-game()->rot_speed);
		double oldplane_x = game()->plane_x;
		game()->plane_x = game()->plane_x * cos(-game()->rot_speed) - game()->plane_y * sin(-game()->rot_speed);
		game()->plane_y = oldplane_x * sin(-game()->rot_speed) + game()->plane_y * cos(-game()->rot_speed);
	}
	if (keycode == 97 || keycode == 65361) // A and <-
	{
		double olddir_x = game()->dir_x;
		game()->dir_x = game()->dir_x * cos(game()->rot_speed) - game()->dir_y * sin(game()->rot_speed);
		game()->dir_y = olddir_x * sin(game()->rot_speed) + game()->dir_y * cos(game()->rot_speed);
		double oldplane_x = game()->plane_x;
		game()->plane_x = game()->plane_x * cos(game()->rot_speed) - game()->plane_y * sin(game()->rot_speed);
		game()->plane_y = oldplane_x * sin(game()->rot_speed) + game()->plane_y * cos(game()->rot_speed);
	}
	if (keycode == 119 || keycode == 65362) // W and UP
	{
		game()->pos_x += game()->dir_x * game()->move_speed;
		game()->pos_y += game()->dir_y * game()->move_speed;
	}
	if (keycode == 115 || keycode == 65364) // S and Down
	{
		game()->pos_x -= game()->dir_x * game()->move_speed;
		game()->pos_y -= game()->dir_y * game()->move_speed;
	}
	mlx_clear_window(game()->mlx, game()->win);
	main_loop();
	return (0);
}

void	get_hooks(void)
{
	mlx_loop_hook(game()->mlx,(void *) &main_loop, NULL);
	mlx_hook(game()->win, DestroyNotify, NoEventMask, (void *)&close_win, NULL);
	mlx_hook(game()->win, KeyPress, KeyPressMask, &key_hook, NULL);
}
