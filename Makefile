gcc test.c -Lminilibx-linux -lmlx_Linux -lX11 -lXext

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -1X11 -lm -lz -o $(NAME)