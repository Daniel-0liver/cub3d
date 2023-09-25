/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:21:23 by dateixei          #+#    #+#             */
/*   Updated: 2023/09/25 18:16:32 by dateixei         ###   ########.fr       */
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
	game()->mlx = mlx_init();
	start_posi();
	init_img();
	game()->move_speed = 0.05;
	game()->rot_speed = 0.05;
	game()->buf = 0;
	start_buffer();
	return (0);
}
