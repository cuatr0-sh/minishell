# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoria <asoria@stedent.42madrid.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/15 00:26:06 by asoria            #+#    #+#              #
#    Updated: 2025/12/17 03:31:01 by asoria           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= minishell
CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror -Iincludes -Ilibft -g3 -O3 -march=native -flto -pipe
SRC_DIR		:= src
SRC_FILES	:= minishell.c
OBJ_DIR		:= obj
OBJ_FILES	:= $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
LIBFT_DIR	:= includes/libft
LIBFT		:= $(LIBFT_DIR)/libft.a
TARGET_DIR	:= target

all:	$(NAME)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean:	clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: clean fclean all

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(TARGET_DIR)/$(NAME)
	@echo -e "\033[32mBuilt $(NAME)\033[0m"

$(OBJ_DIR):
	mkdir $(OBJ_DIR)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

