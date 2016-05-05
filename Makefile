# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syusof <syusof@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 02:50:22 by syusof            #+#    #+#              #
#    Updated: 2016/05/05 13:37:30 by syusof           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = *.c

OFILES = $(SRCS:.c=.o)

FLAGS =  -Wall -Werror -Wextra -c



all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRCS)
	ar rc $(NAME) $(OFILES)
	ranlib $(NAME)



clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

