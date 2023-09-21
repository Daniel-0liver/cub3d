/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 02:24:18 by dateixei          #+#    #+#             */
/*   Updated: 2023/09/20 18:06:13 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	*game(void)
{
	static t_game	game;

	return (&game);
}

t_ray	*ray(void)
{
	static t_ray	ray;

	return (&ray);
}

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

int	start_sprite()
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
	while (i++ < NBR_SPRITES)
	{
		j = 0;
		while (j < (game()->img[i].height * game()->img[i].width))
		{
			game()->sprite[i][j] = 0;
			j++;
		}
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

int	init_var()
{
	int	i;

	game()->mlx = mlx_init();
	game()->dir_x = -1.0; 	//N = 0, S = 0, E = 1, W = -1
	game()->dir_y = 0.0;  	//N = -1, S = 1, E = 0, W = 0
	game()->plane_x = 0; 	//N = 0.66, S = -0.66, E = 0, W = 0
	game()->plane_y = 0.66; //N = 0, S = 0, E = 0.66, W = -0.66
	game()->pos_x = 6;
	game()->pos_y = 6;
	game()->move_speed = 0.05;
	game()->rot_speed = 0.05;
	game()->buf = 0;
	game()->img[0].img = mlx_xpm_file_to_image(game()->mlx, "images/blue_wall.xpm", &game()->img[0].width, &game()->img[0].height);
	game()->img[1].img = mlx_xpm_file_to_image(game()->mlx, "images/wall_34.xpm", &game()->img[1].width, &game()->img[1].height);
	game()->img[2].img = mlx_xpm_file_to_image(game()->mlx, "images/hd_wall.xpm", &game()->img[2].width, &game()->img[2].height);
	game()->img[3].img = mlx_xpm_file_to_image(game()->mlx, "images/brick_wall.xpm", &game()->img[3].width, &game()->img[3].height);
	game()->img[4].img = mlx_xpm_file_to_image(game()->mlx, "images/pillar.xpm", &game()->img[4].width, &game()->img[4].height);
	start_buffer();
	if (start_sprite() == -1)
		return (-1);
	i = 0;
	while (i < NBR_SPRITES)
	{
		if (load_sprite(&game()->img[i], i) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int main(int argc, char *argv[])
{
	game()->element = is_valid_map(argc, argv);
	game()->map = updted_split(ft_split(game()->element.map, '\n'));
	for (int i = 0; game()->map[i]; i++)
		printf("%s\n", game()->map[i]);
	if (init_var() == -1)
		game_close(-1, "Error while initializing variables.");
	game()->win = mlx_new_window(game()->mlx, WIDTH, HEIGHT, "Cub3D");
	game()->mlx_img = mlx_new_image(game()->mlx, WIDTH, HEIGHT);
	game()->mlx_data = (int *)mlx_get_data_addr(game()->mlx_img, &game()->bits_per_pixel, &game()->size_l, &game()->endian);
	get_hooks();
	mlx_loop(game()->mlx);
	game_close(0, "Thank you for playing.");
	return (0);
}