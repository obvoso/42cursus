/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:02:25 by soo               #+#    #+#             */
/*   Updated: 2022/05/28 15:48:29 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "push_swap.h"

int		is_deque_sort(t_deque *deque_a, t_deque *deque_b);
void	check_op(char *op, t_deque *deq_a, t_deque *deq_b, t_deque *cmd);
void	check_op2(char *op, t_deque *deq_a, t_deque *deq_b, t_deque *cmd);

#endif