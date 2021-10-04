# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/25 19:49:02 by daypark           #+#    #+#              #
#    Updated: 2021/10/04 16:09:06 by daypark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = main.c utils.c stack_utils.c swap.c \
	   push.c rotate.c reverse_rotate.c sort.c
OBJS = $(SRCS:.c=.o)

LIBFT = libft
LIBFTL = libft.a

CC = gcc
CFLAGS = -Wextra -Wall -Werror

.PHONY : all
all : $(NAME)

$(NAME) : $(LIBFTL) $(OBJS)
	$(CC) $(CFLAGS) $(LIBFT)/$(LIBFTL) $(OBJS) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $^

$(LIBFTL) :
	make all -C $(LIBFT)/

.PNONY : clean
clean :
	rm -f $(OBJS)
	make clean -C $(LIBFT)/

.PHONY : fclean
fclean : clean
	rm -f $(NAME)
	rm -f $(LIBFT)/$(LIBFTL)

.PHONY : re
re : fclean all
