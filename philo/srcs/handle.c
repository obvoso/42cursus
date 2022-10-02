/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 21:34:32 by soo               #+#    #+#             */
/*   Updated: 2022/10/02 16:55:59 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_die_mutex(t_param *param)
{
	if (!param->print || !param->fork || !param->check)
		return (1);
	pthread_mutex_lock(param->check);
	if (param->die_state)
	{
		pthread_mutex_unlock(param->check);
		return (1);
	}
	pthread_mutex_unlock(param->check);
	return (0);
}

void	free_all(t_param param)
{
	int	i;

	i = 0;
	while (i < param.philos)
	{
		pthread_mutex_destroy(&param.fork[i]);
		++i;
	}
	pthread_mutex_unlock(param.print);
	pthread_mutex_destroy(param.print);
	pthread_mutex_destroy(param.check);
	// free(param.print);
	// free(param.fork);
	// free(param.check);
}
