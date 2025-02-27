CC = cc
NAME = so_long
CFLAGS = -Wall -Wextra -Werror 
SRCS = so_long.c err_message.c ft_putnbr.c ft_split.c check.c first_desplay.c ft_putstr_fd.c ft_strncmp.c \
handle_input.c parsing.c ft_strnstr.c help.c test.c mlx.c help_2.c \
get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

MLX_DIR = /usr/include/minilibx-linux
MLX = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx  -lXext -lX11

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all clean
