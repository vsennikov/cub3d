CC = cc
CFLAGS = -g
SRCS = main.c parser/parser_prep.c parser/parser.c

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
INCLUDES = -I./$(LIBFT_PATH)

GNL = gnl/get_next_line.c gnl/get_next_line_utils.c
GNL_O = $(GNL:.c=.o)

OBJS = $(SRCS:.c=.o)

NAME = cub3d

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft
	
$(NAME): $(OBJS) $(LIBFT) $(GNL_O)
	$(CC) $(CFLAGS) $(OBJS) $(GNL_O) -L./$(LIBFT_PATH) -lft -o $(NAME) 

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE)  -C ./libft clean
	@rm -f $(OBJS) 

fclean: clean
	@$(MAKE) -C ./libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re