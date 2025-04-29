# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 18:41:28 by mah-ming          #+#    #+#              #
#    Updated: 2025/04/29 16:13:05 by mah-ming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := so_long

SRC_DIR    := srcs
OBJ_DIR    := obj

CC     := gcc
CFLAGS    := -Wextra -Wall -Werror -g 

INCLUDE    := -I ./includes

SRC        := main.c get_next_line.c get_next_line_utils.c errors.c \
				parse.c utils.c
OBJ        := $(SRC:%.c=$(OBJ_DIR)/%.o)

GREEN    := \033[1;32m
NC        := \033[0m

LIB     := make -sC mlx 
LIB.A    := mlx/libmlx_Linux.a

all: $(NAME)

$(NAME): $(OBJ)
	@$(LIB)
	@$(CC) $(OBJ) $(LIB.A) -lXext -lX11 -lm -lz -o $(NAME) && printf "$(GREEN)✔️ $(NAME)$(NC) compiled\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE) && printf "$(GREEN)✔️ $(notdir $<)$(NC) compiled\n"

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re