NAME = so_long

MLX_DIR = mlx
MLX = $(MLX_DIR)/libmlx.a

VALGRIND = valgrind --leak-check=full --track-origins=yes -q

SRC_DIR = src
OBJ_DIR = obj
PRE = pregame
IN = ingame

HEADERS = includes/so_long.h

INCLUDE_DIR = includes

SRC_FILES = main.c ft_utils.c ft_load_n_print_image.c \
			$(PRE)/ft_check_extension.c $(PRE)/ft_get_next_line_utils.c \
			$(PRE)/ft_get_next_line.c $(PRE)/ft_map_check.c \
			$(PRE)/ft_actions.c $(PRE)/ft_keys.c $(PRE)/ft_struct_enemy.c \
			$(PRE)/ft_open_n_read.c $(PRE)/ft_struct_exit_gate.c \
			$(PRE)/ft_struct_item.c $(PRE)/ft_struct_map.c \
			$(PRE)/ft_struct_mem.c $(PRE)/ft_struct_player.c \
			$(IN)/ft_enemy.c $(IN)/ft_enemy_movement.c \
			$(IN)/ft_end_game.c $(IN)/ft_game_loop.c \
			$(IN)/ft_game_start.c $(IN)/ft_ingame_checks.c \
			$(IN)/ft_item_animation.c $(IN)/ft_item.c \
			$(IN)/ft_player_animation.c $(IN)/ft_player.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS = -g3 -Wall -Werror -Wextra
CC = clang $(CFLAGS)
LIBFLAGS = -lXext -lX11 -lmlx
RM = rm -rf

all: $(NAME)

$(NAME): $(MLX) $(OBJ)
	$(CC)  $(OBJ) -L$(MLX_DIR) $(LIBFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(PRE)
	@mkdir -p $(OBJ_DIR)/$(IN)
	$(CC) -c -I$(INCLUDE_DIR) -o $@ $<

$(MLX):
	make -C $(MLX_DIR)

run: $(NAME)
	sudo ./$(NAME) maps/map.ber

leak: $(NAME)
	sudo $(VALGRIND) ./$(NAME) maps/map.ber

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_DIR)

fclean: clean
	@make -C $(MLX_DIR) clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re