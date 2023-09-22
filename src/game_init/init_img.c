/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:05:50 by dateixei          #+#    #+#             */
/*   Updated: 2023/09/22 16:32:46 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_img(void)
{
	game()->img[0].img = mlx_xpm_file_to_image(game()->mlx,
		game()->element.we, &game()->img[0].width, &game()->img[0].height);
	game()->img[1].img = mlx_xpm_file_to_image(game()->mlx,
		game()->element.ea, &game()->img[1].width, &game()->img[1].height);
	game()->img[2].img = mlx_xpm_file_to_image(game()->mlx,
		game()->element.no, &game()->img[2].width, &game()->img[2].height);
	game()->img[3].img = mlx_xpm_file_to_image(game()->mlx,
		game()->element.so, &game()->img[3].width, &game()->img[3].height);
	return (0);
}

int	start_sprite(void)
{
	int	i;
	int	j;

	i = 0;
	if (!(game()->sprite = (int **)malloc(NBR_SPRITES * sizeof(int *))))
		return (-1);
	while (i < NBR_SPRITES)
	{
		if (!(game()->sprite[i] = (int *)malloc((game()->img[i].width * game()->img[i].height) * sizeof(int))))
			return (-1);
		i++;
	}
	i = 0;
	while (i < NBR_SPRITES)
	{
		j = 0;
		while (j < (game()->img[i].height * game()->img[i].width))
		{
			game()->sprite[i][j] = 0;
			j++;
		}
		i++;
	}
	return (0);
}

int	load_sprite(t_img *img, int nbr)
{
	int	i;
	int	j;

	img->data = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->size_l, &img->endian);
	i = 0;
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
		{
			game()->sprite[nbr][img->width * i + j] = img->data[img->width * i + j];
			j++;
		}
		i++;
	}
	if (mlx_destroy_image(game()->mlx, img->img) == -1)
		return -1;
	return (0);
}
