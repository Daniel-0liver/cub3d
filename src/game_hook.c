/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:55:53 by dateixei          #+#    #+#             */
/*   Updated: 2023/08/08 03:23:24 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_win()
{
	mlx_destroy_window(game()->mlx, game()->win.screen);
	return (0);
}

int	key_hook(int keycode)
{
	if (keycode == 65307 || keycode == 113)
		close_win();
	if (keycode == 119 || keycode == 65362)
		game()->distance += 2;
	if (keycode == 115 || keycode == 65364)
		game()->distance -= 2;
	return (0);
}

void	get_hooks(void)
{
	mlx_hook(game()->win.screen, DestroyNotify, NoEventMask, (void *)&close_win, NULL);
	mlx_hook(game()->win.screen, KeyPress, KeyPressMask, &key_hook, NULL);
	mlx_loop_hook(game()->mlx,(void *) &win_render, NULL);
}
