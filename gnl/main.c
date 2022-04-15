#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
int main()
{
    char *line;
 //   int attempt = 0;
    int fd = open("1mb1", O_RDONLY);
    while (1) {
        line = get_next_line(fd);
   //     printf("%d\n", attempt++);
        printf("%s", line);
        free(line);
        if (line == NULL)
            break;
    }
    close(fd);
    return 0;
}
