/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:21:23 by dateixei          #+#    #+#             */
/*   Updated: 2023/09/22 16:09:46 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	start_buffer()
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			game()->buffer[i][j] = 0;
			j++;
		}
		i++;
	}
	return (0);
}

int	init_var()
{
	int	i;

	game()->mlx = mlx_init();
	start_posi();
	init_img();
	game()->move_speed = 0.05;
	game()->rot_speed = 0.05;
	game()->buf = 0;
	start_buffer();
	if (start_sprite() == -1)
		return (-1);
	i = 0;
	while (i < NBR_SPRITES)
	{
		if (load_sprite(&game()->img[i], i) == -1)
			return (-1);
		i++;
	}
	return (0);
}
