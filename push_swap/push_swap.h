/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 21:44:20 by soo               #+#    #+#             */
/*   Updated: 2022/05/20 18:17:44 by soo              ###   ########.fr       */
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
	int				value;
}	t_node;

typedef struct	s_deque
{
	struct s_node	*head;
	struct s_node	*top;
	char			name;
}	t_deque;

t_deque *init(int argc, char **argv, t_deque **deque_a);

// deque
t_deque *deque_init(t_deque **deque, char name);
int is_empty(t_deque **deque);
t_deque	*clear_node(t_deque *deque);
t_deque *add_front(int value, t_deque **deque);
t_deque *add_back(int value, t_deque **deque);
int	rm_front(t_deque **deque);
int rm_back(t_deque **deque);
int	deque_size(t_node *deque);
t_deque *check_argv(char **arr_av, t_deque **deque);

// to
void A_to_B(int *arr,int chunk, t_deque *deque_a, t_deque *deque_b);

int	get_chunk_size(int size);

//array_sort
void	quick_sort(int *arr, int start, int end);
int	*sort_array(int size, t_node *deque);
int	is_sort(int	*tab, int length);
void	ft_rev_int_tab(int *tab, int size);

// error
int check_error(int argc, t_deque **deque_a, t_deque **deque_b, char **argv);
int	check_overlap(char **arr_av);

// deque_func
void push_deque(t_deque **srcs, t_deque **dest, char cmd);
void rotate_deque(t_deque **deque, char cmd);
void rev_rotate_deque(t_deque **deque, char cmd);
void swap_deque(t_deque **deque, char cmd);


#endif