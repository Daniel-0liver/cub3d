/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:05:50 by dateixei          #+#    #+#             */
/*   Updated: 2023/09/25 18:48:37 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_img(void)
{
	load_sprite(game()->element.we, 0);
	load_sprite(game()->element.ea, 1);
	load_sprite(game()->element.no, 2);
	load_sprite(game()->element.so, 3);
	return (0);
}

int	load_sprite(char *file, int nbr)
{
	game()->img[nbr].img = mlx_xpm_file_to_image(game()->mlx,
		file, &game()->img[nbr].width, &game()->img[nbr].height);
	game()->img[nbr].data = mlx_get_data_addr(game()->img[nbr].img , \
		&game()->img[nbr].bits_per_pixel,
		&game()->img[nbr].size_l, &game()->img[nbr].endian);
	return (0);
}
