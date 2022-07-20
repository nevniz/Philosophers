/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llawrenc <llawrenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:53:47 by llawrenc          #+#    #+#             */
/*   Updated: 2022/03/31 11:00:58 by llawrenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	run_threads(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philo)
	{
		philo->data->start = current_time();
		usleep(100);
		pthread_create(&philo[i].thread_id, NULL, (void *)eat, &philo[i]);
	}
	i = -1;
	while (++i < data->number_of_philo)
		pthread_join(philo[i].thread_id, NULL);
	return (0);
}

void	eat(t_philo *philo)
{
	philo->last_meal = current_time();
	pthread_create(&philo->death, NULL, (void *)death, philo);
	for_printf(philo->data, timestamp(philo), philo->pid, THINK);
	while (philo->data->death_flag == 1 && philo->pe != philo->data->must_eat)
	{
		pthread_mutex_lock(&philo->data->fork[philo->left_fork]);
		for_printf(philo->data, timestamp(philo), philo->pid, FORK);
		if (philo->data->number_of_philo == 1)
			break ;
		pthread_mutex_lock(&philo->data->fork[philo->right_fork]);
		for_printf(philo->data, timestamp(philo), philo->pid, FORK);
		for_printf(philo->data, timestamp(philo), philo->pid, EAT);
		philo->pe++;
		philo->last_meal = current_time();
		for_usleep(philo->data->time_to_eat);
		pthread_mutex_unlock(&philo->data->fork[philo->left_fork]);
		pthread_mutex_unlock(&philo->data->fork[philo->right_fork]);
		for_printf(philo->data, timestamp(philo), philo->pid, SLEEP);
		for_usleep(philo->data->time_to_sleep);
		for_printf(philo->data, timestamp(philo), philo->pid, THINK);
	}
	pthread_join(philo->death, NULL);
}

void	death(t_philo *philo)
{
	while (philo->data->death_flag && philo->pe != philo->data->must_eat)
	{
		usleep(100);
		pthread_mutex_lock(&philo->data->dead);
		if (philo->data->time_to_die < current_time() - philo->last_meal)
		{
			for_printf(philo->data, timestamp(philo), philo->pid, DEAD);
			philo->data->death_flag = 0;
		}
		pthread_mutex_unlock(&philo->data->dead);
	}
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_data	data;

	philo = NULL;
	if (arg_check(argc, argv) < 0)
		return (-1);
	if (init_arg(&data, argv) < 0)
		return (-1);
	philo = malloc(sizeof(*philo) * data.number_of_philo);
	if (!philo)
	{
		for_free(philo, &data, 0);
		return (print_error(2));
	}
	init_philo(philo, &data);
	run_threads(&data, philo);
	for_free(philo, &data, 1);
	return (0);
}
