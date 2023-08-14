/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:42:10 by gateixei          #+#    #+#             */
/*   Updated: 2023/08/12 14:47:54 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

void	empty_file(void)
{
	errno = ENODATA;
	perror("Error\nEmpty file");
	exit(errno);
}

char	*get_full_file(int fd)
{
	char	*tmp;
	char	*file_buf;
	char	*new_file_buf;

	tmp = get_next_line(fd);
	if (tmp == NULL)
		empty_file();
	file_buf = NULL;
	while (tmp != NULL)
	{
		if (file_buf != NULL)
		{
			new_file_buf = ft_strjoin(file_buf, tmp);
			free(file_buf);
			file_buf = new_file_buf;
			free(tmp);
		}
		else
			file_buf = tmp;
		tmp = get_next_line(fd);
	}
	return (file_buf);
}

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nCould't open the file");
		exit(errno);
	}
	return (fd);
}

void	check_file_format(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '.')
		i++;
	if (str[i] != '\0' && !ft_strncmp(&str[i], ".cub", 5))
		return ;
	errno = EBFONT;
	perror("Error\nNot a .cub file");
	exit(errno);
}

t_element	is_valid_map(int argc, char **argv)
{
	int			fd;
	char		*file_buf;
	t_element	element;

	if (argc != 2 || argv[1] == NULL)
	{
		errno = EBFONT;
		perror("Error\nSend (only) the map path as argument");
		exit(errno);
	}
	check_file_format(argv[1]);
	fd = open_file(argv[1]);
	file_buf = get_full_file(fd);
	element = get_elements(file_buf, set_element());
	free(file_buf);
	if (errno > 0)
		exit(errno);
	check_map(element);
	return (element);
}
