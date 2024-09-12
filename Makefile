# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 22:09:07 by ivotints          #+#    #+#              #
#    Updated: 2024/09/12 18:52:12 by ivotints         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cube3D
CFLAGS		= -Wall -Wextra -Werror #-g
LIBS		= -lft -lmlx -lm -lX11 -lXext -I$(PATH_MLX)
FLAGS		= -L./libft -L$(PATH_MLX)
OBJ_DIR		= obj
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)
SRCS		= check.c clean.c error.c file.c handle.c identifier.c \
			init.c load.c main.c map2.c map.c player2.c player.c \
			ray2.c ray.c render.c texture.c utils.c img_paint_floor_ceiling.c \
			img_get_color.c

INCLUDE		= -I ./ -I ./includes
PATH_FT		= libft/
PATH_MLX	= minilibx-linux/
LIBFT_A		= libft/libft.a
LIBMLX_A	= minilibx-linux/libmlx.a
RM			= rm -rf
VPATH		= src
#FLAGS		= -I$(PATH_MLX) -lbsd -lXext -lX11 -Wl,-rpath=./$(PATH_MLX)/

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(LIBFT_A) $(LIBMLX_A) $(OBJ_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS) $(FLAGS)
	@echo $(NAME) done

$(LIBFT_A):
	@make -C $(PATH_FT)

$(LIBMLX_A):
	@make -C $(PATH_MLX)

$(OBJ_DIR):
	@mkdir -p $@

run: $(NAME)
	@./$(NAME) maps/lvl_0.cub

vrun: $(NAME)
	@valgrind ./$(NAME) maps/lvl_0.cub

clean:
	@make clean -C $(PATH_FT)
	@make clean -C $(PATH_MLX)
	@rm -rf $(OBJ_DIR)
	@echo removed $(OBJ_DIR) folder

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft
	@echo removed $(NAME)


re: fclean all

.PHONY: all run vrun clean fclean re

