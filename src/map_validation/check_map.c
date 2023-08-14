/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:57:21 by gateixei          #+#    #+#             */
/*   Updated: 2023/08/12 14:47:33 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

char	**updted_split(char **split)
{
	int		i;
	int		c;
	int		size;
	char	**new_split;

	i = 0;
	size = split_size(split);
	if (size == -1)
		return (NULL);
	new_split = malloc(sizeof(char *) * (ft_ptrlen(split) + 1));
	while (split && split[i] != NULL)
	{
		c = -1;
		new_split[i] = malloc(sizeof(char) * (size + 1));
		while (split[i][++c] != '\0')
			new_split[i][c] = split[i][c];
		while (c < size)
			new_split[i][c++] = ' ';
		new_split[i][c] = '\0';
		i++;
	}
	new_split[i] = NULL;
	free_double_prt(split);
	return (new_split);
}

void	check_chars(char *str, t_element element)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '1' && str[i] != '0' && str[i] != '\n')
		{
			if ((str[i] == 'N' || str[i] == 'S' || str[i] == 'E' \
			|| str[i] == 'W') && flag == 0)
				flag = 1;
			else
				invalid_map(element, NULL);
		}
		i++;
	}
	if (flag != 1)
		invalid_map(element, NULL);
}

void	check_border(char **split, t_element element)
{
	int	i;
	int	j;

	i = 0;
	while (split && split[i] != NULL)
	{
		j = 0;
		while (split[i][j] != '\0')
		{
			if (i == 0 || split[i + 1] == NULL)
			{
				if (split[i][j] == '0')
					invalid_map(element, split);
			}
			else if (j == 0 && split[i][j] == '0')
				invalid_map(element, split);
			else if (split[i][j + 1] == '\0' && split[i][j] == '0')
				invalid_map(element, split);
			j++;
		}
		i++;
	}
}

void	check_limits(char **split, t_element element)
{
	int	i;
	int	j;

	i = 1;
	while (split && split[i] != NULL && split[i + 1] != NULL)
	{
		j = 1;
		while (split[i][j] != '\0' && split[i][j + 1] != '\0')
		{
			if ((split[i][j] != '1' && split[i][j] != ' ') && \
			(split[i - 1][j] == ' ' || split[i + 1][j] == ' ' \
			|| split[i][j - 1] == ' ' || split[i][j + 1] == ' '))
				invalid_map(element, split);
			j++;
		}
		i++;
	}
}

void	check_map(t_element element)
{
	char	**split;

	check_chars(element.map, element);
	split = updted_split(ft_split(element.map, '\n'));
	if (split == NULL)
		invalid_map(element, split);
	check_border(split, element);
	check_limits(split, element);
	free_double_prt(split);
}
