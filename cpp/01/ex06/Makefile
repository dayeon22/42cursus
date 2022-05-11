# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daypark <daypark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 15:35:32 by daypark           #+#    #+#              #
#    Updated: 2022/05/11 17:03:16 by daypark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harlFilter
SRCS = main.cpp Harl.cpp
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
