/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:46:35 by soo               #+#    #+#             */
/*   Updated: 2022/04/04 22:19:42 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    size_t len;

    len = 0;
    if (s)
        while (s[len])
            ++len;
    return (len);
}

t_list *ft_lstnew(int fd)
{
	t_list *ret;

	ret = (t_list *)malloc(sizeof(t_list));
	if (!ret)
		return (ret);
	ret->fd = fd;
	ret->backup = NULL;
	ret->next = NULL;
	return (ret);
}

char *ft_strjoin(char *s1, char *s2)
{
    char    *tmp;
    char *ret;
    size_t i;

    ret = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!ret)
        return (NULL);
    i = 0;
    if (s1 && *s1)
    {
        tmp = s1;
        while (*s1)
            ret[i++] = *s1++;
        free(tmp);
    }
    if (s2)
        while (*s2)
            ret[i++] = *s2++;
    ret[i] = '\0';
    return (ret);
}

char *ft_strdup(char *s1, size_t size)
{
	char *ret;
	size_t i;

	i = 0;
    if (size == 0)
        return (NULL);
	ret = (char *)malloc(size + 1);
	if (!ret)
		return (NULL);
	while (i < size && *s1)
		ret[i++] = *s1++;
	ret[i] = '\0';

	return (ret);
}