/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:55:33 by soo               #+#    #+#             */
/*   Updated: 2022/10/07 17:57:27 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putendl(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		write(1, s, 1);
		++s;
	}
	write(1, "\n", 1);
}

static void	putnbr_recur(long long nb)
{
	char	c;

	if (nb > 9)
		putnbr_recur(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
}

void	ft_putnbr(long long nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	putnbr_recur(nb);
	write(1, " ", 1);
}

int	print_state(t_philo *philo, t_param *param, char *state, int flag)
{
	if (flag == EAT)
	{
		pthread_mutex_lock(param->check);
		philo->last_eat_time = get_now();
		philo->eat_cnt++;
		pthread_mutex_unlock(param->check);
	}
	else if (flag == FORK)
	{
		pthread_mutex_lock(param->check);
		philo->last_eat_time = get_now();
		pthread_mutex_unlock(param->check);
	}
	if (!param->print)
		return (1);
	pthread_mutex_lock(param->print);
	if (check_die_mutex(param))
		return (1);
	ft_putnbr(time_watch(param->start));
	ft_putnbr(philo->num + 1);
	ft_putendl(state);
	pthread_mutex_unlock(param->print);
	return (0);
}
