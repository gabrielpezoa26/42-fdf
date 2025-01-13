# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 14:04:57 by gcesar-n          #+#    #+#              #
#    Updated: 2025/01/13 11:05:07 by gcesar-n         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./libft -I./includes
LDFLAGS = -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit

LIBFT = ./libft/libft.a

LIBS = -L/usr/local/lib -lXext -lX11 -lm

SRC =	./src/main.c \
		./src/utils.c \
		./src/map_parser.c \
		./src/error_handler.c \
		./src/populate_map.c \
		./src/render.c \
		./src/controls.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)
	@echo "compilingggg"

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIBS)

$(LIBFT):
	@echo "buildingggg"
	make -C ./libft

clean:
	@echo "cleaningggg"
	rm -f $(OBJ)

fclean: clean
	@echo "full cleannnnn"
	rm -f fdf

re: fclean all
	@echo "cleaning and recompilingggg"
