/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgumusta <kgumusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:10:22 by mkayaalp          #+#    #+#             */
/*   Updated: 2024/12/13 19:26:35 by kgumusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*read_func(char *str, int fd)
{
	int		byte_readed;
	char	*buffer;

	byte_readed = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(str, '\n') && byte_readed != 0)
	{
		byte_readed = read(fd, buffer, BUFFER_SIZE);
		if (byte_readed == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_readed] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_after_line(char *str)
{
	int		j;
	int		i;
	char	*tmp;

	j = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	tmp = malloc(ft_strlen(str) - i + 1);
	if (!tmp)
		return (NULL);
	i++;
	while (str[i] != '\0')
		tmp[j++] = str[i++];
	tmp[j] = '\0';
	free(str);
	return (tmp);
}

char	*get_line(char *str)
{
	char	*temp;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		temp = malloc(i + 2);
	else
		temp = malloc(i + 1);
	if (!temp)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		temp[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		temp[i++] = '\n';
	temp[i] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		free(str);
		str = NULL;
		return (0);
	}
	str = read_func(str, fd);
	if (!str)
		return (NULL);
	line = get_line(str);
	str = get_after_line(str);
	return (line);
}
