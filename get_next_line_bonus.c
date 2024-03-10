/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:30:09 by rel-mora          #+#    #+#             */
/*   Updated: 2024/03/10 16:30:11 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_hold_line(char *hold_line)
{
	int		i;
	int		j;
	char	*final_line;

	i = 0;
	j = 0;
	if (hold_line == NULL || hold_line[i] == '\0')
		return (NULL);
	while (hold_line[i] && hold_line[i] != '\n')
		i++;
	final_line = ft_calloc(i + 2);
	if (!final_line)
		return (free(final_line), NULL);
	i = 0;
	while (hold_line[i] && hold_line[i] != '\n')
		final_line[j++] = hold_line[i++];
	if (hold_line[i] == '\n')
		final_line[j++] = hold_line[i];
	final_line[j] = '\0';
	return (final_line);
}

char	*ft_rest_buf(char *hold_line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (hold_line[i] && hold_line[i] != '\n')
		i++;
	if (!hold_line[i])
		return (free(hold_line), NULL);
	str = ft_calloc((ft_strlen(hold_line) - i + 1));
	if (!str)
		return (free(str), NULL);
	i++;
	j = 0;
	while (hold_line[i])
		str[j++] = hold_line[i++];
	str[j] = '\0';
	free(hold_line);
	return (str);
}

int	ft_read(char *buf, int fd, int *result_read)
{
	*result_read = read(fd, buf, BUFFER_SIZE);
	if (*result_read == -1)
		return (free(buf), buf = NULL, 0);
	buf[*result_read] = '\0';
	return (*result_read);
}

char	*get_next_line(int fd)
{
	static char	*hold_line[1000];
	char		*buf;
	char		*check_hold_line;
	int			result_read;

	if (fd < 0)
		return (NULL);
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (free(hold_line[fd]), hold_line[fd] = NULL, NULL);
	result_read = 1;
	buf = ft_calloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (ft_check(hold_line[fd]) == 0 && result_read > 0)
	{
		result_read = ft_read(buf, fd, &result_read);
		hold_line[fd] = ft_strjoin(hold_line[fd], buf);
	}
	free(buf);
	check_hold_line = ft_hold_line(hold_line[fd]);
	hold_line[fd] = ft_rest_buf(hold_line[fd]);
	return (check_hold_line);
}
