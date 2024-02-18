# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 17:41:30 by mboughra          #+#    #+#              #
#    Updated: 2024/02/18 23:36:58 by mboughra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
SRCS = check2.c fail.c get_next_line_utils.c map.ber mlxwindow.c split.c check1.c check3.c get_next_line.c main.c mapmaker.c so_long.h test.c
OBJS = $(SRCS:.c=.o)
EXEC = so_long
LIBS = -lmlx -lXext -lX11
INC_DIR = .
NAME = so_long.a


do: $(NAME) 

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
%.o: %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

# clean:
# 	rm -f $(OBJS)

# fclean: clean
# 	rm -f $(EXEC)

# re: fclean all

.PHONY: all clean fclean re
