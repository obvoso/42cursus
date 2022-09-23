/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:59:55 by soo               #+#    #+#             */
/*   Updated: 2022/09/23 21:39:37 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_finish(t_philo *philo)
{
	//int	i;

	//while (!arg.finish) // 도시떼 와일문 도는 것?
	//{
	// eat_time == 0 //이건 밖에서 체크하기
		if (philo->param->must_eat && philo->param->must_eat == philo->eat_cnt)
		{
			philo->state = FIN;
			print_state(philo, FINISH);
			return (1);
		}
		if (philo->last_eat_time >= philo->param->eat_time)
		{
			philo->state = DIE;
			print_state(philo, DIED);
			return (1);
		}
		// i = 0;
		// while (i < arg.param.philos)
		// {
		// 	if(arg.philo[i].last_eat_time >= arg.param.eat_time)
		// 	{
		// 		print_state(arg, DIED, i);
		// 		arg.finish = 1;
		// 		return ;
		// 	}
		// 	++i;
		// }
	//}
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
	throw_time(start, philo->param->sleep_time);
}

void	eating(t_philo *philo)
{
	long long start;

	if (check_finish(philo))
		return ;
	start = get_now();
	pthread_mutex_lock(&(philo->param->fork[philo->l_fork]));
	print_state(philo, TAKE);
	pthread_mutex_lock(&(philo->param->fork[philo->r_fork]));
	print_state(philo, TAKE);
	print_state(philo, EATING);
	philo->last_eat_time = time_watch(start); // 마지막으로 먹는 데 걸린 시간 저장
	//ft_putnbr(philo->last_eat_time);
	pthread_mutex_unlock(&(philo->param->fork[philo->l_fork]));
	pthread_mutex_unlock(&(philo->param->fork[philo->r_fork]));
	// arg->param.eat_check[arg->idx] = EAT; // 어캐쓰노
	philo->eat_cnt++;
	throw_time(start, philo->param->eat_time);
}

void	*threading(void *p_philo)
{
	t_philo *philo;

	philo = (t_philo *)p_philo;
	while (1)
	{
		if (check_finish(philo))
			break;
		if (philo->num % 2 == 0)
			usleep(500);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}