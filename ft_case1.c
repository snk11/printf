/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:10:46 by syusof            #+#    #+#             */
/*   Updated: 2016/05/04 16:19:04 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_case1(char ****str, t_numb *e, va_list ap)
{
	int		cnt;

	cnt = 0;
	if (****str == 'c')
		cnt = cnt + ft_case1a(e, ap);
	else if (****str == 'C')
		cnt = cnt + ft_case1b(e, ap);
	else if (****str == 's')
		cnt = cnt + ft_case1c(&str, e, ap);
	return (cnt);
}

int		ft_case1a(t_numb *e, va_list ap)
{
	int		cnt;

	cnt = 0;
	e->d = va_arg(ap, int);
	cnt = cnt + ft_checkc(e);
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

int		ft_case1b(t_numb *e, va_list ap)
{
	int		cnt;

	cnt = 0;
	e->wc = va_arg(ap, wchar_t);
	if (e->wc && ((e->wc) <= -1 || (e->wc) >= 1114111))
		return (-1);
	cnt = cnt + ft_putwchar(e->wc);
	e->indelsif = 1;
	return (cnt);
}

int		ft_case1c(char *****str, t_numb *e, va_list ap)
{
	int		cnt;

	cnt = 0;
	e->s = va_arg(ap, char*);
	cnt = cnt + ft_checks(****str, e);
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}
