/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case13.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 10:19:33 by syusof            #+#    #+#             */
/*   Updated: 2016/04/26 13:02:50 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_case13(char ****str, t_numb *e, va_list ap)
{
	int		cnt;

	cnt = 0;
	if (****str == 'l' && (***str)[1] == 'X')
		cnt = cnt + ft_case13a(&str, e, ap);
	else if (****str == 'h' && (***str)[1] == 'X')
		cnt = cnt + ft_case13b(&str, e, ap);
	else if ((****str == 'j' || ****str == 'z') && (***str)[1] == 'X')
		cnt = cnt + ft_case13c(&str, e, ap);
	return (cnt);
}

int		ft_case13a(char *****str, t_numb *e, va_list ap)
{
	int		cnt;
	char	*s2;

	cnt = 0;
	e->ul = va_arg(ap, unsigned long);
	s2 = ft_ltohex2(e->ul);
	if (e->indsharp == 1 && e->ul != 0)
		s2 = ft_case13b1(s2);
	if (e->ul >= 4294967296 && e->ul <= 4563402751)
		s2 = ft_case11b2(s2);
	e->s = s2;
	cnt = cnt + ft_checks(****str, e);
	(****str)++;
	free(s2);
	s2 = NULL;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

char	*ft_case13b1(char *s2)
{
	char	*s3;
	int		i;

	s3 = (char*)malloc(sizeof(char) * (ft_strlen(s2) + 1));
	s3[0] = '0';
	s3[1] = 'X';
	i = 2;
	while (i <= ft_strlen(s2) + 2)
	{
		s3[i] = s2[i - 2];
		i++;
	}
	free(s2);
	return (s3);
}

int		ft_case13b(char *****str, t_numb *e, va_list ap)
{
	int		cnt;
	char	*s2;

	cnt = 0;
	e->us = va_arg(ap, unsigned int);
	s2 = ft_ltohex7(e->us);
	ft_putstr(s2);
	cnt = cnt + ft_strlen(s2);
	(****str)++;
	free(s2);
	s2 = NULL;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

int		ft_case13c(char *****str, t_numb *e, va_list ap)
{
	int		cnt;
	char	*s2;

	cnt = 0;
	e->ull = va_arg(ap, unsigned long long);
	s2 = ft_ltohex5(e->ull);
	if (e->indsharp == 1 && e->ull != 0)
		s2 = ft_case13b1(s2);
	if (e->ull >= 4294967296 && e->ull <= 4563402751)
		s2 = ft_case11b2(s2);
	e->s = s2;
	cnt = cnt + ft_checks(****str, e);
	(****str)++;
	free(s2);
	s2 = NULL;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}
