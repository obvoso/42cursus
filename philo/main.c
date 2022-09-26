/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:21:44 by soo               #+#    #+#             */
/*   Updated: 2022/09/26 15:06:50 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_must_eat(t_param *param, t_philo *philo, int philos, int must_eat)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (must_eat)
	{
		while (i < philos)
		{
			if (philo[i].eat_cnt < must_eat)
				return (0);
			++i;
		}
		philo->param->die_state = 1;
		pthread_mutex_lock(param->print);
		ft_putendl(FINISH);
		pthread_mutex_unlock(param->print);
		return (1);
	}
	return (0);
}

int	check_die_state(t_philo *philo)
{
	int	i;
	t_param	*param;
	long long	now;

	param = philo->param;
	// eat_time == 0 //이건 밖에서 체크하기
	while (1)
	{
			i = 0;
			while (i < param->philos)
			{
				now = get_now();
				if (now - philo[i].last_eat_time > param->life_time)
				{
					philo->param->die_state = 1;
					print_state(&philo[i], DIED);
					return (1);
				}
				++i;
			}
			if (check_must_eat(param, philo, param->philos, param->must_eat))
				return (1);
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
		++i;
	}
	i = 0;
	if (check_die_state(philo))
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