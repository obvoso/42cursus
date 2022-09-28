/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:59:55 by soo               #+#    #+#             */
/*   Updated: 2022/09/28 21:45:31 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_eat_check(t_param *param, t_philo *philo)
{
	pthread_mutex_lock(param->check);
	param->eat_check[philo->num] = FULL;
	if (philo->num == param->philos - 1)
		param->eat_check[0] = HUNGRY;
	else
		param->eat_check[philo->num + 1] = HUNGRY;
	pthread_mutex_unlock(param->check);
}

int	thinking(t_philo *philo)
{
	t_param	*param;

	param = philo->param;
	if (check_die_mutex(param))
		return (1);
	print_state(philo, THINKING);
	return (0);
}

int	sleeping(t_philo *philo)
{
	long long	start;
	t_param		*param;

	start = get_now();
	param = philo->param;
	if (check_die_mutex(param))
		return (1);
	print_state(philo, SLEEPING);
	throw_time(philo, start, param->sleep_time);
	return (0);
}

int	eating(t_philo *philo)
{
	long long	start;
	t_param		*param;

	param = philo->param;
	if (check_die_mutex(param))
		return (1);
	pthread_mutex_lock(&(param->fork[philo->l_fork]));
	pthread_mutex_lock(&(param->fork[philo->r_fork]));
	set_eat_check(param, philo);
	start = get_now();
	print_state(philo, TAKE);
	print_state(philo, TAKE);
	print_state(philo, EATING);
	pthread_mutex_lock(param->last_eat);
	philo->last_eat_time = get_now();
	pthread_mutex_unlock(param->last_eat);
	throw_time(philo, start, param->eat_time);
	philo->eat_cnt++; // 시간 지나고 체크할지 지나기 전에 체크할지 생각해보기...
	if (check_die_mutex(param))
		return (1);
	pthread_mutex_unlock(&(param->fork[philo->l_fork]));
	pthread_mutex_unlock(&(param->fork[philo->r_fork]));
	return (0);
}

void	*threading(void *p_philo)
{
	t_philo	*philo;
	t_param	*param;
	int		flag;

	philo = (t_philo *)p_philo;
	param = philo->param;
	while (1)
	{
		flag = check_threading_param(param, philo);
		if (flag == 2)
			return (NULL);
		if (!flag)
		{
			if (eating(philo))
				return (NULL);
			if (sleeping(philo))
				return (NULL);
			if (thinking(philo))
				return (NULL);
		}
		usleep(500);
	}
	return (NULL);
}
