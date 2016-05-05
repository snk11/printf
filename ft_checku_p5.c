/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checku_p5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:41:22 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 14:41:56 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_countu4a42(t_numb *e, t_count *f)
{
	int		r1;

	r1 = 0;
	while (e->w - e->pr > 0)
	{
		ft_putchar(' ');
		r1++;
		e->w--;
	}
	while ((e->pr - f->i) > 0)
	{
		ft_putchar('0');
		r1++;
		e->pr--;
	}
	return (r1);
}

int		ft_countu4a2(t_numb *e, t_count *f)
{
	int	r1;

	r1 = 0;
	r1 = r1 + ft_countu4a2a(e, f);
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

int		ft_countu4a2a(t_numb *e, t_count *f)
{
	int	r1;

	r1 = 0;
	if (e->indplus == 1)
	{
		while (e->w - f->i + 1 > 0)
		{
			ft_putchar(' ');
			r1++;
			e->w--;
		}
	}
	else
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
