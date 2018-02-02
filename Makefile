# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 11:52:57 by fde-souz          #+#    #+#              #
#    Updated: 2018/02/03 00:41:00 by vgauther         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re

NAME = wolf3d

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./srcs/
INC_PATH = ./includes/
OBJ_PATH = ./obj/
LFT_PATH = ./libft/
MLX_PATH = ./minilibx_macos/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)

INC_NAME = wolf3d.h

SRC_NAME =	main.c \
			image.c \
			parser.c \
			translate.c \
			intersection.c 



all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LFT_PATH)
	@echo "_______ZZZZ\n______ZZZZZZZ\n______ZZZZZZZZZ\n_______ZZZZZZZZZZ\n________ZZZZZZZZZZZ\n_________ZZZZZZZZZ\n_________ZZZZZZZZZ\n_________ZZZZZZZZZZ\n_________ZZZZZZZZZZZ\n_________ZZZZZZZZZZZZZ\n_________ZZZZZZZZZZZZZZ\n_________ZZZZZZZZZZZZZZZZZ\n_________ZZZZZZZZZZZZZZZZZZZ\n_________ZZZZZZZZZZZZZZZZZZZZ\n__________ZZZZZZZZZZZZZZZZZZZZZZZ\n___________ZZZZZZZZZZZZZZZZZZZZZZZZZZZ\n___________ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ\n_____________ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ\n______________ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ\n______________ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ\n_______________ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ\n_______________ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ\n________________ZZZZ__ZZZ____ZZZZZZZZZZZZZZZZZZ\n_________________ZZ___ZZZ_____ZZZZZZZZZZZZZZZZZZ\n_________________ZZ___ZZZ_____ZZZZZZZZZZZZZZZZZZZZZ___ZZ\n_________________ZZ___ZZZ______ZZZZZZZZZZZZZ_ZZZZZZZZZZZ\n_________________ZZ___ZZZ______ZZZZZZZZZZZZZZ_ZZZZZZZZZ\n________________ZZZ___ZZ_________ZZZZZ___ZZZZZ\n___________ZZZZZZZ___ZZZ__________ZZZZZ____ZZZ\n________ZZZZZZZZZZZZZZZ_____________ZZZ____ZZZ\n____ZZZZZZZZZZZZZZZZZZZZZZZ_________ZZZ_____ZZZ\n___ZZZZZZZZZZZZZZZZZZZZZZZZZZZ______ZZZ______ZZZ\n__ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ_______ZZZ\n_ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ_____ZZZ\n_ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ_ZZZ"
	@$(CC) -o $(NAME) $(OBJ) -lm -L $(LFT_PATH) -lft -L $(MLX_PATH) -lmlx -lm -framework OpenGL -framework AppKit

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<

clean:
	@make -C $(LFT_PATH) clean
	@rm -rf $(OBJ_PATH)

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(NAME)
clean_o:
	@rm -f $(NAME)
	@rm -rf $(OBJ_PATH)

re: fclean all
