/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:41:06 by soo               #+#    #+#             */
/*   Updated: 2022/05/29 19:59:58 by soo              ###   ########.fr       */
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
	if (!ft_strncmp(op, "pa\n", 2))
		push_deque(deq_b, deq_a, 'a', cmd);
	else if (!ft_strncmp(op, "pb\n", 2))
		push_deque(deq_a, deq_b, 'b', cmd);
	else if (!ft_strncmp(op, "sa\n", 2))
		swap_deque(&deq_a, 'a', cmd);
	else if (!ft_strncmp(op, "sb\n", 2))
		swap_deque(&deq_b, 'b', cmd);
	else if (!ft_strncmp(op, "ss\n", 2))
	{
		swap_deque(&deq_a, 'a', cmd);
		swap_deque(&deq_b, 'b', cmd);
	}
	else if (!ft_strncmp(op, "ra\n", 2))
		rotate_deque(deq_a, 'a', cmd);
	else if (!ft_strncmp(op, "rb\n", 2))
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
		write(2, "Error\n", 6);
		exit(0);
	}
}

void	checker(t_deque *deque_a, t_deque *deque_b, t_deque *cmd)
{
	char	*op;

	op = "1";
	while (op)
	{
		op = get_next_line(0);
		if (!op)
			break ;
		if (op[ft_strlen(op) - 1] != '\n')
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		check_op(op, deque_a, deque_b, cmd);
		free(op);
	}
	if (is_deque_sort(deque_a, deque_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_deque	*deque_a;
	t_deque	*deque_b;
	t_deque	*cmd;

	deque_a = (t_deque *)malloc(sizeof(t_deque));
	deque_b = (t_deque *)malloc(sizeof(t_deque));
	cmd = (t_deque *)malloc(sizeof(t_deque));
	if (check_error(argc, deque_a, deque_b, argv) || !cmd)
		return (1);
	if (deque_size(deque_a->head) < 2)
		exit(0);
	deque_init(cmd, 'c');
	checker(deque_a, deque_b, cmd);
	return (0);
}
