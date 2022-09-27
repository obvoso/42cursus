/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:21:44 by soo               #+#    #+#             */
/*   Updated: 2022/09/27 22:03:14 by soo              ###   ########.fr       */
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

int	check_must_eat(t_param *param, t_philo *philo, int philos, int must_eat)
{
	int	i;
	int	cnt;
	int eat_cnt_tmp;

	i = 0;
	cnt = 0;
	if (must_eat)
	{
		while (i < philos)
		{
			pthread_mutex_lock(param->check);
			eat_cnt_tmp = philo[i].eat_cnt;
			pthread_mutex_unlock(param->check);
			if (eat_cnt_tmp < must_eat)
				return (0);
			++i;
		}
		pthread_mutex_lock(param->state);
		philo->param->die_state = DIE;
		pthread_mutex_unlock(param->state);
		pthread_mutex_lock(param->print);
		ft_putendl(FINISH);
		pthread_mutex_unlock(param->print);
		return (1);
	}
	return (0);
}

int	check_die_state(t_philo *philo)
{
	int			i;
	long long	last_eat_tmp;
	t_param		*param;
	long long	now;

	param = philo->param;
	while (1)
	{
		i = 0;
		while (i < param->philos)
		{
			now = get_now();
			pthread_mutex_lock(param->last_eat);
			last_eat_tmp = philo[i].last_eat_time;
			pthread_mutex_unlock(param->last_eat);
			if (now - last_eat_tmp > param->life_time)
			{
				print_state(&philo[i], DIED);
				pthread_mutex_lock(param->state);
				philo->param->die_state = DIE;
				pthread_mutex_unlock(param->state);
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
		if (pthread_create(&(philo[i].tid), NULL, threading, \
			(void *)&(philo[i])) != 0)
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
	free_all(param, &philo);
	return (0);
}
