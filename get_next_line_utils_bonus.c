/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <reduno96@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:20:24 by rel-mora          #+#    #+#             */
/*   Updated: 2024/03/09 13:01:19 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i++);
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

void	*ft_calloc(size_t size)
{
	size_t	i;
	char	*src;

	i = 0;
	src = malloc(size);
	if (src == NULL)
		return (free(src), src = NULL, NULL);
	while (i < size)
	{
		src[i] = '\0';
		i++;
	}
	return (src);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str_final;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s2 || !s1)
		return (NULL);
	str_final = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (str_final == NULL)
		return (NULL);
	while (s1[j])
		str_final[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str_final[i++] = s2[j++];
	str_final[i] = '\0';
	free(s1);
	return (str_final);
}