/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:41:06 by soo               #+#    #+#             */
/*   Updated: 2022/05/28 15:34:49 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_deque_sort(t_deque *deque_a, t_deque *deque_b)
{
	t_node	*now;

	if (is_empty(deque_b) && !is_empty(deque_a))
	{
		now = deque_a->top;
		while (now->prev)
		{
			if (now->value > now->prev->value)
				return (FALSE);
			now = now->prev;
		}
		return (TRUE);
	}
	return (FALSE);
}

void	check_op(char *op, t_deque *deq_a, t_deque *deq_b, t_deque *cmd)
{
	if (!ft_strncmp(op, "pa\n", 3))
		push_deque(deq_b, deq_a, 'a', cmd);
	else if (!ft_strncmp(op, "pb\n", 3))
		push_deque(deq_a, deq_b, 'b', cmd);
	else if (!ft_strncmp(op, "sa\n", 3))
		swap_deque(&deq_a, 'a', cmd);
	else if (!ft_strncmp(op, "sb\n", 3))
		swap_deque(&deq_b, 'b', cmd);
	else if (!ft_strncmp(op, "ss\n", 3))
	{
		swap_deque(&deq_a, 'a', cmd);
		swap_deque(&deq_b, 'b', cmd);
	}
	else if (!ft_strncmp(op, "ra\n", 3))
		rotate_deque(deq_a, 'a', cmd);
	else if (!ft_strncmp(op, "rb\n", 3))
		rotate_deque(deq_b, 'b', cmd);
	else
		check_op2(op, deq_a, deq_b, cmd);
}

void	check_op2(char *op, t_deque *deq_a, t_deque *deq_b, t_deque *cmd)
{
	if (!ft_strncmp(op, "rr\n", 3))
	{
		rotate_deque(deq_a, 'a', cmd);
		rotate_deque(deq_b, 'b', cmd);
	}
	else if (!ft_strncmp(op, "rra\n", 4))
		rev_rotate_deque(deq_a, 'a', cmd);
	else if (!ft_strncmp(op, "rrb\n", 4))
		rev_rotate_deque(deq_b, 'b', cmd);
	else if (!ft_strncmp(op, "rrr\n", 4))
	{
		rev_rotate_deque(deq_a, 'a', cmd);
		rev_rotate_deque(deq_b, 'b', cmd);
	}
	else
	{
		write(1, "KO\n", 3);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_deque	*deque_a;
	t_deque	*deque_b;
	t_deque	*cmd;
	char	*op;

	deque_a = (t_deque *)malloc(sizeof(t_deque));
	deque_b = (t_deque *)malloc(sizeof(t_deque));
	cmd = (t_deque *)malloc(sizeof(t_deque));
	if (check_error(argc, deque_a, deque_b, argv) || !cmd)
		return (1);
	deque_init(cmd, 'c');
	op = "1";
	while (op)
	{
		op = get_next_line(0);
		if (!op)
			break ;
		check_op(op, deque_a, deque_b, cmd);
		free(op);
	}
	if (is_deque_sort(deque_a, deque_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
