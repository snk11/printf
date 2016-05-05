/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkbx_p2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 13:56:47 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 13:58:03 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkbx142b(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indsharp == 1)
	{
		while (e->w - (e->g + 2) > 0)
		{
			ft_putchar('0');
			cnt++;
			(e->w)--;
		}
	}
	else
	{
		while (e->w - e->g > 0)
		{
			ft_putchar('0');
			cnt++;
			(e->w)--;
		}
	}
	return (cnt);
}

int		ft_checkbx1a(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->pr >= e->g)
	{
		while (e->w - e->pr > 0)
		{
			ft_putchar(' ');
			cnt++;
			(e->w)--;
		}
		while ((e->pr - e->g) > 0)
		{
			ft_putchar('0');
			cnt++;
			(e->pr)--;
		}
	}
	else
		cnt = cnt + ft_checkbx1a1(e);
	return (cnt);
}

int		ft_checkbx1a1(t_numb *e)
{
	int	cnt;

	cnt = 0;
	while (e->w - e->g > 0)
	{
		ft_putchar(' ');
		cnt++;
		(e->w)--;
	}
	return (cnt);
}
