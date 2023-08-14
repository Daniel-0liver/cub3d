/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:09:34 by gateixei          #+#    #+#             */
/*   Updated: 2023/08/12 14:47:50 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

char	*my_strcat(char *s1, char *temp)
{
	char	*cat;
	int		c;

	c = 0;
	cat = (char *)malloc((my_strlen(s1) + 2) * sizeof(char));
	if (!cat)
		return (0);
	while (s1 && s1[c] != '\0')
	{
		cat[c] = s1[c];
		c++;
	}
	cat[c++] = temp[0];
	cat[c] = '\0';
	free(s1);
	return (cat);
}

void	my_strcpy(char *str)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = &str[1];
	while (str[i] != '\0' && ptr[i] != '\0' && str)
	{
		str[i] = ptr[i];
		i++;
	}
	str[i] = '\0';
}

int	my_strlen(const char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	else
	{
		while (str[len] != '\0')
			len++;
	}
	return (len);
}

char	*add_char_to_str(char *line, char *buf)
{
	line = my_strcat(line, buf);
	my_strcpy(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (TRUE)
	{
		if (buf[0] != '\0' && buf[0] != '\n')
			line = add_char_to_str(line, buf);
		else if (buf[0] == '\n')
			return (add_char_to_str(line, buf));
		else if (!read(fd, buf, BUFFER_SIZE))
			return (line);
	}
}
