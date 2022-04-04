#include "new.h"
#include <stdio.h>

size_t find_newline(char *str)
{
	size_t size;

	size = 0;
	if (str)
	{
		while (str[size])
		{
			if (str[size] == '\n')
				return (size);
			++size;
		}
	}
	return (0);
}

char *return_line(t_list *new, size_t size)
{
	char *tmp;
	char *line;
	size_t len;

	len = find_newline(new->backup);
	if (!len && !size)
	{
		line = ft_strdup(new->backup, ft_strlen(new->backup));
		new->backup = NULL;
		return (line);
	}
	tmp = new->backup;
	line = ft_strdup(new->backup, len);
	new->backup = ft_strdup(&new->backup[len], ft_strlen(new->backup) - len);
	free(tmp);
	return (line);
}

char *init(t_list **ret, int fd)
{
	t_list *new;
	char  *tmp;
	char buf[BUFFER_SIZE + 1];
	size_t size;

	size = 1;
	new = *ret;
	if (!*ret)
	{
		new = ft_lstnew(fd);
		*ret = new;
	}
	else if (new->fd != fd)
	{
		while (new->fd != fd &&new->next)
		{
			new = new->next;
		}
		if (!new->next)
		{
			new->next = ft_lstnew(fd);
			new = new->next;
		}
	}
	while (!(find_newline(new->backup)))
	{
			if ((size = read(fd, &buf, BUFFER_SIZE)) > 0)
			{
				buf[size] = '\0';
				tmp = new->backup;
				new->backup = ft_strjoin(new->backup, buf);
				free(tmp);
			}
			else if (!size && new->backup == NULL)
				return (NULL);
			else if(!size)
				break;
	}
	return (return_line(new, size));
}

char *get_next_line(int fd)
{
	static t_list **ret;
	char    *line;

	if (fd < 3 || BUFFER_SIZE < 1)
		return (NULL);
	if (!ret)
		ret = (t_list **)malloc(sizeof(t_list *));
	line = init(ret, fd);
	if (line == NULL)
	{
	    free(ret);
	    return (NULL);
	}
	return (line);
}