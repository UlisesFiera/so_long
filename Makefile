gcc test.c -Lminilibx-linux -lmlx_Linux -lX11 -lXext
gcc main.c esc_window.c ft_pixel_put.c -o test  -Lminilibx-linux -lmlx_Linux -lX11 -lXext

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -1X11 -lm -lz -o $(NAME)


CC = cc
CFLAGS = -Wall -Werror -Wextra -g3

NAME = libftprintf.a
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
INC_DIRS = -I. -I$(LIBFT_DIR)

SRCS = ft_printf.c print_char.c print_digit.c print_ptr.c print_str.c print_un.c print_uphex.c
OBJS = $(SRCS:.c=.o)
AR = ar rcs

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

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