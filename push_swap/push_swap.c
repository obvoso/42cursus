/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 21:43:01 by soo               #+#    #+#             */
/*   Updated: 2022/05/20 22:51:33 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_deque *init(int argc, char **argv, t_deque **deque_a)
{
	char	**arr_av;
	int		i;
	int		j;

	i = 0;
	while (++i < argc)
	{
		arr_av = ft_split(argv[i], ' ');
		if (!arr_av)
		{
			clear_node(*deque_a);
			free(*deque_a);
			*deque_a = NULL;
			return (NULL);
		}
		if (!check_argv(arr_av, deque_a) || !check_overlap(arr_av))
		{
			free(arr_av);
			return (NULL);
		}
		j = 0;
		while (arr_av[j])
		{
			add_front(ft_atoi(arr_av[j]), deque_a);
			free(arr_av[j++]);
		}
		free(arr_av);
	}
	return (*deque_a);
}

int	get_chunk_size(int size)
{
	if (size >= 100)
		return (15);
	if (size >= 500)
		return (30);
	if (size >= 1000)
		return (45);
	if (size >= 2000)
		return (65);
	if (size >= 5000)
		return (150);
	return (200);
}

void	A_to_B(int *arr, int chunk, t_deque *deque_a, t_deque *deque_b)
{
	int	num;
	int	top;

	num = 0;
	while (!is_empty(&deque_a))
	{
		top = 0;
		while (arr[top] != deque_a->top->value)
			++top;
		if (top <= num)
		{
			push_deque(&deque_a, &deque_b, 'b');
			++num;
		}
		else if (num < top && top <= num + chunk)
		{
			push_deque(&deque_a, &deque_b, 'b');
			rotate_deque(&deque_b, 'b');
			++num;
		}
		else if (num + chunk < top)
			rotate_deque(&deque_a, 'a');
	}
}

int	find_deque_b(int value, t_node *deque)
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

void	B_to_A(int *arr, int arr_size, t_deque *deque_a, t_deque *deque_b)
{
	while (!is_empty(&deque_b))
	{
		--arr_size;
		if (find_deque_b(arr[arr_size], deque_b->top) >= ((arr_size + 1) / 2))
			while (arr[arr_size] != deque_b->top->value)
				rev_rotate_deque(&deque_b, 'b');
		else
			while (arr[arr_size] != deque_b->top->value)
				rotate_deque(&deque_b, 'b');
		push_deque(&deque_b, &deque_a, 'a');
	}
}

int	main(int argc, char **argv)
{
	t_deque	*deque_a;
	t_deque	*deque_b;
	int		*arr;

	deque_a = (t_deque *)malloc(sizeof(t_deque));
	deque_b = (t_deque *)malloc(sizeof(t_deque));
	if (check_error(argc, &deque_a, &deque_b, argv))
		return (1);
	arr = sort_array(deque_size(deque_a->head), deque_a->head);
	A_to_B(arr, get_chunk_size(deque_size(deque_a->head)), deque_a, deque_b);
	B_to_A(arr, deque_size(deque_b->head), deque_a, deque_b);
	//노드 생성 확인
	// swap_deque(&deque_b);
	/*
	if (!is_empty(&deque_a))
	{
		printf("dequeA\n\n");
		t_node	*now = deque_a->top;
		while(now)
		{
			printf("%d\n", now->value);
			now = now->prev;
		}
	}
	if (!is_empty(&deque_b))
	{
		printf("\n\ndequeB\n\n");
		t_node	*now2 = deque_b->top;
		while(now2)
		{
			printf("%d\n", now2->value);
			now2 = now2->prev;
		}
	}*/
	//system("leaks pushswap1 | grep leaked");
}