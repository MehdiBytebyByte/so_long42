# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 17:41:30 by mboughra          #+#    #+#              #
#    Updated: 2024/03/06 20:10:04 by mboughra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =  cc
CFLAGS = -Wall -Werror -Wextra
NAME = so_long
SRCS = checkers/check2.c \
		checkers/check1.c \
		checkers/check3.c \
		get_next_line/get_next_line_utils.c \
		get_next_line/get_next_line.c \
		main.c \
		checkers/mapmaker.c \
		checkers/split.c \
		checkers/pathcheck.c \
		infocollect/init.c \
		checkers/homecheck.c \
		errorhandle/fail.c \
		mlx/mlxwindow.c \
		mlx/mapset.c mlx/move.c \
		mlx/key.c \
		printf/ft_printf.c \
		printf/ft_hexafunctions.c \
		printf/ft_putfunctions.c
OBJS = $(SRCS:.c=.o)
HEADER = so_long.h
all: $(NAME)
%.o: %.c $(HEADER)
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: clean