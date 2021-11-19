SRC =	ft_builtin.c \
		ft_cd_one.c \
		ft_cd_two.c \
		ft_check_list.c \
		ft_cmd_one.c \
		ft_cmd_two.c \
		ft_dollar.c \
		ft_env.c \
		ft_error.c \
		ft_exit_one.c \
		ft_exit_two.c \
		ft_export.c \
		ft_free.c \
		ft_list_utils1.c \
		ft_list_utils2.c \
		ft_pwd.c \
		ft_readline.c \
		ft_shlvl.c \
		ft_signal.c \
		ft_split_rl.c \
		ft_split_utils.c \
		ft_unset.c \
		ft_utils_one.c \
		ft_utils.c \
		main.c
OBJ =	$(SRC:.c=.o)
D_SRC =	src
D_OBJ =	obj
SRCS =	$(addprefix $(D_SRC)/,$(SRC))
OBJS =	$(addprefix $(D_OBJ)/, $(OBJ))

CC = gcc
CFLAGS = -Wextra -Wall -Werror

NAME = minishell

LIBS = -lreadline
INCS = -I include -I libft

# For Cluster
#LIBS += -L $(HOME)/.brew/opt/readline/lib
#INCS += -I $(HOME)/.brew/opt/readline/include

# For Macbook
LIBS += -L /opt/homebrew/opt/readline/lib
INCS += -I /opt/homebrew/opt/readline/include

D_LIBFT = libft
LIBFTL = libft.a

all : $(NAME)

$(NAME) : $(D_LIBFT)/$(LIBFTL) $(D_OBJ) $(OBJS)
	$(CC) $(CFLAGS) $(D_LIBFT)/$(LIBFTL) $(OBJS) $(LIBS) -o $@

$(D_LIBFT)/$(LIBFTL) :
	make all -C $(D_LIBFT)/

$(D_OBJ) :
	mkdir $@

$(D_OBJ)/%.o : $(D_SRC)/%.c
	$(CC) $(CFLAGS) -c $(INCS) $< -o $@

clean :
	rm -rf $(D_OBJ)
	make clean -C $(D_LIBFT)

fclean : clean
	rm -f $(NAME)
	rm -f $(D_LIBFT)/$(LIBFTL)

re : fclean all

.PHONY : all clean fclean re
