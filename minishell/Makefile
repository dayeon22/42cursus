SRC =	main.c ft_shlvl.c ft_signal.c ft_readline.c ft_command.c parse.c
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
