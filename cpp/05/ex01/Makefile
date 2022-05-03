# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/02 02:43:28 by daypark           #+#    #+#              #
#    Updated: 2022/05/02 02:44:00 by daypark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat
SRCS = main.cpp Bureaucrat.cpp
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
