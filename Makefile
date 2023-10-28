# Target and Source Files
NAME = philo

SRCS =	src/main.c \
		src/main/utils/utils.c

# Source Directories
VPATH =	src: \
		src/utils: \

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread

OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/,$(notdir $(SRCS:.c=.o)))

# Clean
RM = rm -rf

# Colors for Terminal Output
COLOR_RED = \e[0;31m
COLOR_GREEN = \e[0;32m
COLOR_PURPLE = \e[0;35m
COLOR_WHITE = \e[0;37m

# Default Target
all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Clean Targets
clean:
	@printf "$(COLOR_RED)Cleaning $(COLOR_PURPLE)$(NAME)$(COLOR_WHITE) objects...\n"
	$(RM) $(OBJ_DIR)
	@printf "$(COLOR_GREEN)Done!\n$(COLOR_WHITE)"

fclean: clean
	@printf "$(COLOR_RED)Cleaning $(COLOR_PURPLE)$(NAME)\n$(COLOR_WHITE)"
	$(RM) $(NAME)
	@printf "$(COLOR_GREEN)Done!\n$(COLOR_WHITE)"

# Rebuild Target
re: fclean all

# Additional Targets
norma:
	@clear
	@norminette $(INC_PATH) $(SRC_PATH) | grep Error || true

leak:
	valgrind -q --leak-check=full --show-leak-kinds=all --trace-children=yes \
	./philo

.PHONY: all clean fclean re libft
