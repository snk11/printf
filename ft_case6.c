/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 08:26:58 by syusof            #+#    #+#             */
/*   Updated: 2016/04/18 11:26:27 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"


int		ft_case6(char ****str,t_numb *e,va_list ap)
{
	int		cnt;

	cnt = 0;
	if (****str == 'h' && ((***str)[1] == 'd' || (***str)[1] == 'i')) 
		cnt = cnt + ft_case6a(&str,e,ap);
	else if ((****str == 'j' || ****str == 'z') && ((***str)[1] == 'd' || (***str)[1] == 'i'))
		cnt = cnt + ft_case6b(&str,e,ap);
	else if (****str == 'l' && (***str)[1] == 'l' && ((***str)[2] == 'd' || (***str)[2] == 'i'))
		cnt = cnt + ft_case6c(&str,e,ap);
	return (cnt);
}
int		ft_case6a(char *****str,t_numb *e,va_list ap)
{
	int	cnt;

	cnt = 0;
	e->sd = va_arg(ap,short int);
	ft_putsdnbr(e->sd);
	cnt = cnt + ft_countsd(e->sd);
	(****str)++;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

int		ft_case6b(char *****str,t_numb *e,va_list ap)
{
	int	cnt;

	cnt = 0;
	e->ll = va_arg(ap,long long);
	ft_putllnbr(e->ll);
	cnt = cnt + ft_countlld(e->ll);
	(****str)++;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

int		ft_case6c(char *****str,t_numb *e,va_list ap)
{
	int	cnt;

	cnt = 0;
	e->ll = va_arg(ap, long long);
	ft_putllnbr(e->ll);
	cnt = cnt + ft_countlld(e->ll);
	(****str)++;
	(****str)++;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

