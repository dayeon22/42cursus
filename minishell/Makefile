# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daypark <daypark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 10:19:18 by jawpark           #+#    #+#              #
#    Updated: 2021/12/27 13:44:55 by daypark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_builtin_1.c \
		ft_cd_1.c \
		ft_cd_2.c \
		ft_cd_redir_1.c \
		ft_check_1.c \
		ft_cmd_1.c \
		ft_cmd_2.c \
		ft_cmd_3.c \
		ft_dless_1.c \
		ft_dollar_1.c \
		ft_dollar_2.c \
		ft_echo_1.c \
		ft_echo_redir_1.c \
		ft_env_1.c \
		ft_error_1.c \
		ft_exit_1.c \
		ft_exit_2.c \
		ft_exit_redir_1.c \
		ft_export_1.c \
		ft_export_2.c \
		ft_free_1.c \
		ft_great_1.c \
		ft_less_1.c \
		ft_pipe_1.c \
		ft_pwd_1.c \
		ft_pwd_redir_1.c \
		ft_readline_1.c \
		ft_redir_1.c \
		ft_redir_2.c \
		ft_shlvl_1.c \
		ft_signal_1.c \
		ft_signal_2.c \
		ft_signal_3.c \
		ft_split_code_1.c \
		ft_split_code_2.c \
		ft_unset_1.c \
		ft_utils_1.c \
		ft_utils_2.c \
		ft_utils_3.c \
		ft_utils_4.c \
		main.c
SRC_B=	ft_builtin_1_bonus.c \
		ft_cd_1_bonus.c \
		ft_cd_2_bonus.c \
		ft_cd_redir_1_bonus.c \
		ft_check_1_bonus.c \
		ft_cmd_1_bonus.c \
		ft_cmd_2_bonus.c \
		ft_cmd_3_bonus.c \
		ft_dless_1_bonus.c \
		ft_dollar_1_bonus.c \
		ft_dollar_2_bonus.c \
		ft_echo_1_bonus.c \
		ft_echo_redir_1_bonus.c \
		ft_env_1_bonus.c \
		ft_error_1_bonus.c \
		ft_exit_1_bonus.c \
		ft_exit_2_bonus.c \
		ft_exit_redir_1_bonus.c \
		ft_export_1_bonus.c \
		ft_export_2_bonus.c \
		ft_free_1_bonus.c \
		ft_great_1_bonus.c \
		ft_less_1_bonus.c \
		ft_pipe_1_bonus.c \
		ft_pwd_1_bonus.c \
		ft_pwd_redir_1_bonus.c \
		ft_readline_1_bonus.c \
		ft_redir_1_bonus.c \
		ft_redir_2_bonus.c \
		ft_shlvl_1_bonus.c \
		ft_signal_1_bonus.c \
		ft_signal_2_bonus.c \
		ft_signal_3_bonus.c \
		ft_split_code_1_bonus.c \
		ft_split_code_2_bonus.c \
		ft_unset_1_bonus.c \
		ft_utils_1_bonus.c \
		ft_utils_2_bonus.c \
		ft_utils_3_bonus.c \
		ft_utils_4_bonus.c \
		main_bonus.c
OBJ =	$(SRC:.c=.o)
OBJ_B =	$(SRC_B:.c=.o)

D_SRC =	src
D_OBJ =	obj
D_SRC_B = bonus
D_OBJ_B = obj_b

SRCS =	$(addprefix $(D_SRC)/,$(SRC))
OBJS =	$(addprefix $(D_OBJ)/, $(OBJ))
SRCS_B =	$(addprefix $(D_SRC_B)/, $(SRC_B))
OBJS_B =	$(addprefix $(D_OBJ_B)/, $(OBJ_B))

CC = gcc
CFLAGS = -Wextra -Wall -Werror

NAME = minishell
NAME_B = minishell_bonus

LIBS = -lreadline
INCS = -I include -I libft

LIBS += -L /opt/homebrew/opt/readline/lib
INCS += -I /opt/homebrew/opt/readline/include

D_LIBFT = libft
LIBFTL = libft.a

all : $(NAME)

bonus : $(NAME_B)

$(NAME) : $(D_LIBFT)/$(LIBFTL) $(D_OBJ) $(OBJS)
	$(CC) $(CFLAGS) $(D_LIBFT)/$(LIBFTL) $(OBJS) $(LIBS) -o $@

$(NAME_B) : $(D_LIBFT)/$(LIBFTL) $(D_OBJ_B) $(OBJS_B)
	$(CC) $(CFLAGS) $(D_LIBFT)/$(LIBFTL) $(OBJS_B) $(LIBS) -o $@

$(D_LIBFT)/$(LIBFTL) : $(D_LIBFT)
	make all -C $(D_LIBFT)/

$(D_OBJ) :
	mkdir $@

$(D_OBJ_B) :
	mkdir $@

$(D_OBJ)/%.o : $(D_SRC)/%.c
	$(CC) $(CFLAGS) -c $(INCS) $< -o $@

$(D_OBJ_B)/%.o : $(D_SRC_B)/%.c
	$(CC) $(CFLAGS) -c $(INCS) $< -o $@

clean :
	rm -rf $(D_OBJ)
	rm -rf $(D_OBJ_B)
	make clean -C $(D_LIBFT)

fclean : clean
	rm -f $(NAME)
	rm -f $(NAME_B)
	rm -f $(D_LIBFT)/$(LIBFTL)

re : fclean all

.PHONY : all clean fclean re bonus
