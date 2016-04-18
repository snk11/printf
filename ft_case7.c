/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 08:47:12 by syusof            #+#    #+#             */
/*   Updated: 2016/04/18 11:27:13 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"


int		ft_case7(char ****str,t_numb *e,va_list ap)
{
	int		cnt;

	cnt = 0;
	if (****str == 'h' && (***str)[1] == 'h' && ((***str)[2] == 'd' || (***str)[2] == 'i'))
		cnt = cnt + ft_case7a(&str,e,ap);
	else if (****str == 'h' && (***str)[1] == 'h' && (***str)[2] == 'l' && ((***str)[3] == 'd' || (***str)[3] == 'i'))
		cnt = cnt + ft_case7b(&str,e,ap);
	else if (****str == 'l' && (***str)[1] == 'u')
		cnt = cnt + ft_case7c(&str,e,ap);
	return (cnt);
}


int		ft_case7a(char *****str,t_numb *e,va_list ap)
{
	int	cnt;

	cnt = 0;
	e->c = va_arg(ap, char);
	cnt = cnt + ft_putnbr2(e->c,e);
	(****str)++;
	(****str)++;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

int		ft_case7b(char *****str,t_numb *e,va_list ap)
{
	int	cnt;

	cnt = 0;
	e->ll  = va_arg(ap, long long);
	ft_putllnbr(e->ll);
	cnt = cnt + ft_countlld(e->ll);
	(****str)++;
	(****str)++;
	(****str)++;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

int		ft_case7c(char *****str,t_numb *e,va_list ap)
{
	int	cnt;

	cnt = 0;
	e->ul = va_arg(ap, unsigned long);
	ft_putulongnbr(e->ul);
	cnt = cnt + ft_countul(e->ul);
	(****str)++;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

