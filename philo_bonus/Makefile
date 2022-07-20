# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llawrenc <llawrenc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 18:03:23 by llawrenc          #+#    #+#              #
#    Updated: 2022/04/14 18:06:59 by llawrenc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo_bonus
SRC		= main_bonus.c arg_check_bonus.c print_error_bonus.c utils_bonus.c
HEADER	= philo_bonus.h
OBJ		= $(SRC:%.c=%.o)
CFLAGS	= -pthread -Wall -Wextra -Werror -O2
CC		= gcc

.PHONY	: all clean fclean re

all		: $(NAME)

$(NAME)	: $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
%.o		: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	rm -f $(OBJ)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all