# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 12:10:26 by bchedru           #+#    #+#              #
#    Updated: 2024/01/30 16:38:12 by bchedru          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	push_swap

INC_FILES = -I libft

INC_ARCHIVES = libft/libft.a

SRC = $(addsuffix .c,$(SRCS))
OBJ = $(addsuffix .o,$(SRCS))

CC = cc
CCFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

all: $(NAME)

$(NAME) : $(OBJ)
	make -C libft/ 
	$(CC) -o $@ $(OBJ) $(INC_ARCHIVES)

%.o: %.c
	$(CC) -c -o $@ $< $(CCFLAGS)

clean :
	make -C libft/ clean
	rm -rf $(OBJ) $(BOBJ)

fclean : clean
	make -C libft fclean
	rm -rf $(NAME) bonus

re : fclean
	make

.PHONY : all clean fclean re