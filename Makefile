# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoria <asoria@stedent.42madrid.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/15 00:26:06 by asoria            #+#    #+#              #
#    Updated: 2025/12/29 21:54:09 by asoria           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= minishell
CC		?= cc
CFLAGS		?= -Wall -Wextra -Werror -Wpedantic -g -O2
CPPFLAGS	?= -Iincludes -Iincludes/libft -lreadline
SRC_DIR		:= src
OBJ_DIR		:= obj
OBJ		= $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))
LIBFT_DIR	:= includes/libft
LIBFT		:= $(LIBFT_DIR)/libft.a
TARGET_DIR	:= target
RM		?= rm

SRC	:= \
	minishell.c \
	init.c \
	parsing.c \
	debug.c \
	cleanup.c \
	executing.c

all:	$(NAME)

clean:
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

$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

.PHONY: all clean fclean re

