/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:22:20 by soo               #+#    #+#             */
/*   Updated: 2022/09/23 22:01:45 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <i386/types.h>

long long	get_now(void)
{
	struct timeval now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

long long	time_watch(long long start)
{
	long long now;

	if (!start)
	{
		start = get_now();
		return (start);
	}
	now = get_now();
	return (now - start);
}

void	throw_time(long long start, long long end)
{
	long long	now;

	now = time_watch(start);
	while(now <= end)
	{
		usleep(10);
		now = time_watch(start);
	}
}