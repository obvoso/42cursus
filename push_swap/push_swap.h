/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 21:44:20 by soo               #+#    #+#             */
/*   Updated: 2022/05/12 17:10:31 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define TRUE 1
# define FALSE 0

typedef struct	s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int		value;
}	t_node;

typedef struct	s_deque
{
	struct s_node	*head;
	struct s_node	*tail;
}	t_deque;

t_deque *check_argv(char **arr_av, t_deque **deque);
t_deque *init(int argc, char **argv, t_deque **deque_a);

// deque
t_deque *deque_init(t_deque **deque);
int is_empty(t_deque **deque);
t_deque	*clear_node(t_deque *deque);
t_deque *add_first(int value, t_deque **deque);
t_deque *add_last(int value, t_deque **deque);
int	rm_front(t_deque **deque);
int rm_last(t_deque **deque);

#endif