# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 15:42:19 by daypark           #+#    #+#              #
#    Updated: 2021/10/05 16:47:26 by daypark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS = main.c utils.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wextra -Wall -Werror -pthread

.PHONY : all
all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $^

.PHONY : clean
clean :
	rm -f $(OBJS)

.PHONY : fclean
fclean : clean
	rm -f $(NAME)

.PHONY : re
re : fclean all
