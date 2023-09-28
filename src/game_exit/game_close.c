/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 22:25:33 by dateixei          #+#    #+#             */
/*   Updated: 2023/09/28 16:37:32 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	game_close(int status, char *str)
{
	free_elements(game()->element);
	free_double_prt(game()->map);
	mlx_destroy_image(game()->mlx, game()->mlx_img);
	mlx_destroy_image(game()->mlx, game()->img[0].img);
	mlx_destroy_image(game()->mlx, game()->img[1].img);
	mlx_destroy_image(game()->mlx, game()->img[2].img);
	mlx_destroy_image(game()->mlx, game()->img[3].img);
	mlx_destroy_window(game()->mlx, game()->win);
	if (status != 0)
		while (*str)
			write(2, str++, 1);
	else
		printf("%s\n", str);
	exit (status);
}
