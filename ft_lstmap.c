/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:09:02 by soo               #+#    #+#             */
/*   Updated: 2022/03/21 14:41:35 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	clear_lst(t_list *lst, void (*del)(void *))
{
	t_list	*next;

	while (lst)
	{
		next = lst->next;
		ft_lstdelone(lst, del);
		lst = next;
	}
	free(next);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head;

	if (lst && *f && del)
	{
		head = ft_lstnew(f(lst->content));
		new = head->next;
		while (lst)
		{
			new = ft_lstnew(f(lst->content));
			if (!new)
			{
				clear_lst(head, del);
				return (NULL);
			}
			lst = lst->next;
			if (!lst)
				new->next = NULL;
			else
				new = new->next;
		}
		return (head);
	}
	return (NULL);
}
