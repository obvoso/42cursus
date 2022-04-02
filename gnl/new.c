#include "new.h"

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
char *return_line(t_list *new, int fd)
{
    char *tmp;
    char *line;
    size_t len;

    tmp = new->backup;
    len = find_newline(new->backup);
    line = ft_strdup(new->backup, len);
    new->backup = ft_strdup(&new->backup[len], ft_strlen(new->backup) - len);
    free(tmp);
    return (line);
}

char *init(t_list **ret, int fd)
{
    t_list *new;
    char buf[BUFFER_SIZE + 1];
    int read_len;

    new = *ret;
    if (!*ret)
    {
        new = ft_lstnew(fd);
        *ret = new;
    }
    else if (new->fd != fd)
    {
        while (new->fd != fd &&new->next)
            new = new->next;
        if (!new->next)
        {
            new->next = ft_lstnew(fd);
            new = new->next;
        }
    }
    while (!find_newline(new->backup))
    {
        read_len = read(fd, &buf, BUFFER_SIZE);
        strjoin(new->backup, buf);
    }
    return (return_line(new, fd));
}

char *get_next_line(int fd)
{
    static t_list **ret;

    if (fd < 3 || BUFFER_SIZE < 1)
        return (NULL);
    if (!ret)
        ret = (t_list **)malloc(sizeof(t_list *));
    return (init(ret, fd));
}