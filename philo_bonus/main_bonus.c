/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llawrenc <llawrenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:09:43 by llawrenc          #+#    #+#             */
/*   Updated: 2022/04/19 17:06:44 by llawrenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	dead(t_data *data)
{
	while (1)
	{
		usleep(100);
		if (current_time() - data->last_meal > data->time_to_die)
		{
			data->f = 1;
			sem_wait(data->print);
			printf("%lli %i %s\n", current_time() - data->start,
				data->pid, DEAD);
			data->stop = 1;
			break ;
		}
		if (data->must_eat != -1 && data->pe >= data->must_eat)
		{
			data->stop = 1;
			break ;
		}
	}
	if (data->f)
		exit(1);
	else
		exit(0);
}

void	eat(t_data *data)
{
	pthread_create(&data->death, NULL, (void *)dead, data);
	while (1)
	{
		for_printf(data, data->pid, THINK);
		sem_wait(data->fork);
		for_printf(data, data->pid, FORK);
		sem_wait(data->fork);
		for_printf(data, data->pid, FORK);
		for_printf(data, data->pid, EAT);
		for_usleep(data, data->time_to_eat);
		data->last_meal = current_time();
		sem_post(data->fork);
		sem_post(data->fork);
		data->pe += 1;
		for_printf(data, data->pid, SLEEP);
		for_usleep(data, data->time_to_sleep);
	}
	pthread_join(data->death, NULL);
}

int	run_threads(t_data *data)
{
	int	i;

	i = -1;
	data->start = current_time();
	while (++i < data->number_of_philo)
	{
		data->f_philo[i] = fork();
		if (data->f_philo[i] == -1)
			return (print_error(5));
		if (data->f_philo[i] == 0)
		{
			data->pid = i + 1;
			data->last_meal = current_time();
			eat(data);
		}
	}
	for_exit(data);
	return (1);
}

int	init_arg(t_data *data, char **argv)
{
	data->number_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		data->must_eat = ft_atoi(argv[5]);
	else
		data->must_eat = -1;
	data->f = 0;
	data->stop = 0;
	data->pe = 0;
	data->f_philo = malloc(sizeof(pid_t) * data->number_of_philo);
	if (!data->f_philo)
		return (print_error(2));
	sem_unlink(SEM_FORK);
	data->fork = sem_open(SEM_FORK, O_CREAT, 0644, data->number_of_philo);
	sem_unlink(SEM_PRINT);
	data->print = sem_open(SEM_PRINT, O_CREAT, 0644, 1);
	if (data->fork == SEM_FAILED || data->print == SEM_FAILED)
		return (print_error(4));
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	memset(&data, 0, sizeof(t_data));
	if (arg_check(argc, argv) < 0)
		return (-1);
	if (init_arg(&data, argv) < 0)
		return (-1);
	if (run_threads(&data) < 0)
		return (-1);
	return (0);
}
