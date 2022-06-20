/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:45:28 by jgobbett          #+#    #+#             */
/*   Updated: 2022/03/03 18:52:49 by jgobbett         ###   ########.fr       */
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

char	*assignline(char **old_store)
{
	int		i;
	int		j;
	char	*return_line;
	char	*new_store;

	i = charfind(*old_store);
	if (i == 0)
		i = ft_strlen(*old_store);
	return_line = malloc(i + 1);
	return_line[i] = '\0';
	while (i-- > 0)
		return_line[i] = (*old_store)[i];
	new_store = NULL;
	i = ft_strlen(*old_store) - charfind(*old_store);
	if (i != ft_strlen(*old_store) && i > 0)
	{
		new_store = malloc(i + 1);
		new_store[i++] = '\0';
		j = ft_strlen(*old_store);
		while (i-- > 0)
			new_store[i] = (*old_store)[j--];
	}
	free(*old_store);
	*old_store = new_store;
	return (return_line);
}

char	*get_next_line(int fd)
{
	char			*buff;
	int				n;
	static char		*stored[4096];

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	while (!charfind(&stored[fd][0]))
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n == 0)
			break ;
		buff[n] = '\0';
		stored[fd] = ft_strjoin(stored[fd], buff);
	}
	free(buff);
	if (stored[fd])
		return (assignline(&stored[fd]));
	return (NULL);
}
