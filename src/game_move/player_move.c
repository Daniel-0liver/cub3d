/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 04:44:03 by dateixei          #+#    #+#             */
/*   Updated: 2023/09/30 04:58:40 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_foward(void)
{
	if (game()->map[(int)(game()->pos_x + (game()->dir_x \
		* game()->move_speed))][(int)(game()->pos_y)] != '1')
		game()->pos_x += game()->dir_x * game()->move_speed;
	if (game()->map[(int)(game()->pos_x)][(int)(game()->pos_y \
		+ (game()->dir_y * game()->move_speed))] != '1')
		game()->pos_y += game()->dir_y * game()->move_speed;
}

void	move_backward(void)
{
	if (game()->map[(int)(game()->pos_x - (game()->dir_x \
		* game()->move_speed))] \
		[(int)(game()->pos_y)] != '1')
		game()->pos_x -= game()->dir_x * game()->move_speed;
	if (game()->map[(int)(game()->pos_x)] \
		[(int)(game()->pos_y \
		- (game()->dir_y * game()->move_speed))] != '1')
		game()->pos_y -= game()->dir_y * game()->move_speed;
}

void	move_right(void)
{
	if (game()->map[(int)(game()->pos_x + (game()->plane_x \
		* game()->move_speed))][(int)game()->pos_y] != '1')
		game()->pos_x += game()->plane_x * game()->move_speed;
	if (game()->map[(int)(game()->pos_x)][(int)(game()->pos_y \
		+ (game()->plane_y * game()->move_speed))] != '1')
		game()->pos_y += game()->plane_y * game()->move_speed;
}

void	move_left(void)
{
	if (game()->map[(int)(game()->pos_x - (game()->plane_x \
		* game()->move_speed))][(int)(game()->pos_y)] != '1')
		game()->pos_x -= game()->plane_x * game()->move_speed;
	if (game()->map[(int)(game()->pos_x)][(int)(game()->pos_y \
		- (game()->plane_y * game()->move_speed))] != '1')
		game()->pos_y -= game()->plane_y * game()->move_speed;
}
