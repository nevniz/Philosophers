/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llawrenc <llawrenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:26:00 by llawrenc          #+#    #+#             */
/*   Updated: 2022/04/15 15:38:49 by llawrenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	print_error(int num)
{
	if (num == 1)
		printf(HELP);
	else if (num == 2)
		printf("Malloc error!\n");
	else if (num == 3)
		printf("Incorrect arguments!\n");
	else if (num == 4)
		printf("Semaphore init error!\n");
	else if (num == 5)
		printf("Fork error!\n");
	return (-1);
}
