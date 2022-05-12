/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:18:26 by soo               #+#    #+#             */
/*   Updated: 2022/05/12 17:10:45 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_deque *deque_init(t_deque **deque)
{
	(*deque)->head = NULL;
	(*deque)->tail = NULL;
	return (*deque);
}

int is_empty(t_deque **deque)
{
	if (!(*deque)->head)
		return TRUE;
	return FALSE;
}

t_deque	*clear_node(t_deque *deque)
{
	t_node	*p_node;
	t_node	*n_node;

	n_node = deque->head;
	while (n_node)
	{
		p_node = n_node;
		n_node = p_node->next;
		free(p_node);
	}
	deque->head = NULL;
	deque->tail = NULL;
	return (deque);
}