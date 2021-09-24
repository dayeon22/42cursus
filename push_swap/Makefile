NAME = push_swap
SRCS = main.c
OBJS = $(SRCS:.c=.o)

LIBFT = libft
LIBFTL = libft.a

CC = gcc
CFLAGS = -Wextra -Wall -Werror

.PHONY : all
all : $(NAME)

$(NAME) : $(LIBFTL) $(OBJS)
	$(CC) $(CFLAGS) $(LIBFT)/$(LIBFTL) $(OBJS) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $^

$(LIBFTL) :
	make all -C $(LIBFT)/

.PNONY : clean
clean :
	rm -f $(OBJS)
	make clean -C $(LIBFT)/

.PHONY : fclean
fclean : clean
	rm -f $(NAME)
	rm -f $(LIBFT)/$(LIBFTL)

.PHONY : re
re : fclean all
