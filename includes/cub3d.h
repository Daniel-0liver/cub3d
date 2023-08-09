/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 01:52:49 by dateixei          #+#    #+#             */
/*   Updated: 2023/08/09 02:46:43 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/include/libft.h"
# include "../mlx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>

// int map[10][10] = {
// 	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
// 	{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1} };

typedef struct s_win
{
	void		*screen;
	int			width;
	int			height;
}			t_win;

typedef struct s_game
{
	void		*mlx;
	t_win		win;
	int			distance;
}			t_game;

//cub3d.c
t_game		*game(void);

//game_hook.c
void		get_hooks(void);

//game_render.c
void		win_render(void);

#endif