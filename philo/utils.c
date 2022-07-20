/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llawrenc <llawrenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:44:15 by llawrenc          #+#    #+#             */
/*   Updated: 2022/03/31 10:18:08 by llawrenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	for_free(t_philo *philo, t_data *data, int flag)
{
	int	i;

	i = -1;
	if (flag == 1)
	{
		pthread_mutex_destroy(&data->print);
		pthread_mutex_destroy(&data->dead);
		while (++i < data->number_of_philo)
			pthread_mutex_destroy(&data->fork[i]);
	}
	else if (flag == 0)
	{
		free(philo->data->fork);
		free(philo);
	}
}

void	for_printf(t_data *data, long long time, int pid, char *str)
{
	pthread_mutex_lock(&data->print);
	if (data->death_flag)
		printf("%lli %i %s\n", time, pid, str);
	pthread_mutex_unlock(&data->print);
}

void	for_usleep(long long argv)
{
	long long	time;

	time = current_time();
	while (argv > current_time() - time)
		usleep(500);
}

long long	current_time(void)
{
	struct timeval	time;
	long long		ms;

	gettimeofday(&time, NULL);
	ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ms);
}

long long	timestamp(t_philo *philo)
{
	return (current_time() - philo->data->start);
}
