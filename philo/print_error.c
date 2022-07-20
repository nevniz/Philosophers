/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llawrenc <llawrenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:11:44 by llawrenc          #+#    #+#             */
/*   Updated: 2022/03/29 20:04:44 by llawrenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(int num)
{
	if (num == 1)
		printf(HELP);
	else if (num == 2)
		printf("Malloc error!\n");
	else if (num == 3)
		printf("Incorrect arguments!\n");
	return (-1);
}
