/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 10:18:57 by syusof            #+#    #+#             */
/*   Updated: 2016/04/18 11:29:11 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"


int		ft_case10(char ****str,t_numb *e,va_list ap)
{
	int		cnt;

	cnt = 0;
	if (****str == 'h' && (***str)[1] == 'o')
		cnt = cnt + ft_case10a(&str,e,ap);
	else if ((****str == 'j' || ****str == 'z') && (***str)[1] == 'o')
		cnt = cnt + ft_case10b(&str,e,ap);
	else if (****str == 'l' && (***str)[1] == 'l' && (***str)[2] == 'o')
		cnt = cnt + ft_case10c(&str,e,ap);
	return (cnt);
}

int		ft_case10a(char *****str,t_numb *e,va_list ap)
{
	int	cnt;
	char	*s2;

	cnt = 0;
	e->us = va_arg(ap, unsigned short);
	s2 = ft_ltooct5(e->us);
	ft_putstr(s2);
	cnt = cnt + ft_strlen(s2);
	(****str)++;
	free(s2);
	s2 = NULL;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

int		ft_case10b(char *****str,t_numb *e,va_list ap)
{
	int	cnt;
	char	*s2;

	cnt = 0;
	e->ull = va_arg(ap, unsigned long long);
	s2 = ft_ltooct4(e->ull);
	ft_putstr(s2);
	cnt = cnt + ft_strlen(s2);
	(****str)++;
	free(s2);
	s2 = NULL;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

int		ft_case10c(char *****str,t_numb *e,va_list ap)
{
	int	cnt;
	char	*s2;

	cnt = 0;
	e->ull = va_arg(ap, unsigned long long);
	s2 = ft_ltooct4(e->ull);
	ft_putstr(s2);
	cnt = cnt + ft_strlen(s2);
	(****str)++;
	(****str)++;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

