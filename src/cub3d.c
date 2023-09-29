/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 02:24:18 by dateixei          #+#    #+#             */
/*   Updated: 2023/09/29 22:17:24 by dateixei         ###   ########.fr       */
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

int main(int argc, char *argv[])
{
	game()->element = is_valid_map(argc, argv);
	printf("%s$", game()->element.so);
	game()->map = updted_split(ft_split(game()->element.map, '\n'));
	for (int i = 0; game()->map[i]; i++)
		printf("%s\n", game()->map[i]);
	if (init_var() == -1)
		game_close(-1, "Error while initializing variables.");
	get_hooks();
	mlx_loop(game()->mlx);
	return (0);
}