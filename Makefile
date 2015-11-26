# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syusof <syusof@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 02:50:22 by syusof            #+#    #+#              #
#    Updated: 2015/11/26 06:28:04 by syusof           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = *.c

OFILES = $(SRCS:.c=.o)

FLAGS =  -c



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

