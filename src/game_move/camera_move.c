/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 04:59:50 by dateixei          #+#    #+#             */
/*   Updated: 2023/10/01 15:01:24 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	camera_move_right(void)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = game()->dir_x;
	oldplane_x = game()->plane_x;
	game()->dir_x = game()->dir_x * cos(-game()->rot_speed) \
		- game()->dir_y * sin(-game()->rot_speed);
	game()->dir_y = olddir_x * sin(-game()->rot_speed) \
		+ game()->dir_y * cos(-game()->rot_speed);
	game()->plane_x = game()->plane_x * cos(-game()->rot_speed) \
		- game()->plane_y * sin(-game()->rot_speed);
	game()->plane_y = oldplane_x * sin(-game()->rot_speed) \
		+ game()->plane_y * cos(-game()->rot_speed);
	game()->rot_speed = 0.05;
}

void	camera_move_left(void)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = game()->dir_x;
	oldplane_x = game()->plane_x;
	game()->dir_x = game()->dir_x * cos(game()->rot_speed) \
		- game()->dir_y * sin(game()->rot_speed);
	game()->dir_y = olddir_x * sin(game()->rot_speed) \
		+ game()->dir_y * cos(game()->rot_speed);
	game()->plane_x = game()->plane_x * cos(game()->rot_speed) \
		- game()->plane_y * sin(game()->rot_speed);
	game()->plane_y = oldplane_x * sin(game()->rot_speed) \
		+ game()->plane_y * cos(game()->rot_speed);
	game()->rot_speed = 0.05;
}
