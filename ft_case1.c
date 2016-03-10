/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:10:46 by syusof            #+#    #+#             */
/*   Updated: 2016/03/10 12:39:33 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		ft_case1(char **str,t_numb *e,va_list ap)
{
	int		cnt;

	cnt = 0;
	if (**str == 'c')
		cnt = cnt + ft_case1a(&str,e,ap);
	else if (**str == 'C')
		cnt = cnt + ft_case1b(&str,e,ap);
	else if (**str == 's')
		cnt = cnt + ft_case1c(&str,e,ap);
	return (cnt);
}

int		ft_case1a(char ***str,t_numb *e,va_list ap)
{
	int		cnt;

	cnt = 0;
		e->d = va_arg(ap, int);
	cnt = cnt + ft_checkc(**str,e);
	ft_initialize(e);
	return (cnt);
}

int		ft_case1b(char ***str,t_numb *e,va_list ap)
{
	int		cnt;

	cnt = 0;
	e->wc = va_arg(ap, wchar_t);
	cnt = cnt + ft_putwchar(e->wc);
	return (cnt);
}

int		ft_case1c(char ***str,t_numb *e,va_list ap)
{
	int		cnt;

	cnt = 0;
	e->s = va_arg(ap, char*);
	cnt = cnt + ft_checks(**str,e);
	ft_initialize(e);
	return (cnt);
}
