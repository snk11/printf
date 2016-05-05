# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syusof <syusof@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 02:50:22 by syusof            #+#    #+#              #
#    Updated: 2016/05/05 16:53:25 by syusof           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_altprime.c ft_altprime_p2.c ft_atoi.c ft_case1.c ft_case10.c \
	   ft_case11.c ft_case11_p2.c ft_case12.c ft_case13.c ft_case14.c \
	   ft_case15.c ft_case16.c ft_case17.c ft_case18.c ft_case2.c ft_case3.c \
	   ft_case4.c ft_case5.c ft_case6.c ft_case7.c ft_case8.c ft_case9.c \
	   ft_check_perc.c ft_checkbo.c ft_checkbo_p2.c ft_checkbo_p3.c \
	   ft_checkbs.c ft_checkbs_p2.c ft_checkbs_p3.c ft_checkbs_p4.c \
	   ft_checkbs_p5.c ft_checkbx.c ft_checkbx_p2.c ft_checkc.c ft_checkc_p2.c \
	   ft_checkd.c ft_checkd_p2.c ft_checkd_p3.c ft_checkd_p4.c ft_checkd_p5.c \
	   ft_checkd_p6.c ft_checkletter.c ft_checkll.c ft_checkllbd.c \
	   ft_checkllbo.c ft_checkllbx.c ft_checkllx.c ft_checko.c ft_checko_p2.c \
	   ft_checko_p3.c ft_checkp.c ft_checkp_p2.c ft_checkp_p3.c ft_checkprec.c \
	   ft_checks.c ft_checks_p10.c ft_checks_p11.c ft_checks_p2.c \
	   ft_checks_p3.c ft_checks_p4.c ft_checks_p5.c ft_checks_p6.c \
	   ft_checks_p7.c ft_checks_p8.c ft_checks_p9.c ft_checku.c ft_checku_p2.c \
	   ft_checku_p3.c ft_checku_p4.c ft_checku_p5.c ft_checkwidth.c \
	   ft_checkx.c ft_checkx_p2.c ft_count.c ft_count_p2.c \
	   ft_count_p3.c ft_countwstr.c ft_countwstr_p2.c ft_countwstr_p3.c \
	   ft_elseend.c ft_elsif1.c ft_elsif2.c ft_elsif3.c ft_getfield.c \
	   ft_initialize.c ft_ltohex.c ft_ltohex_p2.c ft_ltohex_p3.c \
	   ft_ltohex_p4.c ft_ltooct.c ft_ltooct_p2.c ft_ltooct_p3.c ft_p1.c \
	   ft_p2.c ft_p3.c ft_p4.c ft_pow.c ft_printf.c ft_putchar.c ft_putjnbr.c \
	   ft_putjnbr_p2.c ft_putldnbr.c ft_putllnbr.c ft_putlongnbr.c \
	   ft_putnbr.c ft_putnbr_p2.c ft_putsdnbr.c ft_putstr.c ft_putstr_p2.c \
	   ft_putulonglongnbr.c ft_putunbr.c ft_putunbr_p2.c ft_putushortnbr.c \
	   ft_putwchar.c ft_putwchar_p2.c ft_putwchar_p3.c ft_putwstr.c \
	   ft_putwstr2.c ft_putwstr2_p2.c ft_putwstr2_p3.c ft_putznbr.c \
	   ft_putznbr_p2.c ft_strcmp.c ft_strlen.c ft_strlen_p2.c ft_strlen_p3.c

OFILES = ft_altprime.o ft_altprime_p2.o ft_atoi.o ft_case1.o ft_case10.o \
		 ft_case11.o ft_case11_p2.o ft_case12.o ft_case13.o ft_case14.o \
		 ft_case15.o ft_case16.o ft_case17.o ft_case18.o ft_case2.o ft_case3.o \
		 ft_case4.o ft_case5.o ft_case6.o ft_case7.o ft_case8.o ft_case9.o \
		 ft_check_perc.o ft_checkbo.o ft_checkbo_p2.o ft_checkbo_p3.o \
		 ft_checkbs.o ft_checkbs_p2.o ft_checkbs_p3.o ft_checkbs_p4.o \
		 ft_checkbs_p5.o ft_checkbx.o ft_checkbx_p2.o ft_checkc.o \
		 ft_checkc_p2.o ft_checkd.o ft_checkd_p2.o ft_checkd_p3.o \
		 ft_checkd_p4.o ft_checkd_p5.o ft_checkd_p6.o ft_checkletter.o \
		 ft_checkll.o ft_checkllbd.o ft_checkllbo.o ft_checkllbx.o \
		 ft_checkllx.o ft_checko.o ft_checko_p2.o ft_checko_p3.o ft_checkp.o \
		 ft_checkp_p2.o ft_checkp_p3.o ft_checkprec.o ft_checks.o \
		 ft_checks_p10.o ft_checks_p11.o ft_checks_p2.o ft_checks_p3.o \
		 ft_checks_p4.o ft_checks_p5.o ft_checks_p6.o ft_checks_p7.o \
		 ft_checks_p8.o ft_checks_p9.o ft_checku.o ft_checku_p2.o \
		 ft_checku_p3.o ft_checku_p4.o ft_checku_p5.o ft_checkwidth.o \
		 ft_checkx.o ft_checkx_p2.o ft_count.o ft_count_p2.o ft_count_p3.o \
		 ft_countwstr.o ft_countwstr_p2.o ft_countwstr_p3.o ft_elseend.o \
		 ft_elsif1.o ft_elsif2.o ft_elsif3.o ft_getfield.o ft_initialize.o \
		 ft_ltohex.o ft_ltohex_p2.o ft_ltohex_p3.o ft_ltohex_p4.o ft_ltooct.o \
		 ft_ltooct_p2.o ft_ltooct_p3.o ft_p1.o ft_p2.o ft_p3.o ft_p4.o \
		 ft_pow.o ft_printf.o ft_putchar.o ft_putjnbr.o ft_putjnbr_p2.o \
		 ft_putldnbr.o ft_putllnbr.o ft_putlongnbr.o ft_putnbr.o \
		 ft_putnbr_p2.o ft_putsdnbr.o ft_putstr.o ft_putstr_p2.o \
		 ft_putulonglongnbr.o ft_putunbr.o ft_putunbr_p2.o ft_putushortnbr.o \
		 ft_putwchar.o ft_putwchar_p2.o ft_putwchar_p3.o ft_putwstr.o \
		 ft_putwstr2.o ft_putwstr2_p2.o ft_putwstr2_p3.o ft_putznbr.o \
		 ft_putznbr_p2.o ft_strcmp.o ft_strlen.o ft_strlen_p2.o ft_strlen_p3.o


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

