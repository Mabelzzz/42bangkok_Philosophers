NAME = philo
CC = gcc -g
CFLAGS = -Wextra -Wall -Werror

LIBS = -lpthread

INCLUDE_DIR	= .
INCLUDES =	-I$(INCLUDE_DIR)

SRC_DIR = srcs
SRCS =	main.c \
		routine.c \
		observer.c \
		start.c \
		utils/ft_atoi.c \
		utils/ph_activities.c \
		utils/ph_create.c \
		utils/ph_lstfree.c \
		utils/ph_print.c \
		utils/time.c \

BUILD_DIR = build

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

re: fclean all

clean:
	$(RM) -rf $(BUILD_DIR)

fclean: clean
	$(RM) -f $(NAME)

PHONY: all clean fclean re