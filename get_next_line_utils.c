/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgumusta <kgumusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:16:54 by kgumusta          #+#    #+#             */
/*   Updated: 2024/12/18 14:46:26 by kgumusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	tmp = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!tmp)
		return (NULL);
	while (s1[++i])
		tmp[i] = s1[i];
	while (s2[++j])
		tmp[i + j] = s2[j];
	tmp[i + j] = '\0';
	free(s1);
	return (tmp);
}
