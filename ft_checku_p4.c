/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checku_p4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:41:14 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 14:42:19 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_countu3a142(t_numb *e, t_count *f)
{
	int	r1;

	r1 = 0;
	if (e->indpr == 0)
	{
		while (e->w - f->i > 0)
		{
			ft_putchar('0');
			r1++;
			e->w--;
		}
	}
	else if (e->indpr == 1)
	{
		while (e->w - f->i > 0)
		{
			ft_putchar(' ');
			r1++;
			e->w--;
		}
	}
	return (r1);
}

int		ft_countu3a1a(t_numb *e, t_count *f)
{
	int	r1;

	r1 = 0;
	while (e->w - f->i > 0)
	{
		ft_putchar(' ');
		r1++;
		e->w--;
	}
	return (r1);
}

int		ft_countu4(t_numb *e, t_count *f)
{
	int r1;

	r1 = 0;
	if (e->pr >= f->i)
		r1 = r1 + ft_countu4a(e, f);
	else
	{
		if (f->neg == 1 || e->indminus == 1)
			r1 = r1 + ft_countu4a2(e, f);
		else
			r1 = r1 + ft_countu442(e, f);
	}
	return (r1);
}

int		ft_countu442(t_numb *e, t_count *f)
{
	int r1;

	r1 = 0;
	while (e->w - f->i > 0)
	{
		ft_putchar(' ');
		r1++;
		e->w--;
	}
	return (r1);
}

int		ft_countu4a(t_numb *e, t_count *f)
{
	int		r1;

	r1 = 0;
	{
		r1 = r1 + ft_countu4a42(e, f);
	}
	return (r1);
}
