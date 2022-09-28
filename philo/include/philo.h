/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:21:57 by soo               #+#    #+#             */
/*   Updated: 2022/09/28 21:40:10 by soo              ###   ########.fr       */
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

# define HUNGRY 0
# define FULL 1
# define DIE 2

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_param
{
	int				philos;
	int				life_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat;
	int				*eat_check;
	int				die_state;
	long long		start;
	pthread_mutex_t	*last_eat;
	pthread_mutex_t	*check;
	pthread_mutex_t	*state;
	pthread_mutex_t	*print;
	pthread_mutex_t	*fork;
}	t_param;

typedef struct s_philo
{
	int			num;
	int			l_fork;
	int			r_fork;
	int			eat_cnt;
	long long	last_eat_time;
	pthread_t	tid;
	t_param		*param;
}	t_philo;

//init
t_param		*args_parse(t_param *param, char **argv, int argc);
int			make_mutex(t_param *param);
t_param		*init_param(t_param *param);
t_philo		*init_philo(t_philo *philo, t_param *param);
int			ft_atoi(const char *str);

//action
void		set_eat_check(t_param *param, t_philo *philo);
int			thinking(t_philo *philo);
int			sleeping(t_philo *philo);
int			eating(t_philo *philo);
void		*threading(void *p_philo);

//check
int			check_mutex(t_param *param);
int			check_die_mutex(t_param *param);
int			check_threading_param(t_param *param, t_philo *philo);

//print
void		ft_putendl(char *s);
void		ft_putnbr(long long nb);
void		print_state(t_philo *philo, char *state);

//time
long long	get_now(void);
long long	time_watch(long long start);
void		throw_time(t_philo *philo, long long start, int end);

//free
void		free_all(t_param param, t_philo **philo);

#endif