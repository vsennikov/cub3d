CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = main.c 

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
INCLUDES = -I./$(LIBFT_PATH)


OBJS = $(SRCS:.c=.o)

NAME = cub3d

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft
	
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L./$(LIBFT_PATH) -lft -o $(NAME) 

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