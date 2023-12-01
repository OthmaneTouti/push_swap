# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 19:30:44 by ottouti           #+#    #+#              #
#    Updated: 2023/11/30 16:39:11 by ottouti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../include/ -fsanitize=address
DEBUGFLAGS = -g
LDFLAGS = -L../include/ -lft -fsanitize=address
RM = rm -f

FILES = push_swap utils swap_inst push_inst rotate_inst \
		sorting main error_check stack_utils init_nodes \
		tiny_sort node_utils move reverse_rotate_inst \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS = $(SRCS:.c=.o)

all: libft $(NAME)

libft:
	$(MAKE) --silent -C ../include/

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

debug: CFLAGS += $(DEBUGFLAGS)
debug: re

clean:
	$(RM) $(OBJS)
	$(MAKE) -C ../include/ clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ../include/ fclean

re: fclean all

.PHONY: all clean fclean re debug libft
