NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

SRC = \
$(SRC_DIR)/main.c \
$(SRC_DIR)/parse/parse_main.c \
$(SRC_DIR)/parse/parse_utils.c \
$(SRC_DIR)/operations/op_push.c \
$(SRC_DIR)/operations/op_swap.c \
$(SRC_DIR)/operations/op_rotate.c \
$(SRC_DIR)/operations/op_rev_rotate.c \
$(SRC_DIR)/sort/sort_dispatch.c \
$(SRC_DIR)/sort/sort_medium.c \
$(SRC_DIR)/sort/sorting.c \
$(SRC_DIR)/sort/sort_utils.c \
$(SRC_DIR)/sort/sort_complex_utils.c \
$(SRC_DIR)/utils/error.c \
$(SRC_DIR)/stack/add_back.c \
$(SRC_DIR)/stack/add_front.c \
$(SRC_DIR)/stack/last_node.c \
$(SRC_DIR)/stack/new_node.c \
$(SRC_DIR)/stack/size_node.c


OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) -lm

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re