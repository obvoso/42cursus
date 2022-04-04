#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.c"

int main()
{
	int fd;
	char *line;

	fd = open("testscript.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("fin : %s\n", line);
		free (line);
	}
	printf("끝\n");
}