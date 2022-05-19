# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dayeon <daypark@student.42seoul.kr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 10:24:15 by dayeon            #+#    #+#              #
#    Updated: 2022/05/17 17:12:02 by dayeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert
SRCS = main.cpp convert.cpp
OBJS = $(SRCS:.cpp=.o)
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

.PHONY: all
all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) -o $@ $^

%.o : %.c
	$(CC) $(FLAGS) -c $^

.PHONY: clean
clean :
	rm -f $(OBJS)

.PHONY: fclean
fclean : clean
	rm -f $(NAME)

.PHONY: re
re : fclean all
