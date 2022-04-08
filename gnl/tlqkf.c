#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include "get_next_line.h"

void gnl(int fd, char const * expectedReturn)
{
	char *  gnlReturn = get_next_line(fd);
	if (expectedReturn == NULL)
		printf("NULL\n");
	else
		if(strcmp(gnlReturn, expectedReturn))
			printf("Error\n");
	free(gnlReturn);
}


int main()
{
	int fd;
	int i;
	// char *line;

	i = 0;
	while (i < 6)
	{
		fd = open("t1.txt", O_RDONLY);
		gnl(fd, "9876543210987654321098765432109876543210\n");
		gnl(fd, "01234567890123456789012345678901234567890\n");
		gnl(fd, "987654321098765432109876543210987654321098\n");
		gnl(fd, "01234567890123456789012345678901234567890\n");
		gnl(fd, "9876543210987654321098765432109876543210\n");
		gnl(fd, NULL);
		system("leaks a.out > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
		close(fd);
		i++;
	}
	while (1) {}
}
	// fd = open("t1.txt", O_RDONLY);
	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	printf("fin : %s\n", line);
	// 	free(line);

	// }
	// fd = open("t1.txt", O_RDONLY);
	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	printf("fin : %s\n", line);
	// 	free(line);

	// }
	// fd = open("t1.txt", O_RDONLY);
	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	printf("fin : %s\n", line);
	// 	free(line);

	// }
	// fd = open("t1.txt", O_RDONLY);
	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	printf("fin : %s\n", line);
	// 	free(line);
	// }
	// fd = open("t1.txt", O_RDONLY);
	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	printf("fin : %s\n", line);
	// 	free(line);
	// }
	// close(fd);
	// printf("끝\n");
//}