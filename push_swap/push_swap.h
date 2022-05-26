/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 21:44:20 by soo               #+#    #+#             */
/*   Updated: 2022/05/26 21:43:49 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define TRUE 1
# define FALSE 0
# define PA 0
# define PB 1
# define SA 2
# define SB 3
# define RA 4
# define RB 5
# define RRA 6
# define RRB 7

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				value;
	char			*cmd;
}	t_node;

typedef struct s_deque
{
	struct s_node	*head;
	struct s_node	*top;
	char			name;
}	t_deque;

// main
t_deque	*argv_init(int argc, char **argv, t_deque **deque_a);
void	arg_handler(int *arr, t_deque *deque_a, t_deque *deque_b, t_deque *cmd);
void	print_deque(t_node *command);
int		get_chunk_size(int size);

// deque
t_deque	*deque_init(t_deque *deque, char name);
int		is_empty(t_deque *deque);
t_deque	*clear_node(t_deque *deque);
t_deque	*add_front(int value, t_deque **deque);
t_deque	*add_back(int value, char *command, t_deque **deque);
int		rm_front(t_deque **deque);
int		rm_back(t_deque **deque);
int		deque_size(t_node *deque);

// deque_sort
int		find_deque_value(int value, t_node *deque);
void	a_to_b(int *arr, t_deque *deque_a, t_deque *deque_b, t_deque *cmd);
void	b_to_a(int *arr, t_deque *deque_a, t_deque *deque_b, t_deque *cmd);
void	three_argc(int *arr, t_deque *command, t_deque *deque_a, int min);
void	five_argc(int *arr, t_deque *cmd, t_deque *deque_a, t_deque *deque_b);

//array_sort
void	quick_sort(int *arr, int start, int end);
void	quick_sort_swap(int arr[], int i, int j);
int		*sort_array(int size, t_node *deque);
int		is_sort(int	*tab, int length);
void	ft_rev_int_tab(int *tab, int size);

// error
int		check_error(int argc, t_deque *deque_a, t_deque *deque_b, char **argv);
int		check_overlap(char **arr_av);
t_deque	*check_digit(char **arr_av, t_deque **deque);
t_deque	*check_argv(char **arr_av, t_deque **deque);

// deque_func
void	push_deque(t_deque *srcs, t_deque *dest, char cmd, t_deque *command);
void	rotate_deque(t_deque *deque, char cmd, t_deque *command);
void	rev_rotate_deque(t_deque *deque, char cmd, t_deque *command);
void	swap_deque(t_deque **deque, char cmd, t_deque *command);

#endif