/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:59:55 by soo               #+#    #+#             */
/*   Updated: 2022/09/24 17:36:48 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_finish(t_philo *philo)
{
	int	i;
	t_param	*param;

	param = philo->param;
	// eat_time == 0 //이건 밖에서 체크하기
	i = 0;
	// while (i < param->philos)
	// {
	// 	if (philo[i].state == FIN || philo[i].state == DIE)
	// 		return (1);
	// 	++i;
	// }
	if (param->must_eat && param->must_eat == philo->eat_cnt)
	{
		philo->state = FIN;
		print_state(philo, FINISH);
		// write(1, "?", 1);
		return (1);
	}
	if (get_now() - philo->last_eat_time >= param->life_time)
	{
		philo->state = DIE;
		print_state(philo, DIED);
		// write(1, "?", 1);
		return (1);
	}
	return (0);
}

void	thinking(t_philo *philo)
{
	if (check_finish(philo))
		return ;
	print_state(philo, THINKING);
}

void	sleeping(t_philo *philo)
{
	long long	start;

	if (check_finish(philo))
		return ;
	start = get_now();
	print_state(philo, SLEEPING);
	throw_time(philo, start, philo->param->sleep_time);
}

void	eating(t_philo *philo)
{
	long long start;

	if (check_finish(philo))
	{
			write(1, "!", 1);
		return ;
	}
	pthread_mutex_lock(&(philo->param->fork[philo->l_fork]));
	pthread_mutex_lock(&(philo->param->fork[philo->r_fork]));
	start = get_now();
	print_state(philo, TAKE);
	print_state(philo, TAKE);
	print_state(philo, EATING);
	philo->eat_cnt++;
	throw_time(philo, start, philo->param->eat_time);
	philo->last_eat_time = get_now();
	pthread_mutex_unlock(&(philo->param->fork[philo->l_fork]));
	pthread_mutex_unlock(&(philo->param->fork[philo->r_fork]));
	// arg->param.eat_check[arg->idx] = EAT; // 어캐쓰노
}

void	*threading(void *p_philo)
{
	t_philo *philo;

	philo = (t_philo *)p_philo;
	while (!check_finish(philo))
	{
		if (philo->num % 2 == 0)
			usleep(500);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}