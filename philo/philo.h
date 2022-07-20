/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llawrenc <llawrenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:41:29 by llawrenc          #+#    #+#             */
/*   Updated: 2022/03/31 07:34:53 by llawrenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>

# define HELP "Run with the following arguments: ./philo \e[34m[number_of_philosophers]\e[0m \e[34m[time_to_die]\e[0m \
\e[34m[time_to_eat]\e[0m \e[34m[time_to_sleep]\e[0m \
\n\e[35m[number_of_times_each_philosopher_must_eat].\e[0m\n\
\n1. \e[34mNumber_of_philosophers\e[0m: The number of philosophers and also the number of forks.\n\
2. \e[34mTime_to_die\e[0m (in milliseconds): If a philosopher didn’t start eating time_to_die\
 milliseconds since the \
\nbeginning nof their last meal or the beginning of the simulation, they die.\n\
3. \e[34mTime_to_eat\e[0m (in milliseconds): The time it takes for a philosopher to eat. \
During that time, they will \
\nneed to hold two forks.\n\
4. \e[34mTime_to_sleep\e[0m (in milliseconds): The time a philosopher will spend sleeping.\n\
5. \e[35mNumber_of_times_each_philosopher_must_eat\e[0m (optional argument): If all \
philosophers have eaten at least \
\nnumber_of_times_each_philosopher_must_eat \
times, the simulation stops. \
\nIf not specified, the simulation stops when a philosopher dies.\n"

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEAD "died"

typedef struct s_data
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	dead;
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	long long		start;
	int				death_flag;
}	t_data;

typedef struct s_philo
{
	pthread_t	thread_id;
	pthread_t	death;
	t_data		*data;
	long long	last_meal;
	int			pid;
	int			pe;
	int			left_fork;
	int			right_fork;
}	t_philo;

int			print_error(int num);
int			arg_check(int argc, char **argv);
int			init_arg(t_data *data, char **argv);
long long	current_time(void);
int			init_philo(t_philo *philo, t_data *data);
long long	timestamp(t_philo *philo);
void		for_usleep(long long argv);
void		for_printf(t_data *data, long long time, int pid, char *str);
int			run_threads(t_data *data, t_philo *philo);
void		eat(t_philo *philo);
void		for_free(t_philo *philo, t_data *data, int flag);
void		death(t_philo *philo);
long		ft_atoi(const char *n);

#endif
