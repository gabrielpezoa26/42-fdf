# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 14:04:57 by gcesar-n          #+#    #+#              #
#    Updated: 2025/02/03 13:11:50 by gabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wextra -Wall -Werror -Wunreachable-code -Ofast -g
INCLUDES = -I ./src -I ./MLX42/include -I ./MLX42/include/MLX42 -I ./libft

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX42_DIR = ./MLX42
MLX42_BUILD = $(MLX42_DIR)/build
LIBMLX42 = $(MLX42_BUILD)/libmlx42.a

LIBS = $(LIBMLX42) -ldl -lglfw -pthread -lm

SRCS =	./src/controls.c \
		./src/error_handler.c \
		./src/main.c \
		./src/map_parser.c \
		./src/render.c \
		./src/utils.c \
		./src/setup.c 

OBJS = $(SRCS:.c=.o)
DEPS = ./src/fdf.h

all: $(NAME)

$(NAME): $(OBJS) $(LIBMLX42) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(LIBS)
	@echo "linkingggg $(NAME)"

$(LIBMLX42):
	cmake -DDEBUG=1 $(MLX42_DIR) -B $(MLX42_BUILD)
	make -C $(MLX42_BUILD) -j4

$(LIBFT):
	make -C $(LIBFT_DIR) all

$(OBJS): $(DEPS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "compilinggg $<"

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFT_DIR)
	rm -rf $(MLX42_BUILD)
	@echo "cleaningggg $<"


fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	@echo "full cleaninggg $<"


re: fclean all
