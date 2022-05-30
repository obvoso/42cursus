/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_push_pop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:05:19 by soo               #+#    #+#             */
/*   Updated: 2022/05/29 20:09:29 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque	*add_front(int value, t_deque **deque)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
	{
		clear_node(*deque);
		return (NULL);
	}
	if (is_empty(*deque))
		(*deque)->top = new;
	else
		(*deque)->head->prev = new;
	new->prev = NULL;
	new->next = (*deque)->head;
	new->value = value;
	(*deque)->head = new;
	return (*deque);
}

t_deque	*add_back(int value, char *command, t_deque **deque)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
	{
		clear_node(*deque);
		return (NULL);
	}
	if (is_empty(*deque))
		(*deque)->head = new;
	else
		(*deque)->top->next = new;
	new->prev = (*deque)->top;
	new->next = NULL;
	if ((*deque)->name == 'c')
		new->cmd = command;
	new->value = value;
	(*deque)->top = new;
	return (*deque);
}

int	rm_front(t_deque **deque)
{
	t_node	*rm_node;
	int		value;

	rm_node = (*deque)->head;
	value = rm_node->value;
	(*deque)->head = (*deque)->head->next;
	free(rm_node);
	if (!(*deque)->head)
		(*deque)->top = NULL;
	else
		(*deque)->head->prev = NULL;
	return (value);
}

int	rm_back(t_deque **deque)
{
	t_node	*rm_node;
	int		value;

	rm_node = (*deque)->top;
	value = rm_node->value;
	(*deque)->top = (*deque)->top->prev;
	free(rm_node);
	if (!(*deque)->top)
		(*deque)->head = NULL;
	else
		(*deque)->top->next = NULL;
	return (value);
}
