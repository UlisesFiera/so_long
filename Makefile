CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 -I/usr/include -Imlx_linux -O3

NAME = so_long.a
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
INC_DIRS = -I. -I$(LIBFT_DIR)

SRCS = main.c ft_pixel_put.c esc_window.c textures.c
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -1X11 -lm -lz -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INC_DIRS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all
.PHONY: clean
.PHONY: fclean
.PHONY: re



# INC_DIRS = -I. -I$(LIBFT_DIR)
# Include directories (current and libft folder)

# $(MAKE) -C $(LIBFT_DIR)
# Creates libft; -C is used to navigate to the directory
# pointed to by $(LIBFT_DIR)