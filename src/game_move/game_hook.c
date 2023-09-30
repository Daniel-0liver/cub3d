/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:55:53 by dateixei          #+#    #+#             */
/*   Updated: 2023/09/30 05:05:08 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	main_loop(void)
{
	win_render();
	mlx_put_image_to_window(game()->mlx, game()->win, game()->mlx_img, 0, 0);
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
	main_loop();
	return (0);
}

void	get_hooks(void)
{
	mlx_loop_hook(game()->mlx, (void *) &main_loop, NULL);
	mlx_hook(game()->win, DestroyNotify, NoEventMask, (void *)&close_win, NULL);
	mlx_hook(game()->win, KeyPress, KeyPressMask, &key_hook, NULL);
}
