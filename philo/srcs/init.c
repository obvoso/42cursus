/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:44:13 by soo               #+#    #+#             */
/*   Updated: 2022/10/01 20:24:09 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_param	*args_parse(t_param *param, char **argv, int argc)
{
	param->philos = ft_atoi(argv[1]);
	if (param->philos < 1)
		return (NULL);
	param->life_time = ft_atoi(argv[2]);
	if (param->life_time < 1)
		return (NULL);
	param->eat_time = ft_atoi(argv[3]);
	if (param->eat_time < 1)
		return (NULL);
	param->sleep_time = ft_atoi(argv[4]);
	if (param->sleep_time < 1)
		return (NULL);
	if (argc == 6)
	{
		param->must_eat = ft_atoi(argv[5]);
		if (param->must_eat < 1)
			return (NULL);
	}
	return (param);
}

int	make_mutex(t_param *param)
{
	int	i;

	if (pthread_mutex_init(param->print, NULL))
		return (0);
	if (pthread_mutex_init(param->check, NULL))
		return (0);
	i = 0;
	while (i < param->philos)
		if (pthread_mutex_init(&(param->fork[i++]), NULL) != 0)
			return (0);
	return (1);
}

t_param	*init_param(t_param *param)
{
	param->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
					* param->philos);
	param->print = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	param->check = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!param->fork || !param->print || !param->check)
		return (NULL);
	if (!make_mutex(param))
		return (NULL);
	return (param);
}

t_philo	*init_philo(t_philo *philo, t_param *param)
{
	int	i;

	i = 0;
	param->start = get_now();
	while (i < param->philos)
	{
		philo[i].num = i;
		philo[i].l_fork = i;
		philo[i].r_fork = (i + 1) % param->philos;
		philo[i].eat_cnt = 0;
		philo[i].last_eat_time = get_now();
		philo[i].param = param;
		++i;
	}
	return (philo);
}

int	ft_atoi(const char *str)
{
	unsigned long long	ret;
	int					sign;

	ret = 0;
	sign = 1;
	if ((*str >= 9 && *str <= 13) || *str == ' ')
		return (-1);
	if (*str == '-' || *str == '+')
		return (-1);
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + *str - '0';
		++str;
	}
	if (*str)
		return (-1);
	if (ret > 2147483647 && sign == 1)
		return (-1);
	if (ret > 2147483648 && sign == -1)
		return (-1);
	return ((int)ret * sign);
}
