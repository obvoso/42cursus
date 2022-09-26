/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:21:57 by soo               #+#    #+#             */
/*   Updated: 2022/09/26 15:53:35 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//예외처리 에러메세지 출력하기!!!!!!!!!!!
//6번째 인자  make넣었는데 돌아감 좆됨 인자처리 다시하기!!!!!!
# define TAKE "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DIED "died"
# define FINISH "finish"

# define INIT 0

# define HUNGRY 0
# define FULL 1
# define SLEEP 2
# define THINK 3
# define DIE 4
# define FIN 5

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
	int	*eat_check; // 어캐쓰노 1이면 먹어라 0이면 먹음
	long long start;
	int	die_state;
	pthread_mutex_t	*print;
	pthread_mutex_t	*fork;
}	t_param;

typedef struct s_philo
{
	int	num; 
	int	l_fork;
	int	r_fork;
	int	eat_cnt;
	long long	last_eat_time;
	pthread_t	tid;
	t_param *param;
}	t_philo;


//init
t_param	*args_parse(t_param *param, char **argv, int argc);
t_param *init_param(t_param *param);
t_philo *init_philo(t_philo *philo, t_param *param);
int	ft_atoi(const char *str);

//action
//int	check_finish(t_philo *philo);
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
void	throw_time(t_philo *philo, long long start, int end);

#endif