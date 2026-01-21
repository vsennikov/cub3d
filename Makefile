NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBMLX = -lmlx -lX11 -lXext -lm
INCLUDES = -I includes -I libft -I minilibx -I .

SRCDIR = src
PARSEDIR = src/parsing
RENDERDIR = src/rendering
GNLDIR = gnl
OBJDIR = obj
LIBFT_PATH = libft

LIBFT = $(LIBFT_PATH)/libft.a

SRC_FILES = main.c

RENDER_FILES = cleanup.c collision.c draw.c draw_floor_ceiling.c draw_map.c draw_wall.c \
			   error_handler.c init_game.c init_player.c keyboard.c math_utils.c \
			   pixel_utils.c player_movement.c raycasting.c raycasting_dda.c render.c \
			   texture_loader.c texture_selector.c

PARSE_FILES = parser_prep.c parser.c parser_file.c parser_memory.c parser_utils.c \
			  parser_config.c parser_config_utils.c parser_config_texture.c \
			  parser_config_colors.c parser_texture.c parser_map.c parser_map_utils.c \
			  parser_utils_2.c parser_map_utils_2.c

GNL_FILES = get_next_line.c get_next_line_utils.c

SRCS = $(addprefix $(SRCDIR)/, $(SRC_FILES)) \
	   $(addprefix $(RENDERDIR)/, $(RENDER_FILES)) \
	   $(addprefix $(PARSEDIR)/, $(PARSE_FILES)) \
	   $(addprefix $(GNLDIR)/, $(GNL_FILES))

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(LIBMLX)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	@rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
