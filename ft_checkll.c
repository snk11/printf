/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 04:22:52 by syusof            #+#    #+#             */
/*   Updated: 2016/04/27 14:24:07 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkll(char *str, t_numb *e, va_list ap, t_ll *w)
{
	int		cnt;

	w->k = 2;
	w->k2 = 0;
	cnt = 0;
	e->indll = 1;
	while (ft_checkletter(str[w->k]) != 1 && str[w->k])
		(w->k)++;
	if (str[w->k] && str[w->k] == 'x')
		cnt = cnt + ft_checkllx(str, e, w, ap);
	else if (str[w->k] && str[w->k] == 'X')
		cnt = cnt + ft_checkllbx(str, e, w, ap);
	else if (str[w->k] && str[w->k] == 'O')
		cnt = cnt + ft_checkllbo(str, e, w, ap);
	else if ((str[w->k] && str[w->k] == 'U') || (str[w->k] && str[w->k] == 'D'))
		cnt = cnt + ft_checkllbd(str, e, w, ap);
	ft_initialize(e);
	return (cnt);
}
