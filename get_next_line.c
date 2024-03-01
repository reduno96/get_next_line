
#include "get_next_line.h"

void	*ft_calloc(size_t size)
{
	size_t	i;
	char	*src;

	i = 0;
	src = malloc(size);
	if (src == NULL)
		return (0);
	while (i < size)
	{
		src[i] = '\0';
		i++;
	}
	return (src);
}

int	ft_check(char *line_check)
{
	int	i;

	i = 0;
	if (line_check == NULL || line_check[0] == '\0')
		return (0);
	while (line_check[i])
	{
		if (line_check[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_read_buffer(int fd, char *buf)
{
	int	result_read;

	if (buf == NULL)
		return (0);
	result_read = read(fd, buf, BUFFER_SIZE);
	// printf("'%s'", buf);
	if (result_read == -1)
	{
		free(buf);
		return (0);
	}
	return (result_read);
}
char	*ft_hold_line(char *hold_line)
{
	int		i;
	int		j;
	char	*final_line;

	i = 0;
	j = 0;
	if (hold_line == NULL)
		return (NULL);
	while (hold_line[i] && hold_line[i] != '\n')
		i++;
	final_line = ft_calloc(i + 2);
	i = 0;
	while (hold_line[i] && hold_line[i] != '\n')
		final_line[j++] = hold_line[i++];
	if (hold_line[i] == '\n')
		final_line[j++] = hold_line[i];
	final_line[j] = '\0';
	// free(hold_line);
	return (final_line);
}



char	*get_next_line(int fd)
{
	static char	*final_line;
	static char		*hold_line;
	char		*buf;
	char		*check_hold_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	hold_line = NULL;
	while (ft_check(hold_line) == 0)
	{
		buf = ft_calloc(BUFFER_SIZE + 1);
		if (ft_read_buffer(fd, buf) <= 0)
			break ;
		hold_line = ft_strjoin(hold_line, buf);
		free(buf);
	}
	
	check_hold_line = ft_hold_line(hold_line);
	// hold_line = new_line(hold_line);
	return (check_hold_line);
}
