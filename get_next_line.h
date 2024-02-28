# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 5

char	*get_next_line(int fd);
char     *ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);

int		main(void);
# endif