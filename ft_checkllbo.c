/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkllbo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:30:46 by syusof            #+#    #+#             */
/*   Updated: 2016/04/27 14:59:32 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkllbo(char *str, t_numb *e, t_ll *w, va_list ap)
{
	int		cnt;
	char	*s2;

	cnt = 0;
	w->k = 2;
	cnt = cnt + ft_checkllbd1(str, e, w);
	if (w->k2 == 0)
	{
		e->us = va_arg(ap, unsigned int);
		s2 = ft_ltooct3(e->us);
		ft_putstr(s2);
		cnt = cnt + ft_strlen(s2);
	}
	else if (str[w->k] == 'O')
	{
		ft_putchar('O');
		cnt++;
	}
	e->indll = 0;
	return (cnt);
}
