/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:32:42 by soo               #+#    #+#             */
/*   Updated: 2022/05/28 15:42:07 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int size)
{
	if (size <= 100)
		return (15);
	if (size <= 500)
		return (30);
	if (size <= 1000)
		return (45);
	if (size <= 2000)
		return (65);
	if (size <= 5000)
		return (150);
	return (200);
}

void	push_deque(t_deque *srcs, t_deque *dest, char cmd, t_deque *command)
{
	if (is_empty(srcs))
		return ;
	add_back(rm_back(&srcs), NULL, &dest);
	if (cmd == 'a')
		add_back(0, "pa", &command);
	else
		add_back(1, "pb", &command);
}

void	rotate_deque(t_deque *deque, char cmd, t_deque *command)
{
	if (is_empty(deque) || (deque_size(deque->head) == 1))
		return ;
	add_front(rm_back(&deque), &deque);
	if (cmd == 'a')
		add_back(4, "ra", &command);
	else
		add_back(5, "rb", &command);
}

void	rev_rotate_deque(t_deque *deque, char cmd, t_deque *command)
{
	if (is_empty(deque) || (deque_size(deque->head) == 1))
		return ;
	add_back(rm_front(&deque), NULL, &deque);
	if (cmd == 'a')
		add_back(6, "rra", &command);
	else
		add_back(7, "rrb", &command);
}

void	swap_deque(t_deque **deque, char cmd, t_deque *command)
{
	t_node	*tmp;

	if (is_empty(*deque) || (deque_size((*deque)->head) == 1))
		return ;
	tmp = (*deque)->top->prev;
	tmp->prev->next = (*deque)->top;
	(*deque)->top->next = tmp;
	(*deque)->top->prev = tmp->prev;
	tmp->prev = (*deque)->top;
	tmp->next = NULL;
	(*deque)->top = tmp;
	if (cmd == 'a')
		add_back(2, "sa", &command);
	else
		add_back(3, "sb", &command);
}
