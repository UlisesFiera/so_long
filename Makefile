NAME 					= so_long

LIBFT					= ./libft/libft.a

CC						= gcc

STD_FLAGS				= -Wall -Wextra -Werror
MLX_FLAGS				= -Lminilibx-linux -lmlx_Linux -lX11 -lXext

SRCS					= main.c \
						  esc_window.c \
						  ft_pixel_put.c \
						  load_textures.c \

OBJS					= ${SRCS:.c=.o}

REMOVE					= rm -f ${OBJS}; rm -f so_long; rm -f *.out

all:					${LIBFT} ${NAME}

${NAME}:
						${CC} ${SRCS} ${LIBFT} ${STD_FLAGS} ${MLX_FLAGS} -o ${NAME}

${LIBFT}:				
						make bonus -C ./libft

clean:
						${REMOVE}

fclean:					clean
						make fclean -C ./libft
						
re:						fclean all

.PHONY:					all clean fclean re