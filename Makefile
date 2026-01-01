# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoria <asoria@stedent.42madrid.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/15 00:26:06 by asoria            #+#    #+#              #
#    Updated: 2025/12/31 19:49:23 by asoria           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= minishell
CC		?= cc
CFLAGS		?= -Wall -Wextra -Werror -Wpedantic -g -O2
CPPFLAGS	?= -Iincludes -Iincludes/libft -lreadline
SRC_DIR		:= src
OBJ_DIR		:= obj
OBJ		= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
LIBFT_DIR	:= includes/libft
LIBFT		:= $(LIBFT_DIR)/libft.a
TARGET_DIR	:= target
RM		?= rm
BUILTIN_SRC_DIR	:= $(SRC_DIR)/builtin

SRC	:= \
	$(SRC_DIR)/minishell.c \
	$(SRC_DIR)/init.c \
	$(SRC_DIR)/parsing.c \
	$(SRC_DIR)/debug.c \
	$(SRC_DIR)/cleanup.c \
	$(SRC_DIR)/executing.c \
	$(BUILTIN_SRC_DIR)/cd.c

all:	$(NAME)

clean:
	$(RM) -f ".msrc"
	$(RM) -f ".ms_history"
	$(RM) -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean:
	$(RM) -rf $(TARGET_DIR)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) clean

re:
	$(MAKE) fclean
	$(MAKE) all

$(NAME): $(OBJ) $(LIBFT) | $(TARGET_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) $(LIBFT) -o $(TARGET_DIR)/$(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/builtin

$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

.PHONY: all clean fclean re

