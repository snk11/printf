/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 07:47:05 by syusof            #+#    #+#             */
/*   Updated: 2016/04/26 13:35:27 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_case5(char ****str, t_numb *e, va_list ap)
{
	int		cnt;

	cnt = 0;
	if (****str == 'z' && ((***str)[1] == 'h' || (***str)[1] == 'i')
			&& (***str)[2] == 'd')
		cnt = cnt + ft_case5a(&str, e, ap);
	else if (****str == 'j' && ((***str)[1] == 'z' || (***str)[1] == 'h')
			&& (***str)[2] == 'd')
		cnt = cnt + ft_case5b(&str, e, ap);
	else if (****str == 'l' && ((***str)[1] == 'd' || (***str)[1] == 'i'))
		cnt = cnt + ft_case5c(&str, e, ap);
	return (cnt);
}

int		ft_case5a(char *****str, t_numb *e, va_list ap)
{
	int	cnt;

	cnt = 0;
	e->z = va_arg(ap, size_t);
	cnt = cnt + ft_putznbr(e->z, e);
	(****str)++;
	(****str)++;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

int		ft_case5b(char *****str, t_numb *e, va_list ap)
{
	int	cnt;

	cnt = 0;
	e->j = va_arg(ap, intmax_t);
	cnt = cnt + ft_putjnbr(e->j, e);
	(****str)++;
	(****str)++;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

int		ft_case5c(char *****str, t_numb *e, va_list ap)
{
	int	cnt;

	cnt = 0;
	e->l = va_arg(ap, long);
	ft_putldnbr(e->l);
	cnt = cnt + ft_countld(e->l);
	(****str)++;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}
