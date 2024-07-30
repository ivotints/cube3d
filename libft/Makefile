# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 16:23:36 by ivotints          #+#    #+#              #
#    Updated: 2024/07/30 22:42:36 by ivotints         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
			ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
			ft_calloc.c ft_strdup.c ft_toupper.c ft_tolower.c \
			ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
			ft_strnstr.c ft_atoi.c ft_strrchr.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
			ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strcmp.c
SRCSB		= ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c ft_lstiter_bonus.c \
			ft_lstmap_bonus.c
OBJ_DIR		= obj
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)
OBJSB		= $(SRCSB:%.c=$(OBJ_DIR)/%.o)
NAME		= libft.a
LIBC		= ar rcs
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror

all: ${NAME}

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: %.c $(OBJ_DIR) 
	@$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJS}
	@${LIBC} ${NAME} ${OBJS}

bonus: ${NAME} ${OBJSB}
	@${LIBC} ${NAME} ${OBJSB}

clean:
	@${RM} ${OBJ_DIR}

fclean: clean
	@${RM} ${NAME} ${bonus}

re: fclean all

.PHONY : all bonus clean fclean re
