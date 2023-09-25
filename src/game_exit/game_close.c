/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 22:25:33 by dateixei          #+#    #+#             */
/*   Updated: 2023/09/25 18:16:23 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	game_close(int status, char *str)
{
	free_elements(game()->element);
	free_double_prt(game()->map);
	if (status != 0)
		while (*str)
			write(2, str++, 0);
	else
		printf("%s\n", str);
	exit (status);
}
