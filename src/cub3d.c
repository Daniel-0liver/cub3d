/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 02:24:18 by dateixei          #+#    #+#             */
/*   Updated: 2023/09/05 10:39:19 by dateixei         ###   ########.fr       */
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

	i = 0;
	if (!(game()->sprite = (int **)malloc(1 * sizeof(int *))))
		return (-1);
	if (!(game()->sprite[0] = (int *)malloc((game()->img.width * game()->img.height) * sizeof(int))))
		return (-1);
	while (i < (game()->img.height * game()->img.width))
	{
		game()->sprite[0][i] = 0;
		i++;
	}
	return (0);
}

int	load_sprite()
{
	int	i;
	int	j;

	game()->img.data = (int *)mlx_get_data_addr(game()->img.img, &game()->img.bits_per_pixel, &game()->img.size_l, &game()->img.endian);
	i = 0;
	while (i < game()->img.height)
	{
		j = 0;
		while (j < game()->img.width)
		{
			game()->sprite[0][game()->img.width * i + j] = game()->img.data[game()->img.width * i + j];
			j++;
		}
		i++;
	}
	mlx_destroy_image(game()->mlx, game()->img.img);
	return (0);
}

int	init_var()
{
	game()->mlx = mlx_init();
	game()->frame = 0;
	game()->dir_x = -1.0;
	game()->dir_y = 0.0;
	game()->pos_x = 6;
	game()->pos_y = 6;
	game()->plane_x = 0;
	game()->plane_y = 0.66;
	game()->move_speed = 0.05;
	game()->rot_speed = 0.05;
	game()->buf = 0;
	game()->img.img = mlx_xpm_file_to_image(game()->mlx, "images/wall_34.xpm", &game()->img.width, &game()->img.height);
	start_buffer();
	if (start_sprite() == -1)
		return (-1);
	if (load_sprite() == -1)
		return (-1);
	return (0);
}

int main(int argc, char *argv[])
{
	t_element		element;
	
	element = is_valid_map(argc, argv);
	game()->map = updted_split(ft_split(element.map, '\n'));
	for (int i = 0; game()->map[i]; i++)
		printf("%s\n", game()->map[i]);
	init_var();
	game()->win = mlx_new_window(game()->mlx, WIDTH, HEIGHT, "Cub3D");
	game()->mlx_img = mlx_new_image(game()->mlx, WIDTH, HEIGHT);
	game()->mlx_data = (int *)mlx_get_data_addr(game()->mlx_img, &game()->bits_per_pixel, &game()->size_l, &game()->endian);
	get_hooks();
	mlx_loop(game()->mlx);
	free_elements(element);
	free_double_prt(game()->map);
	return (0);
}