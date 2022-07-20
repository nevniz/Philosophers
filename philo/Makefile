# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llawrenc <llawrenc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 20:21:49 by llawrenc          #+#    #+#              #
#    Updated: 2022/03/31 10:38:14 by llawrenc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
SRC		= main.c arg_check.c print_error.c initialization.c utils.c
HEADER	= philo.h
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