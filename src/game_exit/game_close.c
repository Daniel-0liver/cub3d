/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 22:25:33 by dateixei          #+#    #+#             */
/*   Updated: 2023/10/01 15:56:20 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_close(int status, char *str)
{
	free_elements(game()->element);
	free_double_prt(game()->map);
	if (game()->img[0].img != NULL)
		mlx_destroy_image(game()->mlx, game()->img[0].img);
	if (game()->img[1].img)
		mlx_destroy_image(game()->mlx, game()->img[1].img);
	if (game()->img[2].img)
		mlx_destroy_image(game()->mlx, game()->img[2].img);
	if (game()->img[3].img)
		mlx_destroy_image(game()->mlx, game()->img[3].img);
	if (game()->mlx_img != NULL)
		mlx_destroy_image(game()->mlx, game()->mlx_img);
	if (game()->win != NULL)
		mlx_destroy_window(game()->mlx, game()->win);
	if (game()->mlx != NULL)
	{
		mlx_destroy_display(game()->mlx);
		free(game()->mlx);
	}
	if (status != 0)
		while (*str)
			write(2, str++, 1);
	else
		printf("%s\n", str);
	exit (status);
}

int	close_win(void)
{
	game_close(0, "Thank you for playing.");
	return (0);
}
