/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkd_p3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:01:59 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 14:06:43 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_countd342a1(t_numb *e, t_count *f)
{
	int		j;
	int		r1;

	r1 = 0;
	if (e->indpr == 1)
		r1 = r1 + ft_countd342a1z(e, f);
	r1 = r1 + ft_countd342a1a(e, f);
	if (e->indzero == 1 && e->indpr == 0)
	{
		j = 0;
		while (j < e->w - f->i)
		{
			ft_putchar('0');
			r1++;
			j++;
		}
	}
	return (r1);
}

int		ft_countd342a1z(t_numb *e, t_count *f)
{
	int	r1;
	int j;

	j = 0;
	r1 = 0;
	while (j < e->w - f->i)
	{
		ft_putchar(' ');
		r1++;
		j++;
	}
	return (r1);
}

int		ft_countd342a1a(void)
{
	int		r1;

	r1 = 0;
	ft_putchar('-');
	r1++;
	return (r1);
}

int		ft_countd342b(t_numb *e, t_count *f)
{
	int		r1;

	r1 = 0;
	if (e->indminus == 1 || f->neg == 1)
	{
		ft_putchar('-');
		r1++;
	}
	if (e->indplus == 1 && e->indminus == 0)
	{
		ft_putchar('+');
		r1++;
	}
	if (e->indspace == 1 && f->neg == 0)
	{
		ft_putchar(' ');
		r1++;
	}
	return (r1);
}

int		ft_countd3a(t_numb *e, t_count *f)
{
	int r1;

	r1 = 0;
	if (f->neg == 1)
	{
		ft_putchar('-');
		r1++;
		while ((e->w - f->i) > 0)
		{
			ft_putchar('0');
			r1++;
			e->w--;
		}
	}
	else
		r1 = r1 + ft_countd3a1(e, f);
	return (r1);
}
