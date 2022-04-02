#include "new.h"

size_t ft_strlen(const char *s)
{
    size_t len;

    // printf("ft_strlen:%s\n", s);
    len = 0;
    if (s)
        while (s[len])
            ++len;
    return (len);
}
char *ft_strjoin(char *s1, char *s2)
{
    char *ret;
    size_t i;

    ret = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    printf("s1 :%s\ns2 :%s", s1, s2);
    if (!ret)
        return (NULL);
    i = 0;
    if (s1)
    {
        if (*s1 == '\n')
            s1++;
        while (*s1)
            ret[i++] = *s1++;
    }
    if (s2)
        while (*s2)
            ret[i++] = *s2++;
    ret[i] = '\0';
    //printf("strjoin before return : %s\n", ret);
    return (ret);
}
