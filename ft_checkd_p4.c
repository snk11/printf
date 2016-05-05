/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkd_p4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:02:21 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 14:05:18 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_countd3a1(t_numb *e, t_count *f)
{
	int	r1;

	r1 = 0;
	if (e->indminus == 1)
		r1 = r1 + ft_countd3a1a(e, f);
	else
	{
		if (e->indplus == 1)
			e->w--;
		if (e->indplus == 1)
		{
			ft_putchar('+');
			r1++;
		}
		r1 = r1 + ft_countd3a142(e, f);
	}
	return (r1);
}

int		ft_countd3a142(t_numb *e, t_count *f)
{
	int	r1;

	r1 = 0;
	if (e->indspace == 1)
		e->w--;
	if (e->indspace == 1)
	{
		ft_putchar(' ');
		r1++;
	}
	if (e->indpr == 1)
	{
		while (e->w - f->i > 0)
		{
			ft_putchar(' ');
			r1++;
			e->w--;
		}
	}
	else if (e->indpr == 0)
		r1 = r1 + ft_countd3a142z(e, f);
	return (r1);
}

int		ft_countd3a142z(t_numb *e, t_count *f)
{
	int	r1;

	r1 = 0;
	while (e->w - f->i > 0)
	{
		ft_putchar('0');
		r1++;
		e->w--;
	}
	return (r1);
}

int		ft_countd3a1a(t_numb *e, t_count *f)
{
	int	r1;

	r1 = 0;
	if (e->indplus == 1 && e->indminus == 0)
		e->w--;
	if (e->indplus == 1 && e->indminus == 0)
	{
		ft_putchar('+');
		r1++;
	}
	if (e->indspace == 1)
		e->w--;
	if (e->indspace == 1)
	{
		ft_putchar(' ');
		r1++;
	}
	while (e->w - f->i > 0)
	{
		ft_putchar(' ');
		r1++;
		e->w--;
	}
	return (r1);
}

int		ft_countd4(t_numb *e, t_count *f)
{
	int r1;

	r1 = 0;
	if (e->pr >= f->i)
		r1 = r1 + ft_countd4a(e, f);
	else
	{
		if (e->indplus == 1)
			e->w--;
		if (e->indspace == 1 && e->indplus == 0 && f->neg == 0 && e->w < f->i)
		{
			ft_putchar(' ');
			r1++;
		}
		if (f->neg == 1 || e->indminus == 1)
			r1 = r1 + ft_countd4a2(e, f);
		else
			r1 = r1 + ft_countd442(e, f);
	}
	return (r1);
}
