#include "get_next_line.h"

static int	ft_check_line(char *check_line)
{
	int	i;

	i = 0;
	while (check_line[i] != '\0')
	{
		if (check_line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_read_file(int fd, char *check_line)
{
	
	read(fd, check_line, BUFFER_SIZE);
	if (ft_check_line(check_line) == 1)
		return ("\n");
	printf("%s", check_line);
	return (check_line);
}

char	*get_next_line(int fd)
{
	static char	*check_line;

	check_line = (char *)malloc(sizeof(char) * (BUFFER_SIZE));
	if (check_line == NULL)
		return (NULL);
	ft_read_file(fd, check_line);
}
