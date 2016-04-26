/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case14.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 10:19:52 by syusof            #+#    #+#             */
/*   Updated: 2016/04/26 13:05:29 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_case14(char ****str, t_numb *e, va_list ap)
{
	int		cnt;

	cnt = 0;
	if (****str == 'h' && (***str)[1] == 'h' && (***str)[2] == 'X')
		cnt = cnt + ft_case14a(&str, e, ap);
	else if (****str == 'l' && (***str)[1] == 'c')
		cnt = cnt + ft_case14b(&str, e, ap);
	else if (****str == 'h' && (***str)[1] == 'h' && (***str)[2] == 'C')
		cnt = cnt + ft_case14c(&str, e, ap);
	return (cnt);
}

int		ft_case14a(char *****str, t_numb *e, va_list ap)
{
	int		cnt;
	char	*s2;

	cnt = 0;
	e->uc = va_arg(ap, unsigned int);
	s2 = ft_ltohex9(e->uc);
	ft_putstr(s2);
	cnt = cnt + ft_strlen(s2);
	(****str)++;
	(****str)++;
	free(s2);
	s2 = NULL;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

int		ft_case14b(char *****str, t_numb *e, va_list ap)
{
	int	cnt;

	cnt = 0;
	e->wc = va_arg(ap, wchar_t);
	cnt = cnt + ft_putwchar(e->wc);
	(****str)++;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

int		ft_case14c(char *****str, t_numb *e, va_list ap)
{
	int	cnt;

	cnt = 0;
	e->wc = va_arg(ap, wchar_t);
	cnt = cnt + ft_putwchar(e->wc);
	(****str)++;
	(****str)++;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}
