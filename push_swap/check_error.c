/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:32:11 by soo               #+#    #+#             */
/*   Updated: 2022/05/18 22:31:26 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_error(int argc, t_deque **deque_a, t_deque **deque_b, char **argv)
{
	if (!deque_a || !deque_b)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!deque_init(deque_a, 'a') || !deque_init(deque_b, 'b'))
		return (1);
	if (argc < 2)
		return (1);
	if (!init(argc, argv, deque_a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

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
			if (arr_av[i][j] == '-')
				++j;
			if (!ft_isdigit((int)arr_av[i][j++]))
			{
				if ((*deque)->head)
				{
					clear_node(*deque);
					free(*deque);
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

int	check_overlap(char **arr_av)
{
	int	i;
	int	j;

	i = 0;
	while (arr_av[i + 1])
	{
		j = i + 1;
		while (arr_av[j])
			if(!ft_strncmp(arr_av[i], arr_av[j++], 11))
				return (0);
		++i;
	}
	return (1);
}