/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkllbx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:17:58 by syusof            #+#    #+#             */
/*   Updated: 2016/04/27 15:00:11 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkllbx(char *str, t_numb *e, t_ll *w, va_list ap)
{
	int		cnt;
	char	*s2;

	cnt = 0;
	w->k = 2;
	cnt = cnt + ft_checkllbd1(str, e, w);
	if (w->k2 == 0)
	{
		e->ull = va_arg(ap, unsigned long long);
		s2 = ft_ltohex5(e->ull);
		if (e->indsharp == 1 && e->ull != 0)
			s2 = ft_case13b1(s2);
		if (e->ull >= 4294967296 && e->ull <= 4563402751)
			s2 = ft_case11b2(s2);
		e->s = s2;
		cnt = cnt + ft_checks(str, e);
	}
	else if (str[w->k] == 'X')
	{
		ft_putchar('X');
		cnt++;
	}
	e->indll = 0;
	return (cnt);
}
