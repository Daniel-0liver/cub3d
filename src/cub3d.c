/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 02:24:18 by dateixei          #+#    #+#             */
/*   Updated: 2023/10/01 14:29:03 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	(game()->element) = is_valid_map(argc, argv);
	(game()->map) = updted_split(ft_split(game()->element.map, '\n'));
	if (init_var() == -1)
		game_close(-1, "Error while initializing variables.");
	get_hooks();
	mlx_loop(game()->mlx);
	return (0);
}
