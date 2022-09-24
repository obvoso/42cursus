/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:21:44 by soo               #+#    #+#             */
/*   Updated: 2022/09/24 18:15:58 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_out_side(t_philo *philo)
{
	int	i;
	t_param	*param;
	
	param = philo->param;
	while (1)
	{
		i = 0;
		while(i < param->philos)
		{
			if (philo[i].state == FIN || philo[i].state == DIE)
			{
				return (1);
			}
			++i;
		}
	}
	return (0);
}

void	make_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].param->philos)
	{
		if (pthread_create(&(philo[i].tid), NULL, threading, (void *)&(philo[i])) != 0)
			return ;
		// if (philo->state == DIE || philo->state == FIN)
		// 	return ;
		if (check_finish(&philo[i]))
			return ;
		++i;
	}
	i = 0;
	if (check_out_side(philo))
	{
	
		while (i < philo[0].param->philos)
		{
			pthread_detach(philo[i].tid);
			++i;
		}
		return ;
	}
	while (i < philo[0].param->philos)
	{
		pthread_join(philo[i].tid, NULL);
		++i;
	}
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_param	param;

	if (argc != 5 && argc != 6)
		return (1);
	memset(&param, 0, sizeof(t_param));
	if (!args_parse(&param, argv, argc) || !init_param(&param))
		return (1);
	philo = (t_philo *)malloc(sizeof(t_philo) * param.philos);
	init_philo(philo, &param);
	make_thread(philo);
	return (0);
}