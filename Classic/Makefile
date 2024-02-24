# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 17:41:30 by mboughra          #+#    #+#              #
#    Updated: 2024/02/24 15:48:30 by mboughra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC =  cc
CFLAGS = -Wall -Werror -Wextra

# Executable
TARGET = so_long

# Source files
SRCS = check2.c check1.c check3.c fail.c get_next_line_utils.c get_next_line.c main.c mapmaker.c split.c floodfill.c

# Object files
OBJS = $(SRCS:.c=.o)

# Header files
HEADERS = so_long.h

# # Libraries
# LIBS = -lmlx -lXext -lX11 -lm

# Compilation rule
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Linking rule
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LIBS)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(TARGET)
re: fclean all
all: $(TARGET)
