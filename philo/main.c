/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:21:44 by soo               #+#    #+#             */
/*   Updated: 2022/09/19 21:33:02 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeping(t_arg *arg)
{
	print_state(*arg, SLEEPING, 's');
	usleep(arg->param.sleep_time);
}

void	thinking(t_arg *arg)
{
	print_state(*arg, THINKING, 't');
}

void	eating(t_arg *arg)
{
		pthread_mutex_lock(&(arg->param.fork[arg->philo[arg->idx].l_fork]));
		print_state(*arg, TAKE, 'l');
		pthread_mutex_lock(&(arg->param.fork[arg->philo[arg->idx].r_fork]));
		print_state(*arg, TAKE, 'r');
		pthread_mutex_unlock(&(arg->param.fork[arg->philo[arg->idx].l_fork]));
		pthread_mutex_unlock(&(arg->param.fork[arg->philo[arg->idx].r_fork]));
		arg->param.eat_check[arg->idx] = EAT;
}

void	threading(void *p_arg)
{
	t_arg	*arg;

	arg = (t_arg *)p_arg;
	while (1)
	{
		if (arg->idx % 2 == 0)
			usleep(50);
		eating(arg);
		sleeping(arg);
		tinking(arg);
	}
}

void	make_thread(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->param.philos)
	{
		arg->idx = i;
		pthread_create(&(arg->philo[i]), NULL, threading, (void *)arg);
		++i;
	}
}

int	main(int argc, char **argv)
{
	t_arg	arg;

	if (argc != 5 && argc != 6)
		return (1);
	memset(&(arg.param), 0, sizeof(t_param));
	if (!args_parse(&(arg.param), argv, argc) || init_param(&arg.param))
		return (1);
	arg.philo = (t_philo *)malloc(sizeof(t_philo) * arg.param.philos);
	init_philo(arg);
	make_thread(&arg);
	return (0);
}