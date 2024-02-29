#include "get_next_line.h"

char	*ft_check_line(char *check_line)
{
	int	i;

	i = 0;
	if (check_line == NULL)
		return (NULL);
	while (check_line[i] != '\0')
	{
		if (check_line[i] == 'j')
			return (check_line + i);
		i++;
	}
	return (check_line + i);
}
int	ft_read_line(int fd, char *buf)
{
	int	result_read;

	result_read = read(fd, buf, BUFFER_SIZE);
	if (result_read == -1)
	{
		free(buf);
		return (0);
	}
	return (result_read);
}
char	*ft_read_file(int fd, char *hold_line)
{
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	while (ft_check_line(hold_line) == NULL && ft_read_line >= 0)
	{
		ft_read_line(fd, buf);
		hold_line = ft_strjoin(hold_line, buf);
	}
	return (hold_line);
}

char	*get_next_line(int fd)
{
	static char	*hold_line;
	char		*new_line;

	hold_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	new_line = ft_check_line(ft_read_file(fd, hold_line));
	return (new_line);
}
