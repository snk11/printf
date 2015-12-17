/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlongnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 01:40:19 by syusof            #+#    #+#             */
/*   Updated: 2015/12/17 15:36:47 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void	ft_putlongnbr(long n)
{
	if (n == LONG_MIN)
		ft_putstr("-9223372036854775808");
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n >= 10)
		{
			ft_putlongnbr(n / 10);
			ft_putlongnbr(n % 10);
		}
		else
			ft_putchar(n + '0');
	}
}

void	ft_putulongnbr(unsigned long n)
{
	unsigned long	c;

	c = 0;
	if (n == ULONG_MAX)
	{
		ft_putstr("18446744073709551615");
	}
	else
	{
		if (n < c)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n >= 10)
		{
			ft_putlongnbr(n / 10);
			ft_putlongnbr(n % 10);
		}
		else
			ft_putchar(n + '0');
	}
}
