/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 02:24:18 by dateixei          #+#    #+#             */
/*   Updated: 2023/08/14 02:32:52 by dateixei         ###   ########.fr       */
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

void	init_var()
{
	game()->mlx = mlx_init();
	game()->frame = 0;
	game()->win.width = 640;
	game()->win.height = 480;
	game()->dir_x = -1;
	game()->dir_y = 0;
	game()->pos_x = 6;
	game()->pos_y = 6;
	game()->plane_x = 0;
	game()->plane_y = 0.66;
	game()->move_speed = 0.1;
	game()->rot_speed = 0.05;
}

int main(int argc, char *argv[])
{
	t_element		element;

	element = is_valid_map(argc, argv);
	game()->map = updted_split(ft_split(element.map, '\n'));
	for (int i = 0; game()->map[i]; i++)
		printf("%s\n", game()->map[i]);
	init_var();
	game()->win.screen = mlx_new_window(game()->mlx, game()->win.width, game()->win.height, "Cub3D");
	get_hooks();
	mlx_loop(game()->mlx);
	free_elements(element);
	free_double_prt(game()->map);
	return (0);
}