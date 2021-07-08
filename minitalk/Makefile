# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daypark <daypark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 16:37:08 by daypark           #+#    #+#              #
#    Updated: 2021/07/08 16:19:20 by daypark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
NAME_S = server
SRCS_S = server.c utils.c
OBJS_S = $(SRCS_S:.c=.o)
NAME_C = client
SRCS_C = client.c utils.c
OBJS_C = $(SRCS_C:.c=.o)
CC = gcc
CFLAGS = -Wextra -Wall -Werror

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(NAME_S) $(NAME_C)

$(NAME_S) : $(OBJS_S)
	$(CC) -o $@ $^

$(NAME_C) : $(OBJS_C)
	$(CC) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^

clean :
	rm -f $(OBJS_S) $(OBJS_C)

fclean : clean
	rm -f $(NAME_S) $(NAME_C)

re : fclean all
