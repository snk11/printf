/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elseend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 13:55:41 by syusof            #+#    #+#             */
/*   Updated: 2016/05/04 17:49:06 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_elseend(char *str, t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indzero == 1)
	{
		cnt = cnt + ft_elseend1(e, '0');
		ft_putchar(*str);
	}
	else
	{
		if (e->w < 0)
		{
			e->w = -(e->w);
			ft_putchar(*str);
			cnt = cnt + ft_elseend1(e, ' ');
		}
		else
		{
			cnt = cnt + ft_elseend1(e, ' ');
			ft_putchar(*str);
		}
	}
	return (cnt);
}

int		ft_elseend1(t_numb *e, char c)
{
	int	cnt;

	cnt = 0;
	while ((e->w - 1) > 0)
	{
		cnt++;
		ft_putchar(c);
		(e->w)--;
	}
	return (cnt);
}
