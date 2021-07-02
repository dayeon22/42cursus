# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daypark <daypark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 16:37:08 by daypark           #+#    #+#              #
#    Updated: 2021/07/02 14:32:04 by daypark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
NAME_S = server
SRCS_S = server.c utils.c
OBJS_S = $(SRCS_S:.c=.o)
NAME_C = client
SRCS_C = client.c utils.c
OBJS_C = $(SRCS_C:.c=.o)

B_NAME_S = server_bonus
B_SRCS_S = server_bonus.c utils_bonus.c
B_OBJS_S = $(B_SRCS_S:.c=.o)
B_NAME_C = client_bonus
B_SRCS_C = client_bonus.c utils_bonus.c
B_OBJS_C = $(B_SRCS_C:.c=.o)
	
CC = gcc
CFLAGS = -Wextra -Wall -Werror

.PHONY : all clean fclean re bonus

all : $(NAME)

$(NAME) : $(NAME_S) $(NAME_C)

$(NAME_S) : $(OBJS_S)
	$(CC) -o $@ $^

$(NAME_C) : $(OBJS_C)
	$(CC) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^

clean :
	rm -f $(OBJS_S) $(OBJS_C) $(B_OBJS_S) $(B_OBJS_C)

fclean : clean
	rm -f $(NAME_S) $(NAME_C) $(B_NAME_S) $(B_NAME_C)

re : fclean all

bonus : $(B_NAME_S) $(B_NAME_C)

$(B_NAME_S) : $(B_OBJS_S)
	$(CC) $(CFLAGS) -o $(NAME_S) $^

$(B_NAME_C) : $(B_OBJS_C)
	$(CC) $(CFLAGS) -o $(NAME_C) $^
