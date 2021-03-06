/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putznbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 01:09:06 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 15:20:25 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putznbr(size_t n, t_numb *e)
{
	int		r1;

	r1 = 0;
	if (e->valzero == 0)
	{
		if (n == UINT_MAX)
		{
			ft_putstr("4294967295");
			r1 = 10;
		}
		else
			r1 = r1 + ft_putznbr1(n, e);
	}
	else if (e->valzero == 1)
	{
		if (e->indpr == 1)
			r1 = r1 + ft_putznbr42a(e);
		else
			r1 = r1 + ft_putznbr42b(e);
	}
	return (r1);
}

int	ft_putznbr42a(t_numb *e)
{
	int		r1;

	r1 = 0;
	while (e->w - e->pr > 0)
	{
		ft_putchar(' ');
		r1++;
		e->w--;
	}
	while ((e->pr) > 0)
	{
		ft_putchar('0');
		r1++;
		e->pr--;
	}
	return (r1);
}

int	ft_putznbr42b(t_numb *e)
{
	int		r1;

	r1 = 0;
	if (e->indminus == 0)
	{
		if (e->w == 0)
		{
			ft_putchar('0');
			r1++;
		}
		while (e->w)
		{
			e->w--;
			ft_putchar('0');
			r1++;
		}
	}
	else if (e->indminus == 1)
	{
		ft_putchar('0');
		r1++;
	}
	return (r1);
}

int	ft_putznbr1(size_t n, t_numb *e)
{
	int		i;
	int		r1;

	i = 0;
	r1 = 0;
	i = ft_count3(n);
	if (n >= 10)
	{
		r1 = r1 + ft_putznbr(n / 10, e);
		r1 = r1 + ft_putznbr(n % 10, e);
	}
	else
	{
		ft_putchar(n + '0');
		r1++;
	}
	return (r1);
}

int	ft_putznbr2(size_t n, t_numb *e)
{
	int		r1;

	r1 = 0;
	r1 = r1 + ft_putznbr2a(n, e);
	return (r1);
}
