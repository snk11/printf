/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case17.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 10:20:26 by syusof            #+#    #+#             */
/*   Updated: 2016/04/06 13:23:12 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "ft_printf.h"


int		ft_case17(char **str,t_numb *e,va_list ap)
{
	int		cnt;

	cnt = 0;
	if (**str == 'l' && (*str)[1] == 'p')
		cnt = cnt + ft_case17a(&str,e,ap);
	else if ((**str == 'z' || **str == 'j') && ((*str)[1] != 'd' && (*str)[1] != 'i') )
		cnt = cnt + ft_case17b(&str,e,ap);
	else if ((**str == 'h') && ((*str)[1] != 'd' && (*str)[1] != 'i' && (*str)[1] != 'h' && ((*str)[2] != 'd' && (*str)[2] != 'i')) )
		cnt = cnt + ft_case17c(&str,e,ap);
	else if ((**str == 'l') && ((*str)[1] != 'd' && (*str)[1] != 'i' && (*str)[1] != 'l' && ((*str)[2] != 'd' && (*str)[2] != 'i')) )
		cnt = cnt + ft_case17d(&str,e,ap);
	return (cnt);
}

int		ft_case17a(char ***str,t_numb *e,va_list ap)
{
	int	cnt;

	cnt = 0;
	e->l = va_arg(ap, long);
	ft_putstr("0x");
	ft_putstr(ft_ltohex(e->l));
	cnt = cnt + ft_strlen(ft_ltohex(e->l)) + 2;
	(**str)++;
	ft_initialize(e);
	return (cnt);
}

int		ft_case17b(char ***str,t_numb *e,va_list ap)
{
	int	cnt;

	cnt = 0;
	e->indperc = 1;
	return (cnt);
}

int		ft_case17c(char ***str,t_numb *e,va_list ap)
{
	int	cnt;

	cnt = 0;
	e->indperc = 1;
	return (cnt);
}

int		ft_case17d(char ***str,t_numb *e,va_list ap)
{
	int	cnt;

	cnt = 0;
	e->indperc = 1;
	return (cnt);
}

