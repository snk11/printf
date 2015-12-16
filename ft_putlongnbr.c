/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlongnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 01:40:19 by syusof            #+#    #+#             */
/*   Updated: 2015/12/16 04:21:44 by syusof           ###   ########.fr       */
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
