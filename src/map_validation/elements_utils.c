/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:29:21 by gateixei          #+#    #+#             */
/*   Updated: 2023/09/30 04:40:07 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

int	element_len(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0' && str[i] != '\n')
		i++;
	i--;
	while (str[i] != '\0' && (str[i] == ' ' \
	|| str[i] == '\t' || str[i] == '\v' \
	|| str[i] == '\r' || str[i] == '\f'))
		i--;
	return (i + 1);
}

int	map_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0' && str[i] != '\n' && str[i] != ' ')
		i++;
	return (i);
}

int	next_element(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0' && (str[i] == '\n' \
	|| str[i] == ' ' || str[i] == '\t' || str[i] == '\v' \
	|| str[i] == '\r' || str[i] == '\f'))
		i++;
	return (i);
}

int	check_type_id(char *str)
{
	if (!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "N ", 2) \
	|| !ft_strncmp(str, "SO ", 3) || !ft_strncmp(str, "S ", 2) \
	|| !ft_strncmp(str, "WE ", 3) || !ft_strncmp(str, "W ", 2) \
	|| !ft_strncmp(str, "EA ", 3) || !ft_strncmp(str, "E ", 2) \
	|| !ft_strncmp(str, "C ", 2) || !ft_strncmp(str, "F ", 2) \
	|| !ft_strncmp(str, "C ", 2))
		return (1);
	return (0);
}

int	check_null_elements(t_element elements)
{
	if (elements.no == NULL || elements.so == NULL || \
	elements.ea == NULL || elements.we == NULL || \
	elements.c == NULL || elements.f == NULL)
		return (1);
	return (0);
}
