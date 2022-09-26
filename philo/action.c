/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:59:55 by soo               #+#    #+#             */
/*   Updated: 2022/09/26 15:57:24 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	check_finish(t_philo *philo)
// {
// 	int	i;
// 	t_param	*param;

// 	param = philo->param;
// 	// eat_time == 0 //이건 밖에서 체크하기
// 	i = 0;
// 	// while (i < param->philos)
// 	// {
// 	// 	if (philo[i].state == FIN || philo[i].state == DIE)
// 	// 		return (1);
// 	// 	++i;
// 	// }
// 	if (param->must_eat && param->must_eat == philo->eat_cnt)
// 	{
// 		write(1, "?????\n", 6);
// 		philo->state = FIN;
// 		print_state(philo, FINISH);
// 		return (1);
// 	}
// 	if (get_now() - philo->last_eat_time >= param->life_time)
// 	{
// 		write(1, "?????\n", 6);
// 		philo->state = DIE;
// 		print_state(philo, DIED);
// 		return (1);
// 	}
// 	return (0);
// }

void	thinking(t_philo *philo)
{
	t_param	*param;

	param = philo->param;
	if (param->die_state)
		return ;
	print_state(philo, THINKING);
	//param->eat_check[philo->num] = HUNGRY;
	}

void	sleeping(t_philo *philo)
{
	long long	start;
	t_param		*param;

	start = get_now();
	param = philo->param;
	if (param->die_state)
		return ;
	print_state(philo, SLEEPING);
	throw_time(philo, start, param->sleep_time);
}

void	eating(t_philo *philo)
{
	long long	start;
	t_param		*param;

	param = philo->param;
	if (param->die_state)
		return ;
	//if (param->eat_check[philo->num] == HUNGRY)
	//{
		pthread_mutex_lock(&(param->fork[philo->l_fork]));
		pthread_mutex_lock(&(param->fork[philo->r_fork]));
		param->eat_check[philo->num] = FULL;
		start = get_now();
		print_state(philo, TAKE);
		print_state(philo, TAKE);
		print_state(philo, EATING);
		philo->last_eat_time = get_now();
		philo->eat_cnt++;
		//param->eat_check[philo->num] = FULL;
		throw_time(philo, start, param->eat_time);
		if (philo->num + 1 == param->philos) // 내가 마지막 필로면 첫번째 필로 배고프다
			param->eat_check[0] = HUNGRY;
		else
		 	param->eat_check[philo->num + 1] = HUNGRY; // 아니면 내 다음 필로가 배고프다
		pthread_mutex_unlock(&(param->fork[philo->l_fork]));
		pthread_mutex_unlock(&(param->fork[philo->r_fork]));
	//}
}

void	*threading(void *p_philo)
{
	t_philo *philo;
	t_param *param;

	philo = (t_philo *)p_philo;
	param = philo->param;
	
	while (!param->die_state)
	{
		//if (philo->num % 2 == 0)
		//	usleep(500);
		if (!param->eat_check[philo->num])//배고픈 인덱스 먼저 먹이기(짝수)
		{
			eating(philo);
			sleeping(philo);
			thinking(philo);
		}
		usleep(500);
		
	}
	return (NULL);
}