/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:55:53 by dateixei          #+#    #+#             */
/*   Updated: 2023/10/01 17:04:52 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_mouse(void)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(game()->mlx, game()->win, &x, &y);
	if (x < (WIDTH / 2))
	{
		game()->rot_speed = 0.001;
		game()->rot_speed = game()->rot_speed * -(x - (WIDTH / 2));
		camera_move_left();
	}
	else if (x > (WIDTH / 2))
	{
		game()->rot_speed = 0.001;
		game()->rot_speed = game()->rot_speed * (x - (WIDTH / 2));
		camera_move_right();
	}
	mlx_mouse_move(game()->mlx, game()->win, (WIDTH / 2), (HEIGHT / 2));
}

void	main_loop(void)
{
	win_render();
	mlx_put_image_to_window(game()->mlx, game()->win, game()->mlx_img, 0, 0);
	if (game()->flag == 1)
		move_mouse();
}

int	key_hook(int keycode)
{
	if (keycode == 65307 || keycode == 113)
		close_win();
	else if (keycode == 65363)
		camera_move_right();
	else if (keycode == 65361)
		camera_move_left();
	else if (keycode == 119)
		move_foward();
	else if (keycode == 115)
		move_backward();
	else if (keycode == 97)
		move_left();
	else if (keycode == 100)
		move_right();
	else if (keycode == 65505)
	{
		if (game()->flag == 0)
			game()->flag = 1;
		else
			game()->flag = 0;
	}
	main_loop();
	return (0);
}

void	get_hooks(void)
{
	mlx_loop_hook(game()->mlx, (void *) &main_loop, NULL);
	mlx_hook(game()->win, DestroyNotify, NoEventMask, (void *)&close_win, NULL);
	mlx_hook(game()->win, KeyPress, KeyPressMask, &key_hook, NULL);
}
