# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 19:30:44 by ottouti           #+#    #+#              #
#    Updated: 2023/12/01 20:44:35 by ottouti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../include/ -fsanitize=address
DEBUGFLAGS = -g
LDFLAGS = -L ./include/ -lft -fsanitize=address
RM = rm -f

FILES = push_swap misc swap push rotate sorting \
		find_target error_check stack_utils init_nodes \
		node_utils move reverse_rotate \

SRCS_DIR = ./src/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS = $(SRCS:.c=.o)

all: libft $(NAME)

libft:
	$(MAKE) --silent -C ./include/

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

debug: CFLAGS += $(DEBUGFLAGS)
debug: re

clean:
	$(RM) $(OBJS)
	$(MAKE) -C ./include/ clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ./include/ fclean

re: fclean all

.PHONY: all clean fclean re debug libft
