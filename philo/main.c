/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:21:44 by soo               #+#    #+#             */
/*   Updated: 2022/09/19 14:10:37 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	threading(void	*p_arg)
{
	t_arg	*arg;

	arg = (t_arg *)p_arg;
	while (1)
	{
		if (arg->idx % 2 == 0)
			usleep(50);
		pthread_mutex_lock(&(arg->param->fork[arg->philo[arg->idx].l_fork]));
		print_state();
		pthread_mutex_lock(&(arg->param->fork[arg->philo[arg->idx].r_fork]));
	}
}

void	make_thread(t_arg *arg)
{
	int	i;

	i = 0;
	while (i++ < arg->param->philos)
	{
		arg->idx = i;
		pthread_create(&(arg->philo[i]), NULL, threading, (void *)arg);
	}
}

int	main(int argc, char **argv)
{
	t_param	param;
	t_philo	*philo;
	t_arg	arg;

	if (argc != 5 && argc != 6)
		return (1);
	memset(&param, 0, sizeof(param));
	if (!args_parse(&param, argv, argc) || init_param(&param))
		return (1);
	philo = (t_philo *)malloc(sizeof(t_philo) * param.philos);
	arg.param = &param;
	arg.philo = philo;
	init_philo(arg);
	make_thread(&arg);
	
	return (0);
}