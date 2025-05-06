# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 12:24:16 by vjan-nie          #+#    #+#              #
#    Updated: 2025/05/06 13:33:38 by vjan-nie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	pipex

# Paths

SRC_DIR = src

INCLUDE_DIR = includes

LIBFT_DIR = libft

OBJ_DIR = obj

# Libft

LIBFT	=	$(LIBFT_DIR)/libft.a

LIBFT_INCLUDE	= -I$(LIBFT_DIR)/include

# Source files

SRC		=	$(SRC_DIR)/main.c\
			$(SRC_DIR)/pipex_utils.c\
			$(SRC_DIR)/get_path.c\

# Objects

OBJ		= 	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compiling rules

CC		= 	cc

CFLAGS	= 	-Wall -Wextra -Werror

# Includes

INCLUDES = -I$(INCLUDE_DIR) $(LIBFT_INCLUDE)

# Building commands:

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
