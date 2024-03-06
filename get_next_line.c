
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
	return (final_line);
}

char	*new_line(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
		return (free(line), NULL);
	str = ft_calloc((ft_strlen(line) - i + 1));
	if (!str)
		return (free(str), NULL);
	i++;
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free(line);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*hold_line;
	char		*buf;
	char		*check_hold_line;
	int			result_read;

	result_read = 1;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	while (ft_check(hold_line) == 0 && result_read > 0)
	{
		printf("%d", result_read);

		buf = ft_calloc(BUFFER_SIZE + 1);
		result_read = read(fd, buf, BUFFER_SIZE);
		if (result_read < 0)
			return (free(buf), buf = NULL, NULL);

		hold_line = ft_strjoin(hold_line, buf);
		free(buf);
	}
	check_hold_line = ft_hold_line(hold_line);
	hold_line = new_line(hold_line);
	return (check_hold_line);
}
