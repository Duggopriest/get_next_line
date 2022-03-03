/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:45:28 by jgobbett          #+#    #+#             */
/*   Updated: 2022/03/03 17:54:22 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	charfind(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (++i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str, char *str2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = malloc(ft_strlen(str) + ft_strlen(str2) + 1);
	if (str)
		while (str[j])
			new[i++] = str[j++];
	j = 0;
	if (str2)
		while (str2[j])
			new[i++] = str2[j++];
	new[i] = '\0';
	if (str)
		free(str);
	return (new);
}

char	*assignline(char **str)
{
	int		i;
	int		j;
	char	*line;
	char	*store;

	i = charfind(*str);
	if (i == 0)
		i = ft_strlen(*str);
	line = malloc(i);
	line[i] = '\0';
	while (i-- > 0)
		line[i] = (*str)[i];
	store = NULL;
	i = ft_strlen(*str) - charfind(*str);
	if (i != ft_strlen(*str))
	{
		store = malloc(i);
		store[i] = '\0';
		j = ft_strlen(*str);
		while (i-- > 0)
			store[i] = (*str)[j--];
	}
	free(*str);
	*str = store;
	return (line);
}

char	*get_next_line(int fd)
{
	char			*buff;
	int				n;
	static char		*stored = NULL;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	buff = (char *)malloc(BUFFER_SIZE);
	while (!charfind(stored))
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n == 0)
			break ;
		buff[n] = '\0';
		stored = ft_strjoin(stored, buff);
	}
	if (stored)
		if (stored[0])
			return (assignline(&stored));
	free(buff);
	return (NULL);
}
