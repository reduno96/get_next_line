#include "get_next_line.h"

int	main(void)
{
	int fd;


	fd = open("text.txt", O_RDWR );
	printf("%s",get_next_line(fd));
	close(fd);
	return (0);
}