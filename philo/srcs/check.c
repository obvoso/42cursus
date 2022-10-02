/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 21:34:32 by soo               #+#    #+#             */
/*   Updated: 2022/10/02 17:28:14 by soo              ###   ########.fr       */
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
