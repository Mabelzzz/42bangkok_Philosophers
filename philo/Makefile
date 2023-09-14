NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE_DIR	= include
INCLUDES =	-I $(INCLUDE_DIR)

LIB = libft/ft_atoi.c \

SRCS =	srcs/check_die.c \
		srcs/get_time.c \
		srcs/mutex.c \
		srcs/input.c \
		srcs/philo.c \
		srcs/routine.c \
		srcs/utils.c \
		$(LIB)

M_OBJS = $(SRCS:.c=.o)

%o: %c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "\033[0;33mGenerating philosophers objects... %-10.10s\r" $@

all: $(NAME)
	@echo "\033[1;94m\n\nCompiling philosophers (with the mandatory)...\n"

$(NAME): $(M_OBJS)
	$(CC) $(CFLAGS) $(M_OBJS) -o $(NAME)

norm:
	norminette -R checkforbiddensourceheader $(SRCS)
	norminette -R checkdefine gnl/get_next_line.h
	norminette -R checkdefine includes/philo.h
	@echo "\033[0;32m\n\nNorminette (with all files)..."

clean:
	@rm -fr $(M_OBJS)

fclean: clean
	@rm -fr $(NAME)
	@rm -fr $(NAME).dSYM

re:	fclean all

.PHONY: all clean fclean norm re
