/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkllx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 12:22:37 by syusof            #+#    #+#             */
/*   Updated: 2016/05/04 17:26:14 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkllx(char *str, t_numb *e, t_ll *w, va_list ap)
{
	int		cnt;
	char	*s2;

	cnt = 0;
	w->k = 2;
	cnt = cnt + ft_checkllbd1(str, e, w);
	if (w->k2 == 0)
	{
		e->ull = va_arg(ap, unsigned long long);
		s2 = ft_ltohex4(e->ull);
		if (e->indsharp == 1 && e->ull != 0)
			s2 = ft_case11b1(s2);
		if (e->ull >= 4294967296 && e->ull <= 4563402751)
			s2 = ft_case11b2(s2);
		e->s = s2;
		cnt = cnt + ft_checks(e);
	}
	else if (str[w->k] == 'x')
	{
		ft_putchar('x');
		cnt++;
	}
	e->indll = 0;
	return (cnt);
}
