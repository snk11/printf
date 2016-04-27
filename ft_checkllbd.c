/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkllbd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:37:23 by syusof            #+#    #+#             */
/*   Updated: 2016/04/27 14:52:10 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkllbd(char *str, t_numb *e, t_ll *w, va_list ap)
{
	int		cnt;

	cnt = 0;
	w->k = 2;
	cnt = cnt + ft_checkllbd1(str, e, w);
	if (w->k2 == 0)
	{
		e->us = va_arg(ap, unsigned int);
		ft_putushortnbr(e->us);
		cnt = cnt + ft_countus(e->us);
	}
	else if (str[w->k] == 'U')
	{
		ft_putchar('U');
		cnt++;
	}
	else if (str[w->k] == 'D')
	{
		ft_putchar('D');
		cnt++;
	}
	e->indll = 0;
	return (cnt);
}

int		ft_checkllbd1(char *str, t_numb *e, t_ll *w)
{
	int		cnt;

	cnt = 0;
	while (ft_checkletter(str[w->k]) != 1 && str[w->k])
	{
		if (str[w->k] == '#')
			e->indsharp = 1;
		if (((str[w->k] < '0' || str[w->k] > '9') && str[w->k] != ' '
					&& str[w->k] != '+' && str[w->k] != '-'
					&& str[w->k] != '.' && str[w->k] != '#'))
		{
			ft_putchar(str[w->k]);
			cnt++;
			(w->k2)++;
		}
		(w->k)++;
	}
	return (cnt);
}
