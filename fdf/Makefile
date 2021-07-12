# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/09 11:17:58 by daypark           #+#    #+#              #
#    Updated: 2021/07/09 12:10:41 by daypark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS = get_next_line.c read_map.c
OBJS = $(SRCS:.c=.o)
LIBFT = libft
LIBFTL = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
AFLAGS = rcs

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	$(CC) -o $(NAME) $(OBJS) $(LIBFT)/$(LIBFTL)
#	cp $(LIBFT)/$(LIBFTL) $(NAME)
#	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLGS) -c $^

clean :
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	rm -f $(NAME)
	rm -f $(LIBFT)/$(LIBFTL)

re : fclean all
