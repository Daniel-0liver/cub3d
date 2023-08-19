/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:49:07 by gateixei          #+#    #+#             */
/*   Updated: 2023/08/12 14:47:42 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

void	free_elements(t_element elements)
{
	if (elements.no != NULL)
		free(elements.no);
	if (elements.so != NULL)
		free(elements.so);
	if (elements.ea != NULL)
		free(elements.ea);
	if (elements.we != NULL)
		free(elements.we);
	if (elements.c != NULL)
		free(elements.c);
	if (elements.f != NULL)
		free(elements.f);
	if (elements.map != NULL)
		free(elements.map);
	elements.no = NULL;
	elements.so = NULL;
	elements.ea = NULL;
	elements.we = NULL;
	elements.c = NULL;
	elements.f = NULL;
	elements.map = NULL;
}

void	free_double_prt(char **str)
{
	int	i;

	i = 0;
	while (str && str[i] != NULL)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	if (str != NULL)
		free(str);
	str = NULL;
}

void	invalid_map(t_element element, char **split)
{
	errno = EINVAL;
	perror("Error\nInvalid Map");
	free_elements(element);
	free_double_prt(split);
	exit(errno);
}

int	split_size(char **split)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (split && split[i] != NULL)
	{
		if ((int)ft_strlen(split[i]) > size)
			size = ft_strlen(split[i]);
		i++;
	}
	if (i < 3 || size < 3)
	{
		free_double_prt(split);
		return (-1);
	}
	return (size);
}

int	ft_ptrlen(char **ptr)
{
	int	i;

	i = 0;
	while (ptr && ptr[i] != NULL)
		i++;
	return (i);
}
