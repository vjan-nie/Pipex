# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 12:24:16 by vjan-nie          #+#    #+#              #
#    Updated: 2025/03/31 17:14:19 by vjan-nie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB	= 	pipex.a
LIBFT	=	libft.a
SRC		=	ft_atoi.c\
			
			
CC		= 	gcc
CFLAGS	= 	-Wall -Wextra -Werror
OBJ		= 	$(SRC:.c=.o)

all: $(LIB)

$(LIB): $(OBJ)
	ar rcs $(LIB) $(LIBFT) $(OBJ)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@
	
clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(LIB)
	
re: fclean all

.PHONY: all clean fclean re
