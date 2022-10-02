/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:22:20 by soo               #+#    #+#             */
/*   Updated: 2022/10/02 05:07:32 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_now(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

int	time_watch(long long start)
{
	long long	now;

	now = get_now();
	return ((int)(now - start));
}

void	throw_time(t_philo *philo, long long start, int end)
{
	t_param		*param;

	param = philo->param;
	while (time_watch(start) < end)
		usleep(200);
}
