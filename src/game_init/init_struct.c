/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 04:40:48 by dateixei          #+#    #+#             */
/*   Updated: 2023/09/30 04:42:09 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_element	set_element(void)
{
	t_element	elements;

	elements.no = NULL;
	elements.so = NULL;
	elements.ea = NULL;
	elements.we = NULL;
	elements.c = NULL;
	elements.f = NULL;
	elements.map = NULL;
	return (elements);
}

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
