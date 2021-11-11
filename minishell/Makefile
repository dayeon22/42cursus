SRC =	main.c ft_shlvl.c ft_signal.c \
		ft_readline.c ft_split_rl.c \
		ft_init.c ft_list_utils.c \
		ft_check_list.c ft_cmd_one.c \
		ft_cmd_two.c ft_error.c ft_builtin.c
SRCS =	$(addprefix src/,$(SRC))
OBJS =	$(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wextra -Wall -Werror

NAME = minishell

LIBS = -lreadline
INCS = -I include -I libft

# Cluster
#LIBS += -L $(HOME)/.brew/opt/readline/lib
#INCS += -I $(HOME)/.brew/opt/readline/include

# Local Mac
LIBS += -L /opt/homebrew/opt/readline/lib
INCS += -I /opt/homebrew/opt/readline/include

LIBFT = libft
LIBFTL = libft.a

all : $(NAME)

$(NAME) : $(LIBFT)/$(LIBFTL) $(OBJS)
	$(CC) $(CFLAGS) $(LIBFT)/$(LIBFTL) $(OBJS) $(LIBS) -o $@

$(LIBFT)/$(LIBFTL) :
	make all -C $(LIBFT)/

%.o : %.c
	$(CC) $(CFLAGS) -c $(INCS) $< -o $@

clean :
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	rm -f $(NAME)
	rm -f $(LIBFT)/$(LIBFTL)

re : fclean all

.PHONY : all clean fclean re
