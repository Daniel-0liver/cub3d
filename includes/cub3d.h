/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 01:52:49 by dateixei          #+#    #+#             */
/*   Updated: 2023/08/12 15:01:41 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "map_validation.h"
# include "../libft/include/libft.h"
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



typedef struct s_win
{
	void		*screen;
	int			width;
	int			height;
}			t_win;

typedef struct s_ray
{
	int			hit;
	int			side;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			draw_end;
	int			draw_start;
	int			line_height;
	double		camera_x;
	double		dir_ray_x;
	double		dir_ray_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
}			t_ray;


typedef struct s_game
{
	void		*mlx;
	t_win		win;
	int			color;
	int			frame;
	char		**map;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;
}			t_game;

//cub3d.c
t_game		*game(void);
t_ray		*ray(void);

//game_hook.c
void		get_hooks(void);

//game_render.c
void		win_render(void);

#endif