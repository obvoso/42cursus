/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:44:13 by soo               #+#    #+#             */
/*   Updated: 2022/09/19 14:13:46 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_param *init_param(t_param *param)
{
	int	i;

	param->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * param->philos);
	//param->print = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!param->fork)
		return (NULL);
	i = 0;
	param->order = (int *)malloc(sizeof(int) * param->philos);
	memset(param->order, -1, sizeof(param->order));
	if (pthread_mutex_init(&(param->print), NULL) != 0)
		return (NULL);
	while (i++ < param->philos)
	{
		if (pthread_mutex_init(&(param->fork[i]), NULL) != 0)
			return (NULL);
	}
	return (param);
}

t_philo *init_philo(t_arg arg)
{
	int	i;

	i = 0;
	while (i++ < arg.param->philos)
	{
		arg.philo[i].num = i;
		arg.philo[i].state = INIT;
		arg.philo->l_fork = i;
		arg.philo->r_fork = (i + 1) % arg.param->philos;
	}
	return (arg.philo);
}
