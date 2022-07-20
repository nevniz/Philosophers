/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llawrenc <llawrenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:23:17 by llawrenc          #+#    #+#             */
/*   Updated: 2022/04/15 15:24:48 by llawrenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	ft_atoi(const char *n)
{
	long	num;
	int		i;

	i = -1;
	num = 0;
	if (!n)
		return (0);
	while (n[++i])
	{
		num = num * 10 + n[i] - '0';
		if (num > 2147483647 || num < 1)
			return (-1);
	}
	return (num);
}

int	arg_check(int argc, char **argv)
{
	int	i;
	int	j;

	j = 1;
	if (argc < 5 || argc > 6)
		return (print_error(1));
	while (argv[j])
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			if (argv[j][i] < '0' || argv[j][i] > '9' || ft_atoi(argv[j]) == -1)
				return (print_error(3));
			i++;
		}
		j++;
	}
	if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[2]) < 60
		|| ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
		return (print_error(1));
	if (argv[5] && !ft_atoi(argv[5]))
		return (print_error(3));
	return (1);
}
