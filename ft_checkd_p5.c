/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkd_p5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:02:30 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 14:04:50 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_countd442(t_numb *e, t_count *f)
{
	int r1;

	r1 = 0;
	while (e->w - f->i > 0)
	{
		ft_putchar(' ');
		r1++;
		e->w--;
	}
	if (e->indplus == 1 && f->neg == 0 && e->indminus == 0)
	{
		ft_putchar('+');
		r1++;
		e->w--;
	}
	return (r1);
}

int		ft_countd4a(t_numb *e, t_count *f)
{
	int		r1;

	r1 = 0;
	if (f->neg == 1)
		r1 = r1 + ft_countd4a1(e, f);
	else
	{
		if (e->indplus == 1)
			e->w--;
		if (e->indspace == 1)
			e->w--;
		if (e->indspace == 1)
		{
			ft_putchar(' ');
			r1++;
		}
		r1 = r1 + ft_countd4a42(e, f);
	}
	return (r1);
}

int		ft_countd4a42(t_numb *e, t_count *f)
{
	int		r1;

	r1 = 0;
	while (e->w - e->pr > 0)
	{
		ft_putchar(' ');
		r1++;
		e->w--;
	}
	if (e->indplus == 1 && e->indminus == 0)
	{
		ft_putchar('+');
		r1++;
	}
	while ((e->pr - f->i) > 0)
	{
		ft_putchar('0');
		r1++;
		e->pr--;
	}
	return (r1);
}

int		ft_countd4a1(t_numb *e, t_count *f)
{
	int	r1;

	r1 = 0;
	while (e->w - e->pr - 1 > 0)
	{
		ft_putchar(' ');
		r1++;
		e->w--;
	}
	ft_putchar('-');
	r1++;
	while ((e->pr - f->i + 1) > 0)
	{
		ft_putchar('0');
		r1++;
		e->pr--;
	}
	return (r1);
}

int		ft_countd4a2(t_numb *e, t_count *f)
{
	int	r1;

	r1 = 0;
	r1 = r1 + ft_countd4a2z(e, f);
	ft_putchar('-');
	r1++;
	while ((e->pr - f->i + 1) > 0)
	{
		ft_putchar('0');
		r1++;
		e->pr--;
	}
	return (r1);
}
