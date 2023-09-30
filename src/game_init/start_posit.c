/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_posit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:52:48 by dateixei          #+#    #+#             */
/*   Updated: 2023/09/30 04:42:58 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_pos(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'N' || str[i][j] == 'S' \
				|| str[i][j] == 'E' || str[i][j] == 'W')
			{
				game()->pos_x = i;
				game()->pos_y = j;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

int	start_w_e(void)
{
	if (game()->map[(int)game()->pos_x][(int)game()->pos_y] == 'W')
	{
		game()->dir_x = -1;
		game()->dir_y = 0;
		game()->plane_x = 0;
		game()->plane_y = 0.66;
	}
	if (game()->map[(int)game()->pos_x][(int)game()->pos_y] == 'E')
	{
		game()->dir_x = 1;
		game()->dir_y = 0;
		game()->plane_x = 0;
		game()->plane_y = -0.66;
	}
	return (0);
}

int	start_n_s(void)
{
	if (game()->map[(int)game()->pos_x][(int)game()->pos_y] == 'N')
	{
		game()->dir_x = 0;
		game()->dir_y = -1;
		game()->plane_x = -0.66;
		game()->plane_y = 0;
	}
	if (game()->map[(int)game()->pos_x][(int)game()->pos_y] == 'S')
	{
		game()->dir_x = 0;
		game()->dir_y = 1;
		game()->plane_x = 0.66;
		game()->plane_y = 0;
	}
	return (0);
}

int	start_posi(void)
{
	if (check_pos(game()->map) == -1)
		game_close(-1, "Error while founding the start position!");
	if (game()->map[(int)game()->pos_x][(int)game()->pos_y] == 'N'
		|| game()->map[(int)game()->pos_x][(int)game()->pos_y] == 'S')
		start_n_s();
	else if (game()->map[(int)game()->pos_x][(int)game()->pos_y] == 'W'
		|| game()->map[(int)game()->pos_x][(int)game()->pos_y] == 'E')
		start_w_e();
	return (0);
}
