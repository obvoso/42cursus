/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:18:11 by soo               #+#    #+#             */
/*   Updated: 2022/09/18 17:35:56 by soo              ###   ########.fr       */
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
	param->must_eat = ft_atoi(argv[5]);
	if (param->must_eat < 1)
		return (NULL);
	return (param);
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
	if (ret > 2147483647 && sign == 1)
		return (-1);
	if (ret > 2147483648 && sign == -1)
		return (-1);
	return ((int)ret * sign);
}
