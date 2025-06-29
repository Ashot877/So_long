# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asmkrtch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/31 19:05:49 by asmkrtch          #+#    #+#              #
#    Updated: 2025/05/31 19:05:54 by asmkrtch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

TARGET = so_long

FT_PRINTF_DIR = ft_printf
MLX_DIR = minilibx-linux
GET_NEXT_LINE_DIR = get_next_line
LIBFT_DIR = libft

INCLUDES = -I. -I$(GET_NEXT_LINE_DIR) -I$(MLX_DIR) -I$(FT_PRINTF_DIR) -I$(LIBFT_DIR)

FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a -lm -lX11 -lXext

SRCS = so_long.c\
		get_next_line/get_next_line_utils.c\
		get_next_line/get_next_line.c\
		get_next_line/utils.c\
		fill_st.c\
		error_.c\
		free_.c\
		check_map.c\
		check_paths.c\
		utils.c\
		mlx_func.c

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(FT_PRINTF) $(MLX_DIR)/libmlx.a $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -g $(FT_PRINTF) $(MLX) $(INCLUDES) -o $(TARGET)

$(MLX_DIR)/libmlx.a:
	$(MAKE) -C $(MLX_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)	all

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)	all

%.o: %.c
	$(CC) $(INCLUDES) $(CFLAGS) -g -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(TARGET)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean 

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
