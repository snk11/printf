/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putjnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 01:47:53 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 15:09:11 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putjnbr(intmax_t n, t_numb *e)
{
	int		r1;

	r1 = 0;
	if (e->valzero == 0)
		r1 = r1 + ft_putjnbr42a(n, e);
	else if (e->valzero == 1)
	{
		if (e->indpr == 1)
			r1 = r1 + ft_putjnbr42b(e);
		else
		{
			if (e->indminus == 0)
			{
				r1 = r1 + ft_putjnbr42c(e);
				r1 = r1 + ft_putjnbr42d(e);
			}
			else if (e->indminus == 1)
			{
				ft_putchar('0');
				r1++;
			}
		}
	}
	return (r1);
}

int	ft_putjnbr42a(intmax_t n, t_numb *e)
{
	int	r1;

	r1 = 0;
	if (n == -2147483648)
	{
		{
			ft_putstr("2147483648");
			r1 = 10;
		}
	}
	else
		r1 = r1 + ft_putjnbr1(n, e);
	return (r1);
}

int	ft_putjnbr42b(t_numb *e)
{
	int	r1;

	r1 = 0;
	if (e->indplus == 1)
	{
		e->w--;
	}
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
	while ((e->pr) > 0)
	{
		ft_putchar('0');
		r1++;
		e->pr--;
	}
	return (r1);
}

int	ft_putjnbr42c(t_numb *e)
{
	int	r1;

	r1 = 0;
	if (e->indplus == 1)
	{
		e->w--;
	}
	if (e->indspace == 1)
	{
		e->w--;
	}
	if (e->indspace == 1)
	{
		ft_putchar(' ');
		r1++;
	}
	if (e->indplus == 1 && e->indminus == 0)
	{
		ft_putchar('+');
		r1++;
	}
	return (r1);
}

int	ft_putjnbr42d(t_numb *e)
{
	int	r1;

	r1 = 0;
	if (e->w < 0)
	{
		ft_putchar('0');
		r1++;
	}
	while (e->w > 0)
	{
		e->w--;
		ft_putchar('0');
		r1++;
	}
	return (r1);
}
