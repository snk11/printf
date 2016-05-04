/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case11.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 10:19:07 by syusof            #+#    #+#             */
/*   Updated: 2016/05/04 15:31:16 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_case11(char ****str, t_numb *e, va_list ap)
{
	int		cnt;

	cnt = 0;
	if (****str == 'h' && (***str)[1] == 'h' && (***str)[2] == 'o')
		cnt = cnt + ft_case11a(&str, e, ap);
	else if (****str == 'l' && (***str)[1] == 'x')
		cnt = cnt + ft_case11b(&str, e, ap);
	else if (****str == 'h' && (***str)[1] == 'x')
		cnt = cnt + ft_case11c(&str, e, ap);
	return (cnt);
}

int		ft_case11a(char *****str, t_numb *e, va_list ap)
{
	int		cnt;
	char	*s2;

	cnt = 0;
	e->uc = va_arg(ap, unsigned int);
	s2 = ft_ltooct6(e->uc);
	ft_putstr(s2);
	cnt = cnt + ft_strlen(s2);
	(****str)++;
	(****str)++;
	free(s2);
	s2 = NULL;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

int		ft_case11b(char *****str, t_numb *e, va_list ap)
{
	int		cnt;
	char	*s2;

	cnt = 0;
	e->ul = va_arg(ap, unsigned long);
	s2 = ft_ltohex3(e->ul);
	if (e->indsharp == 1 && e->ul != 0)
		s2 = ft_case11b1(s2);
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

char	*ft_case11b1(char *s2)
{
	char			*s3;
	unsigned long	i;

	s3 = (char*)malloc(sizeof(char) * (ft_strlen(s2) + 1));
	s3[0] = '0';
	s3[1] = 'x';
	i = 2;
	while (i <= ft_strlen(s2) + 2)
	{
		s3[i] = s2[i - 2];
		i++;
	}
	free(s2);
	return (s3);
}

char	*ft_case11b2(char *s2)
{
	char			*s4;
	unsigned long	i;

	s4 = (char*)malloc(sizeof(char) * (ft_strlen(s2) + 1));
	s4[0] = '1';
	i = 1;
	while (i <= ft_strlen(s2) + 2)
	{
		s4[i] = s2[i - 1];
		i++;
	}
	free(s2);
	return (s4);
}

int		ft_case11c(char *****str, t_numb *e, va_list ap)
{
	int		cnt;
	char	*s2;

	cnt = 0;
	e->us = va_arg(ap, unsigned int);
	s2 = ft_ltohex6(e->us);
	ft_putstr(s2);
	cnt = cnt + ft_strlen(s2);
	(****str)++;
	free(s2);
	s2 = NULL;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}
