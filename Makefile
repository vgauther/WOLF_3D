# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/23 13:56:44 by vgauther          #+#    #+#              #
#    Updated: 2018/01/25 13:28:45 by vgauther         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS

RESET=\033[0m
DARK=\033[132m
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
MAGENTA=\033[35m
CYAN=\033[36m
WHITE=\033[37m
BOLDBLACK=\033[1m\033[30m
BOLDRED=\033[1m\033[31m
BOLDWHITE=\033[1m\033[37m

.PHONY: all, $(NAME), clean, fclean, re

NAME = wolf3d

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra -g

SRC_PATH = ./SRCS/
INC_PATH = ./INC/
OBJ_PATH = ./OBJ/
LFT_PATH = ./libft/
MLX_PATH = ./minilibx_macos/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)

INC_NAME = wolf_3d.h

SRC_NAME = main.c error.c ft_countwords.c ft_open_n_read.c put_pixel_image.c mini_map.c

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(RESET)$(CYAN)MAKING LIBFT ...$(RESET)"
	@make -C $(LFT_PATH)
	@echo "$(RESET)$(GREEN)LIBFTDONE\n$(RESET)"
	@echo "$(RESET)$(CYAN)MAKING MLX LIB ...$(RESET)"
	@make -C $(MLX_PATH)
	@echo "$(RESET)$(GREEN)MLX DONE\n$(RESET)"
	@$(CC) -o $(NAME) $(OBJ) -lm -L $(LFT_PATH) -lft -L ./minilibx_macos/ -lmlx -lm -framework OpenGL -framework AppKit
	@echo "$(RESET)$(GREEN)[✓] EXECUTABLE FDF DONE$(RESET)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<

clean:
	@make -C $(LFT_PATH) clean
	@make -C $(MLX_PATH) clean
	@rm -rf $(OBJ_PATH)

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(NAME)
clean_o:
	@rm -f $(NAME)
	@rm -rf $(OBJ_PATH)

re-bis: clean_o $(NAME)

re: 
	@make fclean
	@make all
