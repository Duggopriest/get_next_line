#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	charfind(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char *ft_strjoin(char *str, char *str2)
{
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = -1;
	new = malloc(ft_strlen(str) + ft_strlen(str2) + 1);
	while (str[++i])
		new[i] = str[i];
	while (str2[j] && str2[j] != '\n')
		new[i++] = str2[j++];
	free(str2);
	new[i] = '\0';
	return (new);
}

char	*get_next_line(int fd)
{
	char			*buff;
	char			*line;
	int				n;
	static char		**stored;
	
	n = 0;
	while (stored[++n])
		line = ft_strjoin(line, stored[n][0]);
	free(stored);
	buff = malloc(BUFF_SIZE + 1);
	while (read(fd, buff, 1))
	{
		line = ft_strjoin(line, buff);
		if (charfind(buff))
		{
			stored = ft_split(buff, '\n');
			break ;
		}
	}
	return(line);
}
