# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 12:10:26 by bchedru           #+#    #+#              #
#    Updated: 2024/04/09 17:56:28 by bchedru          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main error_free push_swap_command push_swap_init tiny_sort stack_utils stack_init push_command swap_command rotate_command reverse_rotate_command split push_b

SRC = $(addsuffix .c,$(SRCS))
OBJ = $(addsuffix .o,$(SRCS))

CC = cc
CCFLAGS = -Wall -Wextra -Werror -O0 -g

NAME = push_swap

all: $(NAME)

bonus :
	cd bonus/ && make

$(NAME) : $(OBJ)
	$(CC) -o $@ $(OBJ) $(INC_ARCHIVES)

%.o: %.c
	$(CC) -c -o $@ $< $(CCFLAGS)

clean :
	cd bonus/ && make clean
	rm -rf $(OBJ)

fclean : clean
	cd bonus/ && make fclean
	rm -rf $(NAME)

re : fclean
	make

.PHONY : all clean fclean re
