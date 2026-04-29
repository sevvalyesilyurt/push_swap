NAME = push_swap
BONUS = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iincludes
SRC_DIR = src
BONUS_DIR = bonus
OBJ_DIR = obj

SRC = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/parse/ft_split.c \
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

BONUS_SRC = \
	$(BONUS_DIR)/checker_main_bonus.c \
	$(BONUS_DIR)/checker_exec_bonus.c \
	$(BONUS_DIR)/checker_parse_bonus.c \
	$(BONUS_DIR)/checker_read_bonus.c \
	$(BONUS_DIR)/checker_utils_bonus.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJ = $(BONUS_SRC:$(BONUS_DIR)/%.c=$(OBJ_DIR)/bonus_%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INCLUDES) -lm

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/bonus_%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJ) $(OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(OBJ) -o $(BONUS) $(INCLUDES)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus