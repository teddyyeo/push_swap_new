# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 16:12:20 by tayeo             #+#    #+#              #
#    Updated: 2022/11/17 06:55:03 by tayeo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = push_swap

SRC = main.c op1.c op2.c op3.c sort.c small_sort.c
OBJ = ${SRC:.c=.o}

FLAG = -Werror -Wall -Wextra -D BUFFER_SIZE=1

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIB) push_swap.h
	$(CC)  $(OBJ)  $(LIB)  -o $(NAME)

$(LIB):
	make -C libft

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C libft


fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

n: $(SRC)
	norminette -R CheckForbiddenSourceHeader src libft
	norminette -R CheckDefine push_swap.h

.PHONY: all clean fclean re n
