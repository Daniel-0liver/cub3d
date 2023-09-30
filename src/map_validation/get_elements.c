/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:25:15 by gateixei          #+#    #+#             */
/*   Updated: 2023/09/30 05:10:27 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

char	*dup_elements(char *str)
{
	int		i;
	int		j;
	int		size;
	char	*element;

	j = 0;
	i = map_strlen(str);
	i += next_element(&str[i]);
	size = element_len(&str[i]);
	element = malloc(sizeof(char) * (size + 1));
	while (size-- > 0)
		element[j++] = str[i++];
	element[j] = '\0';
	return (element);
}

char	*dup_map(char *str)
{
	int		i;
	int		size;
	char	*map;

	i = 0;
	size = 0;
	while (str && str[i] != '\n' && str[i] != '\0')
		str++;
	while (str && str[i] == '\n')
		str++;
	while (str && str[size] != '\0')
		size++;
	map = malloc(sizeof(char) * (size + 1));
	while (size-- > 0)
	{
		map[i] = str[i];
		i++;
	}
	map[i] = '\0';
	return (map);
}

t_element	get_element_dup(char *full_file, t_element element)
{
	if (full_file[0] == 'N' && element.no == NULL)
		element.no = dup_elements(full_file);
	else if (full_file[0] == 'S' && element.so == NULL)
		element.so = dup_elements(full_file);
	else if (full_file[0] == 'E' && element.ea == NULL)
		element.ea = dup_elements(full_file);
	else if (full_file[0] == 'W' && element.we == NULL)
		element.we = dup_elements(full_file);
	else if (full_file[0] == 'C' && element.c == NULL)
		element.c = dup_elements(full_file);
	else if (full_file[0] == 'F' && element.f == NULL)
		element.f = dup_elements(full_file);
	return (element);
}

int	run_length(char *str)
{
	int	i;

	i = map_strlen(str);
	i += next_element(&str[i]);
	i += map_strlen(&str[i]);
	return (i);
}

t_element	get_elements(char *full_file, t_element element)
{
	int			i;
	int			c;

	i = 0;
	c = 0;
	while (full_file && full_file[i] != '\0' && errno == 0 && c++ < 7)
	{
		if (check_null_elements(element))
			i += next_element(&full_file[i]);
		if (check_type_id(&full_file[i]))
		{
			element = get_element_dup(&full_file[i], element);
			i += run_length(&full_file[i]);
		}
		else if (!check_null_elements(element))
		{
			element.map = dup_map(&full_file[i]);
			return (element);
		}
	}
	errno = EINVAL;
	perror("Error\nCheck map file rules");
	free_elements(element);
	return (element);
}
