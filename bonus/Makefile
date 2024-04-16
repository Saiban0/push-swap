# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 16:58:40 by bchedru           #+#    #+#              #
#    Updated: 2024/04/16 17:42:21 by bchedru          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

FILES =	checker get_next_line get_next_line_utils
SRC = $(addsuffix .c,$(FILES))
OBJ = $(addsuffix .o,$(FILES))

CC = cc
CCFLAGS = -Wall -Wextra -Werror -O0 -g

PUSH_SWAP_ARCHIVE = ../push_swap.a

all: $(NAME)

$(NAME) : $(OBJ) $(PUSH_SWAP_ARCHIVE)
	$(CC) -o $@ $^ $(INC_ARCHIVES)
	cp $(NAME) ../

$(PUSH_SWAP_ARCHIVE) :
	make -C ../

%.o: %.c
	$(CC) $(CCFLAGS) -c  $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME) ../$(NAME)

re : fclean
	make

.PHONY : all clean fclean re
