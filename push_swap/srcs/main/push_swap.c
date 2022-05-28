/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 21:43:01 by soo               #+#    #+#             */
/*   Updated: 2022/05/28 17:53:01 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_deque(t_node *cmd)
{
	while (cmd)
	{
		if (cmd->next && cmd->value == RB && cmd->next->value == RA)
		{
			write(1, "rr\n", 3);
			cmd = cmd->next->next;
		}
		else if (cmd->next && cmd->value == SA && cmd->next->value == SB)
		{
			write(1, "ss\n", 3);
			cmd = cmd->next->next;
		}
		else if (cmd->next && cmd->value == RRA && cmd->next->value == RRB)
		{
			write(1, "rrr\n", 4);
			cmd = cmd->next->next;
		}
		else
		{
			ft_putstr_fd(cmd->cmd, 1);
			write(1, "\n", 1);
			cmd = cmd->next;
		}
	}
}

void	arg_handler(int *arr, t_deque *deque_a, t_deque *deque_b, t_deque *cmd)
{
	int	deque_a_size;

	deque_a_size = deque_size(deque_a->head);
	if (!arr || deque_a_size < 2)
		exit(0);
	if (deque_a_size == 3)
		three_argc(arr, cmd, deque_a, 0);
	else if (deque_a_size == 5)
		five_argc(arr, cmd, deque_a, deque_b);
	else
	{
		a_to_b(arr, deque_a, deque_b, cmd);
		b_to_a(arr, deque_a, deque_b, cmd);
	}
	print_deque(cmd->head);
}

int	main(int argc, char **argv)
{
	t_deque	*deque_a;
	t_deque	*deque_b;
	t_deque	*command;
	int		*arr;

	deque_a = (t_deque *)malloc(sizeof(t_deque));
	deque_b = (t_deque *)malloc(sizeof(t_deque));
	command = (t_deque *)malloc(sizeof(t_deque));
	if (check_error(argc, deque_a, deque_b, argv) || !command)
		return (1);
	deque_init(command, 'c');
	arr = sort_array(deque_size(deque_a->head), deque_a->top);
	if (!arr)
		exit(0);
	arg_handler(arr, deque_a, deque_b, command);
	return (0);
}
