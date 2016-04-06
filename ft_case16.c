/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case16.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 10:20:14 by syusof            #+#    #+#             */
/*   Updated: 2016/04/06 14:53:27 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "ft_printf.h"


int		ft_case16(char ***str,t_numb *e,va_list ap)
{
	int		cnt;

	cnt = 0;
	if (***str == 'h' && (**str)[1] == 'h' && (**str)[2] == 'O')
		cnt = cnt + ft_case16a(&str,e,ap);
	else if ((***str == 'l' || ***str == 'h' || ***str == 'j' || ***str == 'z') && ((**str)[1] == 'U' || (**str)[1] == 'D'))
		cnt = cnt + ft_case16b(&str,e,ap);
	else if (***str == 'h' && (**str)[1] == 'h' && ((**str)[2] == 'U' || (**str)[2] == 'D'))
		cnt = cnt + ft_case16c(&str,e,ap);
	return (cnt);
}
int		ft_case16a(char ****str,t_numb *e,va_list ap)
{
	int	cnt;
	char	*s2;

	cnt = 0;
	e->us = va_arg(ap, unsigned short);
	s2 = ft_ltooct3(e->us);
	ft_putstr(s2);
	cnt = cnt + ft_strlen(s2);
	(***str)++;
	(***str)++;
	free(s2);
	s2 = NULL;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

int		ft_case16b(char ****str,t_numb *e,va_list ap)
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

int		ft_case16c(char ****str,t_numb *e,va_list ap)
{
	int	cnt;

	cnt = 0;
	e->us = va_arg(ap, unsigned short);
	ft_putushortnbr(e->us);
	cnt = cnt + ft_countus(e->us);
	(***str)++;
	(***str)++;
	ft_initialize(e);
	e->indelsif = 1;
	return (cnt);
}

