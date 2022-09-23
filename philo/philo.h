/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:21:57 by soo               #+#    #+#             */
/*   Updated: 2022/09/23 21:11:51 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define TAKE "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DIED "died"
# define FINISH "finish"

# define INIT 0
# define STARVE 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIE 5
# define FIN 6

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct	s_param
{
	int	philos;
	int	life_time;
	int	eat_time;
	int	sleep_time;
	int	must_eat;
	int	*eat_check; // 어캐쓰노
	long long start;
	pthread_mutex_t	*print;
	pthread_mutex_t	*fork;
}	t_param;

typedef struct s_philo
{
	int	num;
	int	l_fork;
	int	r_fork;
	int	eat_cnt;
	int	state;
	long long	last_eat_time; // 마지막으로 먹는데 걸린 시간
	pthread_t	tid;
	t_param *param;
}	t_philo;

//init
t_param	*args_parse(t_param *param, char **argv, int argc);
t_param *init_param(t_param *param);
t_philo *init_philo(t_philo *philo, t_param *param);
int	ft_atoi(const char *str);

//action
int	check_finish(t_philo *philo);
void	thinking(t_philo *philo);
void	sleeping(t_philo *philo);
void	eating(t_philo *philo);
void	*threading(void *p_philo);

//print
void	ft_putendl(char *s);
void	ft_putnbr(long long nb);
void print_state(t_philo *philo, char *state);

//time
long long	get_now(void);
long long	time_watch(long long start);
void	throw_time(long long start, long long end);

#endif