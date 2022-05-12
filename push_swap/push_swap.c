/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 21:43:01 by soo               #+#    #+#             */
/*   Updated: 2022/05/12 17:13:01 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_deque *check_argv(char **arr_av, t_deque **deque)
{
	int	i;
	int	j;

	i = 0;
	while (arr_av[i])
	{
		j = 0;
		while (arr_av[i][j])
		{
			if (!ft_isdigit((int)arr_av[i][j++]))
			{
				if ((*deque)->head)
				{
					clear_node(*deque);
					free (*deque);
					*deque = NULL;
				}
				while (*arr_av)
					free(*arr_av++);
				return (NULL);
			}
		}
	++i;
	}
	return (*deque);
}

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
			return (NULL);
		}
		if (!check_argv(arr_av, deque_a))
		{
			free(arr_av);
			return (NULL);
		}
		j = 0;
		while (arr_av[j])
		{
			add_last(ft_atoi(arr_av[j]), deque_a);
			free(arr_av[j]);
		}
		free(arr_av);
	}
	return (*deque_a);
}

int main(int argc, char **argv)
{
	t_deque	*deque_a;
	t_deque *deque_b;
	t_node	*now;

	deque_a = (t_deque *)malloc(sizeof(t_deque));
	deque_b = (t_deque *)malloc(sizeof(t_deque));
	if (!deque_a || !deque_b)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!deque_init(&deque_a) || !deque_init(&deque_b))
		return (1);
	if (argc < 2)
		return (1);
	if (!init(argc, argv, &deque_a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	
	//노드 생성 확인
	if (!is_empty(&deque_a) && !is_empty(&deque_b))
	{
		now = deque_a->head;
		while(now)
		{
			printf("%d\n", now->value);
			now = now->next;
		}
	}
	system("leaks a.out | grep leaked");
}