/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 22:25:33 by dateixei          #+#    #+#             */
/*   Updated: 2023/09/22 16:36:39 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void free_sprites() {
    int i;

	i = 0;
    if (game() && game()->sprite) 
	{
        while (i < NBR_SPRITES) 
		{
            if (game()->sprite[i]) 
			{
                free(game()->sprite[i]);
                game()->sprite[i] = NULL;
            }
			i++;
        }
        free(game()->sprite);
        game()->sprite = NULL;
    }
}


void	game_close(int status, char *str)
{
	free_elements(game()->element);
	free_double_prt(game()->map);
	free_sprites();
	if (status != 0)
		while (*str)
			write(2, str++, 0);
	else
		printf("%s\n", str);
	exit (status);
}
