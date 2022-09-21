/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:21:57 by soo               #+#    #+#             */
/*   Updated: 2022/09/21 12:02:00 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define TAKE "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DIED "died"

# define INIT 0
# define STARVE 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIE 5

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
	int	*eat_check;
	pthread_mutex_t	*print;
	pthread_mutex_t	*fork;
}	t_param;

typedef struct s_philo
{
	int	num;
	int	l_fork;
	int	r_fork;
	int	eat_cnt;
}	t_philo;

typedef struct s_arg
{
	int		idx;
	t_param param;
	t_philo *philo;
} t_arg;

#endif