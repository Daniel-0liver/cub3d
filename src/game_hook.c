/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:55:53 by dateixei          #+#    #+#             */
/*   Updated: 2023/09/28 19:45:14 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_win()
{
	game_close(0, "Thank you for playing.");
	return (0);
}

void	main_loop()
{
	win_render();
	mlx_put_image_to_window(game()->mlx, game()->win, game()->mlx_img, 0, 0);
}

int	key_hook(int keycode)
{
	if (keycode == 65307 || keycode == 113) //ESC and Q
		close_win();
	if (keycode == 65363) // ->
	{
		double olddir_x = game()->dir_x;
		game()->dir_x = game()->dir_x * cos(-game()->rot_speed) - game()->dir_y * sin(-game()->rot_speed);
		game()->dir_y = olddir_x * sin(-game()->rot_speed) + game()->dir_y * cos(-game()->rot_speed);
		double oldplane_x = game()->plane_x;
		game()->plane_x = game()->plane_x * cos(-game()->rot_speed) - game()->plane_y * sin(-game()->rot_speed);
		game()->plane_y = oldplane_x * sin(-game()->rot_speed) + game()->plane_y * cos(-game()->rot_speed);
	}
	if (keycode == 65361) // <-
	{
		double olddir_x = game()->dir_x;
		game()->dir_x = game()->dir_x * cos(game()->rot_speed) - game()->dir_y * sin(game()->rot_speed);
		game()->dir_y = olddir_x * sin(game()->rot_speed) + game()->dir_y * cos(game()->rot_speed);
		double oldplane_x = game()->plane_x;
		game()->plane_x = game()->plane_x * cos(game()->rot_speed) - game()->plane_y * sin(game()->rot_speed);
		game()->plane_y = oldplane_x * sin(game()->rot_speed) + game()->plane_y * cos(game()->rot_speed);
	}
	if (keycode == 119) // W and UP
	{
		game()->pos_x += game()->dir_x * game()->move_speed;
		game()->pos_y += game()->dir_y * game()->move_speed;
	}
	if (keycode == 115) // S and Down
	{
		game()->pos_x -= game()->dir_x * game()->move_speed;
		game()->pos_y -= game()->dir_y * game()->move_speed;
	}
	else if (keycode == 97) // A
	{
		game()->pos_x -= game()->plane_x * game()->move_speed;
		game()->pos_y -= game()->plane_y * game()->move_speed;
	}
	else if (keycode == 100) // D
	{
		game()->pos_x += game()->plane_x * game()->move_speed;
		game()->pos_y += game()->plane_y * game()->move_speed;
	}
	main_loop();
	return (0);
}

void	get_hooks(void)
{
	mlx_loop_hook(game()->mlx,(void *) &main_loop, NULL);
	mlx_hook(game()->win, DestroyNotify, NoEventMask, (void *)&close_win, NULL);
	mlx_hook(game()->win, KeyPress, KeyPressMask, &key_hook, NULL);
}
