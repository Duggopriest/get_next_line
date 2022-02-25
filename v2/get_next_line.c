#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*t;

	i = -1;
	t = malloc(ft_strlen(str) * sizeof(str));
	while (str[++i])
		t[i] = str[i];
	t[0] = 0;
	return (t);
}

void	inislize(char *buff_reminder, char *buff, char *line)
{
	buff_reminder = 0;
	buff = malloc(1);
	line = malloc(1000000);
	line[0] = 0;
}

char	*get_next_line(int fd)
{
	static char	*buff_reminder;
	char		*buff;
	char		*line;
	int			n;
	int			i;

	i = 0;
	n = 0;
	inislize(buff_reminder, buff, line);
	while ((n = read(fd, buff, 1)) && n > 0)
	{
		if ((n = read(fd, buff, 1)) && n > 0)
		line[i++] = buff[0];
		line[i] = '\0';
		if (buff[0] == '\n')
			return (ft_strdup(line));
	}
	if (!line[0])
		return (NULL);
	return(ft_strdup(line));
}
