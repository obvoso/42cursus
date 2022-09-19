/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:44:13 by soo               #+#    #+#             */
/*   Updated: 2022/09/19 21:29:48 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_param *init_param(t_param *param)
{
	int	i;

	param->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * param->philos);
	param->print = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!param->fork || !param->print)
		return (NULL);
	param->eat_check = (int *)malloc(sizeof(int) * param->philos);
	if (!param->eat_check)
		return (NULL);
	memset(param->eat_check, 0, sizeof(param->eat_check));
	if (pthread_mutex_init(&(param->print), NULL) != 0)
		return (NULL);
	i = 0;
	while (i < param->philos)
	{
		if (pthread_mutex_init(&(param->fork[i]), NULL) != 0)
			return (NULL);
		++i;
	}
	return (param);
}

t_philo *init_philo(t_arg arg)
{
	int	i;

	i = 0;
	while (i < arg.param.philos)
	{
		arg.philo[i].num = i;
		arg.philo->l_fork = i;
		arg.philo->r_fork = (i + 1) % arg.param.philos;
		++i;
	}
	return (arg.philo);
}
