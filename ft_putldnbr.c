/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putldnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 11:51:56 by syusof            #+#    #+#             */
/*   Updated: 2016/01/26 12:23:26 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putldnbr(long int n)
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
			ft_putldnbr(n / 10);
			ft_putldnbr(n % 10);
		}
		else
			ft_putchar(n + '0');
	}
}
