/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case15.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 10:20:04 by syusof            #+#    #+#             */
/*   Updated: 2016/04/18 11:33:38 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "ft_printf.h"


int		ft_case15(char ****str,t_numb *e,va_list ap)
{
	int		cnt;

	cnt = 0;
	if (****str == 'l' && (***str)[1] == 's')
		cnt = cnt + ft_case15a(&str,e,ap);
	else if (****str == 'h' && (***str)[1] == 'h' && (***str)[2] == 'S')
		cnt = cnt + ft_case15b(&str,e,ap);
	else if ((****str == 'l' || ****str == 'h' || ****str == 'j' || ****str == 'z') && (***str)[1] == 'O')
		cnt = cnt + ft_case15c(&str,e,ap);
	return (cnt);
}

int		ft_case15a(char *****str,t_numb *e,va_list ap)
{
	int	cnt;

	cnt = 0;
	e->ss = va_arg(ap, wchar_t*);
	if (e->ss)
	{
		cnt = cnt + ft_putwstr(e->ss);
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	(****str)++;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

int		ft_case15b(char *****str,t_numb *e,va_list ap)
{
	int	cnt;

	cnt = 0;
	e->ss = va_arg(ap, wchar_t*);
	if (e->ss)
	{
		cnt = cnt + ft_putwstr(e->ss);
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	(****str)++;
	(****str)++;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

int		ft_case15c(char *****str,t_numb *e,va_list ap)
{
	int	cnt;
	char	*s2;

	cnt = 0;
	e->us = va_arg(ap, unsigned short);
	s2 = ft_ltooct3(e->us);
	ft_putstr(s2);
	cnt = cnt + ft_strlen(s2);
	(****str)++;
	free(s2);
	s2 = NULL;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

