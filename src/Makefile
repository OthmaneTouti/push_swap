# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 19:30:44 by ottouti           #+#    #+#              #
#    Updated: 2023/11/28 22:47:16 by ottouti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../include/
DEBUGFLAGS = -g
LDFLAGS = -L../include/ -lft
RM = rm -f

FILES = push_swap utils swap_inst push_inst rotate_inst \
		sorting main error_check stack_utils\

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS=$(SRCS:.c=.o)

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
