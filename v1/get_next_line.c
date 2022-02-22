#include "get_next_line.h"

static char	ft_pop(char *chptr, char **line, char **str)
{
	char	*mem;

	*line = ft_substr(*str, 0, ft_strlen(*str) - ft_strlen(chptr));
	mem = *str;
	*str = ft_substr(*str, ft_strlen(*line, ft_strlen(*str) + 1, ft_strlen(*str)));
	ft_strdel(&mem);
	return (1);
}

static char ft_term(char **line, char **str)
{
	if (ft_strlen(*str) > 0)
	{
		*line = ft_strdup(*str);
		ft_strdel(*str);
		return (1);
	}
	return (0);
}


int				get_next_line(const int fd, char **line)
{
	ssize_t 	red;
	static char	*str;
	char		buff[BUFF_SIZE + 1];
	char		*mem;
	char		*chptr;

	if (fd < 0 || !line)
		return (ft_pop(chptr, line, &str));
	while ((red = read(fd, buff, BUFF_SIZE)) != -1)
	{
		buff[red] = '\0';
		if (red == 0)
			break ;
		mem = str;
		str = ft_strjoin(str, buff);
		ft_strdel(&mem);
		if ((chptr = ft_strchr(buff, '\n')))
			return (ft_pop(chptr, line, &str));
	}
	if (red == -1)
		return (-1);
	return (ft_term(line, &str));
}