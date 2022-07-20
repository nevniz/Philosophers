/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llawrenc <llawrenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:09:40 by llawrenc          #+#    #+#             */
/*   Updated: 2022/04/18 18:29:40 by llawrenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdlib.h>
# include <fcntl.h>

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

# define SEM_PHILO "/philo"
# define SEM_FORK "/fork"
# define SEM_PRINT "/print"
# define SEM_DEAD "/dead"

typedef struct s_data
{
	pid_t			*f_philo;
	sem_t			*fork;
	sem_t			*print;
	pthread_t		death;
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				pe;
	int				stop;
	int				f;
	long long		start;
	int				pid;
	long long		last_meal;
}	t_data;

long		ft_atoi(const char *n);
int			arg_check(int argc, char **argv);
int			print_error(int num);
void		for_exit(t_data *data);
void		for_usleep(t_data *data, long long argv);
void		for_printf(t_data *data, int pid, char *str);
long long	current_time(void);

#endif
