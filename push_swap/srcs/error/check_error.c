/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:32:11 by soo               #+#    #+#             */
/*   Updated: 2022/05/28 17:52:41 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_error(int argc, t_deque *deque_a, t_deque *deque_b, char **argv)
{
	if (!deque_a || !deque_b)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!deque_init(deque_a, 'a') || !deque_init(deque_b, 'b'))
		return (1);
	if (!argv_init(argc, argv, &deque_a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!chk_dup(&deque_a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

t_deque	*check_argv(char **arr_av, t_deque **deque)
{
	if (!arr_av && !is_empty(*deque))
	{
		clear_node(*deque);
		free(*deque);
		*deque = NULL;
		return (NULL);
	}
	if (!check_digit(arr_av, deque) || !check_overlap(arr_av))
	{
		free(arr_av);
		return (NULL);
	}
	return (*deque);
}

t_deque	*check_maxint(char *arr_av, t_deque **deque_a, int value)
{
	if (value == 0 && *arr_av - '0' != 0)
	{
		clear_node(*deque_a);
		free(*deque_a);
		*deque_a = NULL;
		return (NULL);
	}
	return (*deque_a);
}

t_deque	*check_digit(char **arr_av, t_deque **deque)
{
	int	i;
	int	j;

	i = -1;
	while (arr_av[++i])
	{
		j = 0;
		if (arr_av[i][j] == '-')
			++j;
		while (ft_isdigit((int)arr_av[i][j]))
			++j;
		if (arr_av[i][j] != '\0')
		{
			if (!is_empty(*deque))
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
			if (!ft_strncmp(arr_av[i], arr_av[j++], 11))
				return (0);
		++i;
	}
	return (1);
}
