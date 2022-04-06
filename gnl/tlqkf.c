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
		system("leaks a.out > leaks_result_tmp; cat leaks_result_tmp | grep leaks && rm -rf leaks_result_tmp");

	}
	printf("끝\n");
}