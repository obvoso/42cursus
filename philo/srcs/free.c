/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 21:34:32 by soo               #+#    #+#             */
/*   Updated: 2022/09/28 21:35:31 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_param param, t_philo **philo)
{
	int	i;

	i = 0;
	while (i < param.philos)
	{
		pthread_mutex_destroy(&param.fork[i]);
		++i;
	}
	free(*philo);
	free(param.fork);
	free(param.eat_check);
}