/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:18:26 by soo               #+#    #+#             */
/*   Updated: 2022/05/28 15:53:02 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque	*argv_init(int argc, char **argv, t_deque **deque_a)
{
	char	**arr_av;
	int		i;
	int		j;

	i = 0;
	while (++i < argc)
	{
		arr_av = ft_split(argv[i], ' ');
		if (!check_argv(arr_av, deque_a))
			return (NULL);
		j = 0;
		while (arr_av[j])
		{
			if (!check_maxint(arr_av[j], deque_a, ft_atoi(arr_av[j])))
			{
				free(arr_av[j]);
				break ;
			}
			add_front(ft_atoi(arr_av[j]), deque_a);
			free(arr_av[j++]);
		}
		free(arr_av);
	}
	return (*deque_a);
}

t_deque	*deque_init(t_deque *deque, char name)
{
	deque->head = NULL;
	deque->top = NULL;
	deque->name = name;
	return (deque);
}

int	is_empty(t_deque *deque)
{
	if (!deque)
		return (TRUE);
	if (deque->head == NULL)
		return (TRUE);
	return (FALSE);
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
	deque->top = NULL;
	return (deque);
}

int	deque_size(t_node *deque)
{
	int	size;

	size = 0;
	while (deque)
	{
		++size;
		deque = deque->next;
	}
	return (size);
}
