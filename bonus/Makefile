# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 16:58:40 by bchedru           #+#    #+#              #
#    Updated: 2024/04/15 16:39:42 by bchedru          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	checker get_next_line get_next_line_utils

SRC = $(addsuffix .c,$(SRCS))
# OBJ = $(addsuffix .o,$(SRCS))

CC = cc
CCFLAGS = -Wall -Wextra -Werror -O0 -g

PUSH_SWAP_ARCHIVE = ../push_swap.a

NAME = checker

all: $(NAME)

$(NAME) : $(OBJ) $(PUSH_SWAP_ARCHIVE)
	$(CC) -o $@ $^ $(OBJ) $(INC_ARCHIVES)
	cp $(NAME) ../

%.o: %.c
	$(CC) -c -o $@ $< $(CCFLAGS)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf ../$(NAME)

re : fclean
	make


$(PUSH_SWAP_ARCHIVE) :
	make -C ../

.PHONY : all clean fclean re
