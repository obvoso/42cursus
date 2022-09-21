/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:22:20 by soo               #+#    #+#             */
/*   Updated: 2022/09/20 15:44:21 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <i386/types.h>

long long	get_now(void)
{
	struct timeval now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
	// subject는 milli, 나오는 건 macro, sec이니까 마이크로는 / 1000, sec은 * 1000해서 맞추는듯
}

long long	time_diff(long long start)
{
	long long now;
	
}