/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkp_p3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:13:30 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 14:14:37 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkp2a1(t_numb *e, char *s1)
{
	int	cnt;

	cnt = 0;
	if (e->indminus == 1)
	{
		ft_putstr("0x");
		ft_putstrad(s1);
		while ((e->w - (e->g + 2)) > 0)
		{
			cnt++;
			ft_putchar(' ');
			(e->w)--;
		}
	}
	else
		cnt = cnt + ft_checkp2a1a(e, s1);
	return (cnt);
}

int		ft_checkp2a1a(t_numb *e, char *s1)
{
	int	cnt;

	cnt = 0;
	if (e->indspace == 1 || e->indplus == 1)
	{
		while ((e->w - (e->g + 2)) > 0)
		{
			cnt++;
			ft_putchar(' ');
			(e->w)--;
		}
		ft_putstr("0x");
		ft_putstr(s1);
	}
	else
		cnt = cnt + ft_checkp2a1a1(e, s1);
	return (cnt);
}

int		ft_checkp2a1a1(t_numb *e, char *s1)
{
	int	cnt;

	cnt = 0;
	while ((e->w - (e->g + 2)) > 0)
	{
		cnt++;
		ft_putchar(' ');
		(e->w)--;
	}
	ft_putstr("0x");
	ft_putstrad(s1);
	return (cnt);
}
