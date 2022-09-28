/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:55:33 by soo               #+#    #+#             */
/*   Updated: 2022/09/28 22:02:13 by soo              ###   ########.fr       */
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

void	print_state(t_philo *philo, char *state)
{
	t_param	*param;

	param = philo->param;
	if (!check_mutex(param))
		return ;
	pthread_mutex_lock(param->state);
	if (param->die_state)
		return ;
	pthread_mutex_unlock(param->state);
	pthread_mutex_lock(param->print);
	ft_putnbr(time_watch(param->start));
	ft_putnbr(philo->num + 1);
	ft_putendl(state);
	pthread_mutex_unlock(param->print);
}
