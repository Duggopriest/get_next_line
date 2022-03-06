#include "get_next_line.h"

int	main(void)
{
	char	*line;
	char	*line2;
	int		i;
	int		fd1;
	int		fd2;

	fd1 = open("test.txt", O_RDONLY);
	i = 0;
	fd2 = open("test2.txt", O_RDONLY);
	printf("\n\nstarting\n\n");
	while (1)
	{
		line = get_next_line(fd1);
		if (line)
		{	
			printf("line [%02d]: %s\n", i, line);
		}
		line2 = get_next_line(fd2);
		if (line2)
		{
			printf("line [%02d]: %s\n", i, line2);
		}
		if (!line && !line2)
			break ;
		free(line);
		free(line2);
		i++;
	}
	close(fd1);
	return (0);
}
