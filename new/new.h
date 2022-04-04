
#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

typedef struct s_list
{
	int fd;
	char *backup;
	struct s_list *next;
} t_list;

char *get_next_line(int fd);
char *ft_strjoin(char *s1, char *s2);
char *ft_strchr(const char *s, int c);
size_t ft_strlen(const char *s);
char *ft_strdup(char *s1, size_t size);
t_list *ft_lstnew(int fd);

#endif