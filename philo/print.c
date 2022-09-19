/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:55:33 by soo               #+#    #+#             */
/*   Updated: 2022/09/19 21:30:14 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_state(t_arg arg, char *state, char flag)
{
	pthread_mutex_lock(arg.param.print);
	gettimeofday(&(arg.param.now), NULL);
	printf("ld ", arg.param.now.tv_usec);
	printf("%d %s\n", arg.idx + 1, state);
	if (flag == 'r')
	{
		gettimeofday($(arg.param.now), NULL);
		printf("ld ", arg.param.now.tv_usec);
		printf("%d %d\n", arg.idx + 1, EATING);
	}
	pthread_mutex_unlock(arg.param.print);
	if (flag == 'l' || flag == 'r')
		++arg.philo->eat_cnt;
}