/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:53:35 by soo               #+#    #+#             */
/*   Updated: 2022/05/26 21:58:52 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_deque_value(int value, t_node *deque)
{
	int	i;

	i = 0;
	while (deque->value != value)
	{
		++i;
		deque = deque->prev;
	}
	return (i);
}

void	a_to_b(int *arr, t_deque *deque_a, t_deque *deque_b, t_deque *command)
{
	int	num;
	int	top;
	int	chunk;

	num = 0;
	chunk = get_chunk_size(deque_size(deque_a->head));
	while (!is_empty(deque_a))
	{
		top = 0;
		while (arr[top] != deque_a->top->value)
			++top;
		if (top <= num)
		{
			push_deque(deque_a, deque_b, 'b', command);
			++num;
		}
		else if (num < top && top <= num + chunk)
		{
			push_deque(deque_a, deque_b, 'b', command);
			rotate_deque(deque_b, 'b', command);
			++num;
		}
		else if (num + chunk < top)
			rotate_deque(deque_a, 'a', command);
	}
}

void	b_to_a(int *arr, t_deque *deque_a, t_deque *deque_b, t_deque *command)
{
	int	arr_size;

	arr_size = deque_size(deque_b->head);
	while (!is_empty(deque_b))
	{
		--arr_size;
		if (find_deque_value(arr[arr_size], deque_b->top) >= (arr_size / 2))
			while (arr[arr_size] != deque_b->top->value)
				rev_rotate_deque(deque_b, 'b', command);
		else
			while (arr[arr_size] != deque_b->top->value)
				rotate_deque(deque_b, 'b', command);
		push_deque(deque_b, deque_a, 'a', command);
	}
}

void	three_argc(int *arr, t_deque *cmd, t_deque *deque_a, int min)
{
	int	top;
	int	mid;

	top = deque_a->top->value;
	mid = deque_a->top->prev->value;
	if (top == arr[min] && mid != arr[min + 1])
	{
		rotate_deque(deque_a, 'a', cmd);
		swap_deque(&deque_a, 'a', cmd);
		rev_rotate_deque(deque_a, 'a', cmd);
	}
	else if (top == arr[min + 1])
	{
		if (mid == arr[min])
			swap_deque(&deque_a, 'a', cmd);
		else
			rev_rotate_deque(deque_a, 'a', cmd);
	}
	else if (top == arr[min + 2])
	{
		rotate_deque(deque_a, 'a', cmd);
		if (mid == arr[min + 1])
			swap_deque(&deque_a, 'a', cmd);
	}
}

void	five_argc(int *arr, t_deque *cmd, t_deque *deque_a, t_deque *deque_b)
{
	int	arr_size;
	int	idx;

	arr_size = 5;
	idx = 0;
	while (arr_size-- > 3)
	{
		if (find_deque_value(arr[idx], deque_a->top) > (arr_size / 2))
			while (arr[idx] != deque_a->top->value)
				rev_rotate_deque(deque_a, 'a', cmd);
		else
			while (arr[idx] != deque_a->top->value)
				rotate_deque(deque_a, 'a', cmd);
		push_deque(deque_a, deque_b, 'b', cmd);
		++idx;
	}
	three_argc(arr, cmd, deque_a, 2);
	if (deque_b->head->value > deque_b->top->value)
		swap_deque(&deque_b, 'b', cmd);
	push_deque(deque_b, deque_a, 'a', cmd);
	push_deque(deque_b, deque_a, 'a', cmd);
}
