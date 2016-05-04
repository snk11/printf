# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syusof <syusof@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 02:50:22 by syusof            #+#    #+#              #
#    Updated: 2016/05/04 16:27:44 by syusof           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = *.c

OFILES = $(SRCS:.c=.o)

//FLAGS =  -Wall -Werror -Wextra -c
FLAGS = -c



all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRCS)
	ar rc $(NAME) $(OFILES)
	ranlib $(NAME)
	gcc -c ../main.c
	gcc -o main main.o -L . -lftprintf

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)
	rm -f main

re: fclean all

