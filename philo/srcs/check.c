/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 21:30:50 by soo               #+#    #+#             */
/*   Updated: 2022/09/28 21:32:15 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_mutex(t_param *param)
{
	if (param->last_eat && param->check && param->state && \
		param->print && param->fork)
		return (1);
	return (0);
}

int	check_die_mutex(t_param *param)
{
	if (!check_mutex(param))
		return (1);
	pthread_mutex_lock(param->state);
	if (param->die_state)
		return (1);
	pthread_mutex_unlock(param->state);
	return (0);
}

int	check_threading_param(t_param *param, t_philo *philo)
{
	int	flag;

	if (!check_mutex(param))
		return (2);
	pthread_mutex_lock(param->state);
	if (param->die_state)
		return (2);
	pthread_mutex_unlock(param->state);
	pthread_mutex_lock(param->check);
	flag = param->eat_check[philo->num];
	pthread_mutex_unlock(param->check);
	return (flag);
}