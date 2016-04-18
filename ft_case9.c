/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case9.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 09:56:56 by syusof            #+#    #+#             */
/*   Updated: 2016/04/18 11:28:27 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"


int		ft_case9(char ****str,t_numb *e,va_list ap)
{
	int		cnt;

	cnt = 0;
	if (****str == 'l' && (***str)[1] == 'l' && (***str)[2] == 'u')
		cnt = cnt + ft_case9a(&str,e,ap);
	else if (****str == 'h' && (***str)[1] == 'h' && (***str)[2] == 'u')
		cnt = cnt + ft_case9b(&str,e,ap);
	else if (****str == 'l' && (***str)[1] == 'o')
		cnt = cnt + ft_case9c(&str,e,ap);
	return (cnt);
}

int		ft_case9a(char *****str,t_numb *e,va_list ap)
{
	int	cnt;

	cnt = 0;
	e->ull = va_arg(ap, unsigned long long);
	ft_putulonglongnbr(e->ull);
	cnt = cnt + ft_countul(e->ull);
	(****str)++;
	(****str)++;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

int		ft_case9b(char *****str,t_numb *e,va_list ap)
{
	int	cnt;

	cnt = 0;
	e->uc = va_arg(ap, unsigned char);
	ft_putnbr(e->uc,e);
	cnt = cnt + ft_countuc(e->uc);
	(****str)++;
	(****str)++;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

int		ft_case9c(char *****str,t_numb *e,va_list ap)
{
	int	cnt;
	char	*s2;

	cnt = 0;
	e->ul = va_arg(ap, unsigned long);
	s2 = ft_ltooct2(e->ul);
	ft_putstr(s2);
	cnt = cnt + ft_strlen(s2);
	(****str)++;
	free(s2);
	s2 = NULL;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

