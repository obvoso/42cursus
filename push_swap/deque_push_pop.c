/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_push_pop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:05:19 by soo               #+#    #+#             */
/*   Updated: 2022/05/16 16:24:40 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_deque *add_front(int value, t_deque **deque)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
	{
		clear_node(*deque);
		return (NULL);
	}
	if (is_empty(deque))
		(*deque)->tail = new;
	else
		(*deque)->head->prev = new;
	new->prev = NULL;
	new->next = (*deque)->head;
	new->value = value;
	(*deque)->head = new;
	return (*deque);
}

t_deque *add_back(int value, t_deque **deque)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
	{
		clear_node(*deque);
		return (NULL);
	}
	if (is_empty(deque))
		(*deque)->head = new;
	else
		(*deque)->tail->next = new;
	new->prev = (*deque)->tail;
	new->next = NULL;
	new->value = value;
	(*deque)->tail = new;
	return (*deque);
}

int	rm_front(t_deque **deque)
{
	t_node	*rm_node;
	int		value;
	
	if (is_empty(deque))
		return (0);//고치렴
	rm_node = (*deque)->head;
	value = rm_node->value;
	free(rm_node);
	(*deque)->head = (*deque)->head->next;
	if (!(*deque)->head)
		(*deque)->tail = NULL;
	else
		(*deque)->head->prev = NULL;
	return (value);
}

int rm_back(t_deque **deque)
{
	t_node *rm_node;
	int	value;

	if(is_empty(deque))
		return (0);//고치렴2
	rm_node = (*deque)->tail;
	value = rm_node->value;
	free(rm_node);
	(*deque)->tail = (*deque)->tail->prev;
	if (!(*deque)->tail)
		(*deque)->head = NULL;
	else
		(*deque)->tail->next = NULL;
	return (value);
}

