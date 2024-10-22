# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpetit <lpetit@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 13:57:50 by lpetit            #+#    #+#              #
#    Updated: 2024/10/22 12:18:19 by lpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D

CC		= cc

SRCS 	= ./srcs/helper.c ./srcs/map_init.c ./srcs/main.c \
./gnl/get_next_line.c ./gnl/get_next_line_utils.c ./srcs/draw_map.c \
./srcs/render.c ./srcs/map_check.c ./srcs/closed.c ./srcs/map_check_add.c \
./srcs/init_graphics.c \
./srcs/cast_rays.c ./srcs/cast_helper.c ./srcs/key_hook.c \
./srcs/init_player.c ./srcs/init_textures.c ./srcs/freeing.c

LIB_DIR = ./libft

LIB		= $(LIB_DIR)/libft.a

INCLUDES = ./includes

OBJS	= $(SRCS:.c=.o)

FLAGS	= -Wall -Wextra -Werror -g

MLX_DIR = ./minilibx

MLX		=	$(MLX_DIR)/libmlx.a

HEADERS = includes/cub3d.h

X = -L includes/ -lmlx -framework OpenGL -framework AppKit

#Colors:
GREEN		=	\e[92;5;118m
GRAY		=	\e[33;2;37m
CURSIVE		=	\e[33;3m
RESET		=	\e[0m

.PHONY: all clean fclean re

all: $(LIB) $(MLX) $(NAME)

$(LIB):
	$(MAKE) -C $(LIB_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME):	$(OBJS) $(HEADERS)
	@printf "$(CURSIVE)$(GRAY) 	- Compiling $(NAME)... $(RESET)\n"
	$(CC) $(FLAGS) -I$(INCLUDES) -o $(NAME) $(OBJS) $(LIB) $(X)
	@printf "$(GREEN)    - Executable ready.\n$(RESET)"

%.o: %.c
	$(CC) $(FLAGS) -I$(INCLUDES) -c "$<" -o "$@"

clean:
	rm -rf $(OBJS)
	$(MAKE) -C $(LIB_DIR) clean

fclean:	clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all
