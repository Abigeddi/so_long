# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abigeddi <abigeddi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/28 08:32:15 by abigeddi          #+#    #+#              #
#    Updated: 2022/05/28 08:53:24 by abigeddi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEADER = so_long.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

MAKE = make -C

SRC = 	so_long.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c\
		main.c\
		checkmap.c\
		checkmap2.c\
		checkmap3.c\
		player.c\
		moves.c\
		
OBJ = $(SRC:.c=.o)

all:$(NAME)

$(NAME) : ft_printf ft_libft $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) libft/libft.a ft_printf/libftprintf.a -o $(NAME)

ft_libft :
	@$(MAKE) libft

ft_printf :
	@$(MAKE) ft_printf

clean :
	@rm -f GNL/*.o && rm -f bonus/GNL/*.o
	@$(MAKE) libft clean && $(MAKE) printf clean

fclean : clean	
	@$(MAKE) libft fclean && $(MAKE) printf fclean
	@rm -f so_long 

re : fclean all
