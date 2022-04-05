#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd;
	char *line;

	fd = open("t1.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("fin : %s\n", line);
		free(line);
	}
	printf("끝\n");
}