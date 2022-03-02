#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("test.txt", O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd1);
		if (!line)
			break ;
		printf("line [%02d]: %s\n", i, line);
		free(line);
		i++;
	}
	close(fd1);
	return (0);
}
