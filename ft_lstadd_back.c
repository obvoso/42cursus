/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:08:46 by soo               #+#    #+#             */
/*   Updated: 2022/03/21 15:04:35 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	**tmp;

	if (lst && new)
	{
		if (*lst)
		{
			tmp = lst;
			while ((*tmp)->next)
				*tmp = (*tmp)->next;
			(*tmp)->next = new;
		}
		else
			*lst = new;
	}
}
