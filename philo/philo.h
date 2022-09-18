/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:21:57 by soo               #+#    #+#             */
/*   Updated: 2022/09/19 00:07:08 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define INIT 0;
# define EAT 2;
# define SLEEP 3;
# define THINK 4;
# define DIE 5;

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct	s_param
{
	int	philos;
	int	life_time;
	int	eat_time;
	int	sleep_time;
	int	must_eat;
	int	*order;
	pthread_mutex_t	*print;
	pthread_mutex_t	*fork;
}	t_param;

typedef struct s_philo
{
	int	num;
	int	state;
	int	l_fork;
	int	r_fork;
}	t_philo;

typedef struct s_arg
{
	int		idx;
	t_param *param;
	t_philo *philo;
} t_arg;
#endif