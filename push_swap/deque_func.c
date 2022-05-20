/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:32:42 by soo               #+#    #+#             */
/*   Updated: 2022/05/20 17:54:32 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_deque(t_deque **srcs, t_deque **dest, char cmd)
{
	if (is_empty(srcs))
		return ;
	add_back(rm_back(srcs), dest);
	write(1, "p", 1);
	write(1, &cmd, 1);
	write(1, "\n", 1);
}

void rotate_deque(t_deque **deque, char cmd)
{
	if (is_empty(deque))
		return ;
	add_front(rm_back(deque), deque);
	write(1, "r", 1);
	write(1, &cmd, 1);
	write(1, "\n", 1);
}

void rev_rotate_deque(t_deque **deque, char cmd)
{
	if (is_empty(deque))
		return ;
	add_back(rm_front(deque), deque);
	write(1, "rr", 2);
	write(1, &cmd, 1);
	write(1, "\n", 1);
}

void swap_deque(t_deque **deque, char cmd)
{
	t_node	*tmp;

	if (is_empty(deque))
		return ;
	tmp = (*deque)->top->prev;
	tmp->prev->next = (*deque)->top;
	(*deque)->top->next = tmp;
	(*deque)->top->prev = tmp->prev;
	tmp->prev = (*deque)->top;
	tmp->next = NULL;
	(*deque)->top = tmp;
	write(1, "s", 1);
	write(1, &cmd, 1);
	write(1, "\n", 1);
}

