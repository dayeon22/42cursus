# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daypark <daypark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 15:13:17 by daypark           #+#    #+#              #
#    Updated: 2022/05/17 01:41:30 by daypark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animal
W_NAME = wrong
SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp
W_SRCS = wrongmain.cpp WrongAnimal.cpp WrongCat.cpp
OBJS = $(SRCS:.cpp=.o)
W_OBJS = $(W_SRCS:.cpp=.o)
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

.PHONY: all
all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) -o $@ $^

$(W_NAME) : $(W_OBJS)
	$(CC) $(FLAGS) -o $@ $^

%.o : %.c
	$(CC) $(FLAGS) -c $^

.PHONY: clean
clean :
	rm -f $(OBJS)
	rm -f $(W_OBJS)

.PHONY: fclean
fclean : clean
	rm -f $(NAME)
	rm -f $(W_NAME)

.PHONY: re
re : fclean all