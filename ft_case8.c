/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 09:17:54 by syusof            #+#    #+#             */
/*   Updated: 2016/04/06 14:47:28 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"


int		ft_case8(char ***str,t_numb *e,va_list ap)
{
	int		cnt;

	cnt = 0;
	if (***str == 'h' && (**str)[1] == 'u')
		cnt = cnt + ft_case8a(&str,e,ap);
	else if (***str == 'h' && (**str)[1] == 'U')
		cnt = cnt + ft_case8b(&str,e,ap);
	else if ((***str == 'j' || ***str == 'z') && (**str)[1] == 'u')
		cnt = cnt + ft_case8c(&str,e,ap);
	return (cnt);
}

int		ft_case8a(char ****str,t_numb *e,va_list ap)
{
	int	cnt;

	cnt = 0;
	e->us = va_arg(ap, unsigned short);
	ft_putushortnbr(e->us);
	cnt = cnt + ft_countus(e->us);
	(***str)++;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

int		ft_case8b(char ****str,t_numb *e,va_list ap)
{
	int	cnt;

	cnt = 0;
	e->ul = va_arg(ap, unsigned long);
	ft_putulongnbr(e->ul);
	cnt = cnt + ft_countul(e->ul);
	(***str)++;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

int		ft_case8c(char ****str,t_numb *e,va_list ap)
{
	int	cnt;

	cnt = 0;
	e->ull = va_arg(ap, unsigned long long);
	ft_putulonglongnbr(e->ull);
	cnt = cnt + ft_countull(e->ull);
	(***str)++;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

