/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:24:16 by gateixei          #+#    #+#             */
/*   Updated: 2023/09/29 21:42:25 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALIDATION_H

# define MAP_VALIDATION_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/include/libft.h"

# define TRUE 1
# define FALSE 0
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_element
{
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	char		*c;
	char		*f;
	char		*map;
}	t_element;

// is_valid_map ----------

void		empty_file(void);
char		*get_full_file(int fd);
int			open_file(char *file);
void		check_file_format(char *str);
t_element	is_valid_map(int argc, char **argv);

// get_next_line ----------

char		*my_strcat(char *s1, char *temp);
void		my_strcpy(char *str);
int			my_strlen(const char *str);
char		*add_char_to_str(char *line, char *buf);
char		*get_next_line(int fd);

// get_elements ----------

char		*dup_elements(char *str);
char		*dup_map(char *str);
t_element	get_element_dup(char *full_file, t_element element);
int			run_length(char *str);
t_element	get_elements(char *full_file, t_element element);

// elementos_utils ----------

int			element_len(char *str);
int			map_strlen(char *str);
int			next_element(char *str);
int			check_type_id(char *str);
t_element	set_element(void);
int			check_null_elements(t_element elements);

// exit_elements ----------

void		free_elements(t_element elements);
void		free_double_prt(char **str);
void		invalid_map(t_element element, char **split);
int			split_size(char **split);
int			ft_ptrlen(char **ptr);

// check_map ----------

char		**updted_split(char **split);
void		check_chars(char *str, t_element element);
void		check_border(char **split, t_element element);
void		check_limits(char **split, t_element element);
void		check_map(t_element element);

#endif