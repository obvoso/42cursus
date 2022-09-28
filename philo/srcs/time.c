/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:22:20 by soo               #+#    #+#             */
/*   Updated: 2022/09/26 21:50:10 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_now(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

long long	time_watch(long long start)
{
	long long	now;

	if (!start)
	{
		start = get_now();
		return (start);
	}
	now = get_now();
	return (now - start);
}

void	throw_time(t_philo *philo, long long start, int end)
{
	int			now;
	long long	l_end;
	t_param		*param;

	now = time_watch(start);
	param = philo->param;
	l_end = (long long)end;
	while (now < end)
	{
		if (!check_mutex(param))
			return ;
		pthread_mutex_lock(param->state);
		if (param->die_state)
			return ;
		pthread_mutex_unlock(param->state);
		usleep(100);
		now = time_watch(start);
	}
}