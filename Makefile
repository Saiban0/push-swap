# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 12:10:26 by bchedru           #+#    #+#              #
#    Updated: 2024/02/09 11:20:24 by bchedru          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	push_swap push_swap_utils tinysort_utils

INC_FILES = -I libft

INC_ARCHIVES = libft/libft.a

SRC = $(addsuffix .c,$(SRCS))
OBJ = $(addsuffix .o,$(SRCS))

CC = cc
CCFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

all: $(NAME)

$(NAME) : $(OBJ)
	make -C libft/ bonus
	$(CC) -o $@ $(OBJ) $(INC_ARCHIVES)

%.o: %.c
	$(CC) -c -o $@ $< $(CCFLAGS)

clean :
	make -C libft/ clean
	rm -rf $(OBJ)

fclean : clean
	make -C libft fclean
	rm -rf $(NAME) bonus

re : fclean
	make

.PHONY : all clean fclean re