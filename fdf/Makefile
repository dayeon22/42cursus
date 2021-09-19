# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/23 16:59:11 by daypark           #+#    #+#              #
#    Updated: 2021/08/16 17:51:11 by daypark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS = main.c read_map.c draw1.c draw2.c
OBJS = $(SRCS:.c=.o)
LIB = lib
LIBFT = libft
LIBFTL = libft.a
MLX = mlx
MLXL = libmlx.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -L $(LIB)/mlx/ -lmlx -framework OpenGL -framework AppKit
AR = ar
AFLAGS = rcs

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFTL) $(MLXL)
	$(CC) $(LIB)/$(LIBFT)/$(LIBFTL) $(LIB)/$(MLX)/$(MLXL) $(OBJS) $(LFLAGS) -o $@

$(LIBFTL) :
	make all -C $(LIB)/$(LIBFT)

$(MLXL) :
	make all -C $(LIB)/$(MLX)

%.o : %.c
	$(CC) $(CFLAGS) -c $^

clean :
	rm -f $(OBJS)
	make clean -C $(LIB)/$(LIBFT)/
	make clean -C $(LIB)/$(MLX)/

fclean : clean
	rm -f $(NAME)
	rm -f $(LIB)/$(LIBFT)/$(LIBFTL)
	rm -f $(LIB)/$(MLX)/$(MLXL)

re : fclean all
