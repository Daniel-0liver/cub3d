/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:21:23 by dateixei          #+#    #+#             */
/*   Updated: 2023/09/28 12:10:27 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_var()
{
	game()->mlx = mlx_init();
	start_posi();
	init_img();
	game()->move_speed = 0.05;
	game()->rot_speed = 0.05;
	game()->color = 0;
	return (0);
}
