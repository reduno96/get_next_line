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

static char	*ft_read_file(int fd, char *hold_line)
{
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE));
	if (buf == NULL)
		return (NULL);
	read(fd, buf, BUFFER_SIZE);
	if (ft_check_line(buf) == 1)
	{
		hold_line = ft_strjoin(hold_line, buf);
		return (hold_line);
	}
	return (hold_line);
}

char	*get_next_line(int fd)
{
	static char	*hold_line;

	hold_line = NULL;
	return (ft_read_file(fd, hold_line));
}
