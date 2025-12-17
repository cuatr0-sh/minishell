# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoria <asoria@stedent.42madrid.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/15 00:26:06 by asoria            #+#    #+#              #
#    Updated: 2025/12/17 14:24:56 by asoria           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= minishell
CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror -Iincludes -Ilibft -g3 -O3 -march=native -flto -pipe
SRC_DIR		:= src
SRC_FILES	:= minishell.c
OBJ_DIR		:= obj
OBJ_FILES	:= $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
#LIBFT_DIR	:= includes/libft
#LIBFT		:= $(LIBFT_DIR)/libft.a
TARGET_DIR	:= target

all:	$(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(TARGET_DIR)
#	$(MAKE) -C $(LIBFT_DIR) clean

fclean:	clean
	@rm -f $(NAME)
#	rm -f $(LIBFT)

re: clean fclean all

$(NAME): $(OBJ_FILES) $(TARGET_DIR)
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $(TARGET_DIR)/$(NAME)
	@echo -e "\033[32m[✔] Built $(NAME)\033[0m"

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(TARGET_DIR):
	mkdir $(TARGET_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

