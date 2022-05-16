/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:32:42 by soo               #+#    #+#             */
/*   Updated: 2022/05/16 16:31:07 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_deque(t_deque **srcs, t_deque **dest)
{
	if (is_empty(srcs))
		return ;
	add_back(rm_back(srcs), dest);
	write(1, "push\n", 5);
}

void rotate_deque(t_deque **deque)
{
	if (is_empty(deque))
		return ;
	add_back(rm_front(deque), deque);
	write(1, "rota\n", 5);
}

void rev_rotate_deque(t_deque **deque)
{
	if (is_empty(deque))
		return ;
	add_front(rm_back(deque), deque);
	write(1, "rero\n", 5);
}

void swap_deque(t_deque **deque)
{
	t_node	*tmp;

	if (is_empty(deque))
		return ;
	tmp = (*deque)->tail->prev;
	tmp->prev->next = (*deque)->tail;
	(*deque)->tail->next = tmp;
	(*deque)->tail->prev = tmp->prev;
	tmp->prev = (*deque)->tail;
	tmp->next = NULL;
	(*deque)->tail = tmp;
	write(1, "swap\n", 5);
}

