# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/20 09:51:08 by idahhan           #+#    #+#              #
#    Updated: 2025/07/20 18:56:53 by idahhan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror
# MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
SRC_PATH = src/
UTILS_PATH = src/utils/
LIBFT_PATH = src/libft_utils/

SRCS = $(SRC_PATH)main.c \
		$(SRC_PATH)print_errors.c \
		$(SRC_PATH)parsing.c \
		$(SRC_PATH)parse_textures.c \
		$(SRC_PATH)parse_colors.c \
		$(SRC_PATH)read_cub_file.c \
		$(UTILS_PATH)get_next_line.c \
		$(UTILS_PATH)type_line.c \
		$(UTILS_PATH)free.c \
		$(LIBFT_PATH)ft_strlen.c \
		$(LIBFT_PATH)ft_strdup.c \
		$(LIBFT_PATH)ft_strtrim.c \
		$(LIBFT_PATH)ft_strncmp.c \
		$(LIBFT_PATH)ft_strchr.c \
		$(LIBFT_PATH)ft_strjoin.c \
		$(LIBFT_PATH)ft_atoi.c \
		$(LIBFT_PATH)ft_split.c \
		$(LIBFT_PATH)ft_lstnew.c \
		$(LIBFT_PATH)ft_lstadd_back.c \
		$(LIBFT_PATH)ft_lstclear.c \
		$(LIBFT_PATH)ft_lstdelone.c \
		
OBJS = $(SRCS:%.c=%.o)

HEADER = include/cub3d.h

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
