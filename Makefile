CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -Lminilibx-linux -lmlx_Linux -L/usr/lib -lX11 -lXext -lz
SOURCES = so_long.c err_message.c ft_split.c check.c first_desplay.c ft_putstr_fd.c ft_strncmp.c handle_input.c parsing.c ft_strnstr.c help.c test.c mlx.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
NAME = so_long

OBJS = ${SOURCES:.c=.o}

.c.o:
	$(CC) ${CFLAGS} -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY:	$(OBJS)
