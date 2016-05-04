/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 03:09:33 by syusof            #+#    #+#             */
/*   Updated: 2016/05/04 17:01:09 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_case2(char ****str, t_numb *e, va_list ap)
{
	int		cnt;

	cnt = 0;
	if (****str == 'S')
		cnt = cnt + ft_case2a(e, ap);
	else if (****str == 'p')
		cnt = cnt + ft_case2b(e, ap);
	else if (****str == 'u')
		cnt = cnt + ft_case2c(&str, e, ap);
	return (cnt);
}

int		ft_case2a(t_numb *e, va_list ap)
{
	int	cnt;

	cnt = 0;
	e->ss = va_arg(ap, wchar_t*);
	if (e->ss && ((int)*(e->ss) <= -1 || (int)*(e->ss) >= 1114111))
		return (-1);
	cnt = cnt + ft_checkbs(e);
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

int		ft_case2b(t_numb *e, va_list ap)
{
	int	cnt;

	cnt = 0;
	e->l = va_arg(ap, long);
	cnt = cnt + ft_checkp(e);
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

int		ft_case2c(char *****str, t_numb *e, va_list ap)
{
	int	cnt;

	cnt = 0;
	e->u = va_arg(ap, unsigned int);
	cnt = cnt + ft_checku(****str, e);
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}
