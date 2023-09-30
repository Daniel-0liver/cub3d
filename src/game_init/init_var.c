/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:21:23 by dateixei          #+#    #+#             */
/*   Updated: 2023/09/30 14:02:58 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_atoi_rgb(const char *nptr)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (nptr[i] && (nptr[i] == '\f' || nptr[i] == ' ' || nptr[i] == '\n'
			|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v'))
		i++;
	if (nptr[i] && (nptr[i] == '-' || nptr[i] == '+'))
		if (nptr[i++] == '-')
			return (-1);
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	while (nptr[i] && (nptr[i] == ' ' || nptr[i] == '\t' \
		|| nptr[i] == '\v' || nptr[i] == 'r'))
		i++;
	if (nptr[i] != 0 || result > 255 || result < 0)
		return (-1);
	return (result);
}

int	get_rgb_color(char	*file)
{
	int		r;
	int		g;
	int		b;
	int		i;
	char	**rgb;

	rgb = ft_split(file, ',');
	i = 0;
	while (rgb[i])
		i++;
	r = ft_atoi_rgb(rgb[0]);
	g = ft_atoi_rgb(rgb[1]);
	b = ft_atoi_rgb(rgb[2]);
	free_double_prt(rgb);
	if (i != 3 || file[0] == ',' || r == -1 || g == -1 || b == -1)
		game_close(-1, "Error while picking color");
	return ((r << 16) | (g << 8) | b);
}

int	init_var(void)
{
	(game()->mlx) = mlx_init();
	(game()->mlx_img) = mlx_new_image(game()->mlx, WIDTH, HEIGHT);
	(game()->mlx_data) = mlx_get_data_addr(game()->mlx_img, \
		&game()->bits_per_pixel, &game()->size_l, &game()->endian);
	start_posi();
	init_img();
	(game()->win) = mlx_new_window(game()->mlx, WIDTH, HEIGHT, "Cub3D");
	game()->c_color = get_rgb_color(game()->element.c);
	game()->f_color = get_rgb_color(game()->element.f);
	game()->move_speed = 0.05;
	game()->rot_speed = 0.05;
	game()->color = 0;
	return (0);
}
