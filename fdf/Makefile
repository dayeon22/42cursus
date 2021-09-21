# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/23 16:59:11 by daypark           #+#    #+#              #
#    Updated: 2021/09/22 02:40:56 by daypark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

M_NAME = fdf
M_DIR = mandatory
M_SRCS = $(M_DIR)/main.c $(M_DIR)/read_map.c $(M_DIR)/draw1.c \
		 $(M_DIR)/draw2.c $(M_DIR)/utils.c
M_OBJS = $(M_SRCS:.c=.o)

B_NAME = fdf_bonus
B_DIR = bonus
B_SRCS = $(B_DIR)/main_bonus.c $(B_DIR)/read_map_bonus.c $(B_DIR)/draw1_bonus.c \
		 $(B_DIR)/draw2_bonus.c $(B_DIR)/utils_bonus.c
B_OBJS = $(B_SRCS:.c=.o)

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

.PHONY : all
all : $(M_NAME)

$(M_NAME) : $(M_OBJS) $(LIBFTL) $(MLXL)
	$(CC) $(LIB)/$(LIBFT)/$(LIBFTL) $(LIB)/$(MLX)/$(MLXL) \
		$(M_OBJS) $(LFLAGS) -o $@

.PHONY : bonus
bonus : $(B_NAME)

$(B_NAME) : $(B_OBJS) $(LIBFTL) $(MLXL)
	$(CC) $(LIB)/$(LIBFT)/$(LIBFTL) $(LIB)/$(MLX)/$(MLXL) \
		$(B_OBJS) $(LFLAGS) -o $@

$(LIBFTL) :
	make all -C $(LIB)/$(LIBFT)

$(MLXL) :
	make all -C $(LIB)/$(MLX)

$(M_DIR)%.o : $(M_DIR)%.c
	$(CC) $(CFLAGS) -c $^

$(B_DIR)%.o : $(B_DIR)%.c
	$(CC) $(CFLAGS) -c $^

.PHONY : clean
clean :
	rm -f $(M_OBJS)
	rm -f $(B_OBJS)
	make clean -C $(LIB)/$(LIBFT)/
	make clean -C $(LIB)/$(MLX)/

.PHONY : fclean
fclean : clean
	rm -f $(M_NAME)
	rm -f $(B_NAME)
	rm -f $(LIB)/$(LIBFT)/$(LIBFTL)
	rm -f $(LIB)/$(MLX)/$(MLXL)

.PHONY : re
re : fclean all
