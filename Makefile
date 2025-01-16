# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 14:04:57 by gcesar-n          #+#    #+#              #
#    Updated: 2025/01/15 13:12:28 by gabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

CC	= cc

CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g

INCLUDES	= -I ./src -I ./lib/MLX42/include -I ./lib/libft

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

MLX42_DIR	= ./MLX42
MLX42_BUILD	= $(MLX42_DIR)/build
LIBMLX42	= $(MLX42_BUILD)/libmlx42.a

LIBS		= $(LIBMLX42) -ldl -lglfw -pthread -lm

SRCS =	./src/controls.c \
		./src/error_handler.c \
		./src/main.c \
		./src/map_parser.c \
		./src/populate_map.c \
		./src/render.c \
		./src/utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): libmlx $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(LIBS)
	@echo "linkingggg $(NAME)"

libmlx:
	@cmake -DDEBUG=1 $(MLX42_DIR) -B $(MLX42_BUILD)
	@make -C $(MLX42_BUILD) -j4
	@echo "mlx42 builttttt"

$(LIBFT):
	@make -C $(LIBFT_DIR) all
	@echo "libft builtttt"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "compilinggg $<"

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(MLX42_BUILD)
	@echo "cleaningggg"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "full cleaningggg"

re: fclean all
