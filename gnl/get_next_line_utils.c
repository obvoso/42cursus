/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:46:35 by soo               #+#    #+#             */
/*   Updated: 2022/04/01 22:22:46 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <string.h>
#include <stdio.h>

size_t ft_strlen(const char *s)
{
	size_t	len;

	// printf("ft_strlen:%s\n", s);
	len = 0;
	if (s)
		while (s[len])
			++len;
	return (len);
}

char *ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

char *ft_strchr(const char *s, int c)
{
	char	ch;
	int		i;

	i = -1;
	ch = (char)c;
	while (s[++i])
	{
		if (s[i] == ch)
			return ((char *)&s[i]);
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	i;

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

char	*ft_strdup(char *s1, size_t size)
{
	char	*ret;
	size_t	len;
	size_t	i;
	
	i = 0;
	len = ft_strlen(s1);
	printf("ft_strdup : %d %d\n", (int)size, (int)len);
	if (len > size)
		ret = (char *)malloc(size + 1);
	else
		ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	if (*s1 == '\n')
		s1++;
	while (i < size && *s1)
		ret[i++] = *s1++;
	ret[i] = '\0';
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!%s\n", ret);
	return (ret);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		if (*lst)
			ft_lstlast(*lst)->next = new;
		else
			*lst = new;
	}
}

t_list	*ft_lstnew(int fd)
{
	t_list	*ret;

	ret = (t_list *)malloc(sizeof(t_list));
	if (!ret)
		return (ret);
	ret->fd = fd;
	ret->line = NULL;
	ret->backup = NULL;
	ret->next = NULL;
	return (ret);
}

