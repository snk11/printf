/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case11_p2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 16:01:36 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 16:02:11 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
