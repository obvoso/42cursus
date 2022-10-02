/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:21:44 by soo               #+#    #+#             */
/*   Updated: 2022/10/02 22:34:16 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_must_eat(t_param *param, t_philo *philo, int philos, int must_eat)
{
	int	i;

	i = 0;
	if (must_eat)
	{
		while (i < philos)
		{
			pthread_mutex_lock(param->check);
			if (philo[i].eat_cnt < must_eat)
			{
				pthread_mutex_unlock(param->check);
				return (0);
			}
			++i;
			pthread_mutex_unlock(param->check);
		}
		pthread_mutex_unlock(param->check);
		pthread_mutex_lock(param->print);
		ft_putendl(FINISH);
		pthread_mutex_lock(param->check);
		philo->param->die_state = DIE;
		pthread_mutex_unlock(param->check);
		return (1);
	}
	return (0);
}

int	check_life_time(t_param *param, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < param->philos)
	{
		usleep(10);
		pthread_mutex_lock(param->check);
		if (get_now() - philo[i].last_eat_time > param->life_time)
		{
			pthread_mutex_unlock(param->check);
			pthread_mutex_lock(param->print);
			ft_putnbr(time_watch(param->start));
			ft_putnbr(philo[i].num + 1);
			ft_putendl(DIED);
			pthread_mutex_lock(param->check);
			philo->param->die_state = DIE;
			pthread_mutex_unlock(param->check);
			return (1);
		}
		pthread_mutex_unlock(param->check);
		++i;
	}
	return (0);
}

int	check_fin_state(t_philo *philo)
{
	t_param		*param;

	param = philo->param;
	while (1)
	{
		usleep (200);
		if (check_life_time(param, philo))
			return (1);
		usleep(100);
		if (check_must_eat(param, philo, param->philos, param->must_eat))
			return (1);
	}
	return (0);
}

void	make_thread(t_philo *philo)
{
	int		i;
	t_param	*param;

	i = 0;
	while (i < philo[0].param->philos)
	{
		if (pthread_create(&(philo[i].tid), NULL, threading, \
			(void *)&(philo[i])) != 0)
			return ;
		usleep(100);
		++i;
	}
	i = 0;
	param = philo->param;
	if (check_fin_state(philo))
	{
		usleep(1000);
		while (i < param->philos)
		{
			pthread_detach(philo[i++].tid);
			usleep(100);
		}
		return ;
	}
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_param	param;

	if (argc != 5 && argc != 6)
	{
		write(2, "error\n", 6);
		return (1);
	}
	memset(&param, 0, sizeof(t_param));
	if (!args_parse(&param, argv, argc) || !init_param(&param))
	{
		write(2, "error\n", 6);
		return (1);
	}
	philo = (t_philo *)malloc(sizeof(t_philo) * param.philos);
	init_philo(philo, &param);
	make_thread(philo);
	return (0);
}
