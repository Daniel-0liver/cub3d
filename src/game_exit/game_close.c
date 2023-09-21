/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 22:25:33 by dateixei          #+#    #+#             */
/*   Updated: 2023/09/20 19:53:38 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_close(int status, char *str)
{
	free_elements(game()->element);
	free_double_prt(game()->map);
	ft_free_array((void **)game()->sprite);
	printf("%s\n", str);
	exit (status);
}