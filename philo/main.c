/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:21:44 by soo               #+#    #+#             */
/*   Updated: 2022/09/19 00:13:37 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	threading(void	*p_arg)
{
	t_arg	*arg;
	int		i;

	i = 1;
	arg = (t_arg *)p_arg;
	while (1)
	{
		//여기서 홀 짝  구구분분하하기
		if (arg->idx % i == 1)
		{
			pthread_mutex_lock(&(arg->param->fork[arg->philo[arg->idx].l_fork]));
			print_state();
			pthread_mutex_lock(&(arg->param->fork[arg->philo[arg->idx].r_fork]));
		}
		else
		{
			
		}

	}
}

void	make_thread(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->param->philos)
	{
		arg->idx = i;
		pthread_create(&(arg->philo[i]), NULL, threading, (void *)arg);
		++i;
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