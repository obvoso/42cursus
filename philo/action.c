/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:59:55 by soo               #+#    #+#             */
/*   Updated: 2022/09/21 22:00:24 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_finish(t_arg arg)
{
	int	i;

	//while (!arg.finish) // 도시떼 와일문 도는 것?
	//{
		if (arg.param.eat_time == 0)
		{
			arg.finish = 1;
			return ;
		} //|| (arg.must_eat == arg.philo[0].eat_cnt))
		i = 0;
		while (i < arg.param.philos)
		{
			if(arg.philo[i].last_eat_time >= arg.param.eat_time)
			{
				print_state(arg, DIED, i);
				arg.finish = 1;
				return ;
			}
			++i;
		}
	//}
}

void	thinking(t_philo *philo)
{
	print_state(philo, THINKING);
}

void	sleeping(t_philo *philo)
{
	long long	start;

	start = get_now();
	print_state(philo, SLEEPING);
	throw_time(start, philo->param->sleep_time);
}

void	eating(t_philo *philo)
{
	long long start;

	start = get_now();
	pthread_mutex_lock(&(philo->param->fork[philo->l_fork]));
	print_state(philo, TAKE);
	pthread_mutex_lock(&(philo->param->fork[philo->r_fork]));
	print_state(philo, TAKE);
	print_state(philo, EATING);
	pthread_mutex_unlock(&(philo->param->fork[philo->l_fork]));
	pthread_mutex_unlock(&(philo->param->fork[philo->r_fork]));
	// arg->param.eat_check[arg->idx] = EAT; // 어캐쓰노
	++philo->eat_cnt;
	throw_time(start, philo->param->eat_time);
}

void	threading(void *p_philo)
{
	t_philo *philo;

	philo = (t_philo *)p_philo;
	while (1)
	{
		if (philo->num % 2 == 0)
			usleep(50);
		eating(philo);
		sleeping(philo);
		tinking(philo);
	}
}