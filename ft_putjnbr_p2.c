/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putjnbr_p2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 15:08:40 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 15:09:18 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putjnbr1(intmax_t n, t_numb *e)
{
	int		i;
	int		r1;

	i = 0;
	r1 = 0;
	i = ft_count4(n);
	if (n < 0)
	{
		if (e->indzero == 1 && e->w > i && e->pr == 0 && e->indminus == 0)
		{
		}
		n = -n;
	}
	if (n >= 10)
	{
		r1 = r1 + ft_putjnbr(n / 10, e);
		r1 = r1 + ft_putjnbr(n % 10, e);
	}
	else
	{
		ft_putchar(n + '0');
		r1++;
	}
	return (r1);
}

int	ft_putjnbr2(intmax_t n, t_numb *e)
{
	int		r1;

	r1 = 0;
	if (n == -2147483648)
	{
		{
			ft_putstr("-2147483648");
			r1 = 11;
		}
	}
	else
		r1 = r1 + ft_putjnbr2a(n, e);
	return (r1);
}

int	ft_putjnbr2a(intmax_t n, t_numb *e)
{
	int		r1;

	r1 = 0;
	if (n < 0)
	{
		r1 = r1 + ft_putnbr2a1(n, e);
		n = -n;
	}
	if (n >= 10)
	{
		r1 = r1 + ft_putjnbr2(n / 10, e);
		r1 = r1 + ft_putjnbr2(n % 10, e);
	}
	else
	{
		ft_putchar(n + '0');
		r1++;
	}
	return (r1);
}
