NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iincludes
SRC_DIR = src
OBJ_DIR = obj

SRC = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/parse/parse_main.c \
	$(SRC_DIR)/parse/parse_utils.c \
	$(SRC_DIR)/sort/sort_complex_utils.c \
	$(SRC_DIR)/sort/sort_complex.c \
	$(SRC_DIR)/sort/sort_dispatch.c \
	$(SRC_DIR)/sort/sort_medium.c \
	$(SRC_DIR)/sort/sort_simple_and_small.c \
	$(SRC_DIR)/operations/op_push.c \
	$(SRC_DIR)/operations/op_rev_rotate.c \
	$(SRC_DIR)/operations/op_rotate.c \
	$(SRC_DIR)/operations/op_swap.c \
	$(SRC_DIR)/utils/helper_functions.c \
	$(SRC_DIR)/utils/stack_operations.c \
	$(SRC_DIR)/utils/ft_split.c \
	$(SRC_DIR)/bench/bench_print.c\
	$(SRC_DIR)/bench/bench_utils.c
	
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INCLUDES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re