/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llawrenc <llawrenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 20:07:58 by llawrenc          #+#    #+#             */
/*   Updated: 2022/03/29 20:56:21 by llawrenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	data->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->number_of_philo);
	if (!data->fork)
		return (print_error(2));
	data->death_flag = 1;
	return (1);
}

int	init_philo(t_philo *philo, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philo)
	{
		philo[i].pid = i + 1;
		philo[i].pe = 0;
		philo[i].data = data;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % data->number_of_philo;
		pthread_mutex_init(&data->fork[i], NULL);
		pthread_mutex_init(&data->dead, NULL);
	}
	pthread_mutex_init(&data->print, NULL);
	return (1);
}
