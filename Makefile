CC = cc
CFLAGS = -g
SRCS = main.c \
       parser/parser_prep.c \
       parser/parser.c \
       parser/parser_file.c \
       parser/parser_memory.c \
       parser/parser_utils.c \
       parser/parser_config.c \
       parser/parser_config_utils.c \
       parser/parser_config_texture.c \
       parser/parser_config_colors.c \
       parser/parser_texture.c \
       parser/parser_map.c \
       parser/parser_map_utils.c

# Object files placed in obj directory
OBJDIR = obj
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
INCLUDES = -I./$(LIBFT_PATH)

GNL = gnl/get_next_line.c gnl/get_next_line_utils.c
GNL_O = $(GNL:%.c=$(OBJDIR)/%.o)

NAME = cub3d

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(OBJS) $(GNL_O) $(LIBFT) 
	$(CC) $(CFLAGS) $(OBJS) $(GNL_O) $(LIBFT) -o $(NAME) 

# Create object files in obj directory structure
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C ./libft clean
	@rm -rf $(OBJDIR)

fclean: clean
	@$(MAKE) -C ./libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re