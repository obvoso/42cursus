/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:55:33 by soo               #+#    #+#             */
/*   Updated: 2022/09/19 14:14:44 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_state(t_arg arg, char *state)
{
	//timestamp
	pthread_mutex_lock(arg.param->print);
	printf("%d %s\n", arg.idx, state);
	pthread_mutex_unlock(arg.param->print);
}