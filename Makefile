# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 12:10:26 by bchedru           #+#    #+#              #
#    Updated: 2024/04/15 16:13:57 by bchedru          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main error_free push_swap_command push_swap_init tiny_sort stack_utils stack_init push_command swap_command rotate_command reverse_rotate_command split push_b

SRC = $(addsuffix .c,$(SRCS))
OBJ = $(addsuffix .o,$(SRCS))

CC = cc
CCFLAGS = -Wall -Wextra -Werror -O0 -g
NAME = push_swap

ARCHIVE = push_swap.a
MAKE_LIB = ar -rcs

all: $(NAME)

bonus :
	make -C bonus

archive : $(ARCHIVE)

$(ARCHIVE) : $(OBJ)
	$(MAKE_LIB) $(ARCHIVE) $^

$(NAME) : $(OBJ)
	$(CC) -o $@ $(OBJ) $(INC_ARCHIVES) $(CCFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CCFLAGS)

clean :
	make -C bonus clean
	rm -rf $(OBJ)

fclean : clean
	make -C bonus fclean
	rm -rf $(NAME) $(ARCHIVE)

re : fclean $(NAME)

.PHONY : all clean fclean re bonus