# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 17:41:30 by mboughra          #+#    #+#              #
#    Updated: 2024/03/04 16:46:50 by mboughra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC =  gcc
CFLAGS = -Wall -Werror -Wextra

# Executable
TARGET = so_long

# Source files
SRCS = checkers/check2.c checkers/check1.c checkers/check3.c \
		get_next_line/get_next_line_utils.c get_next_line/get_next_line.c \
		main.c checkers/mapmaker.c checkers/split.c checkers/pathcheck.c \
		infocollect/init.c checkers/homecheck.c errorhandle/fail.c \
		mlx/mlxwindow.c mlx/mapset.c mlx/move.c \
		mlx/key.c printf/ft_printf.c printf/ft_hexafunctions.c printf/ft_putfunctions.c
# Object files
OBJS = $(SRCS:.c=.o)

# Header files
HEADERS = so_long.h

# # Libraries
# LIBS = -lmlx -lXext -lX11 -lm

# Compilation rule
%.o: %.c $(HEADERS)
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

# Linking rule
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(TARGET) 
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(TARGET)
re: fclean all
all: $(TARGET)

.PHONY: clean