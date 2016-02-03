/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:38:21 by syusof            #+#    #+#             */
/*   Updated: 2016/02/03 15:34:36 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int w,int pr,int zero,int n)
{
	int		i;

	i = 0;
	i = ft_count(n);
	if (n == -2147483648)
	{
		if (pr >= i)
			ft_putstr("2147483648");
		else
			ft_putstr("-2147483648");

	}
	else
	{
		if (n < 0)
		{
			if (zero == 1 && w > i && pr == 0)
			{
			}
			else if (pr < i)
				ft_putchar('-');
			n = -n;
		}
		if (n >= 10)
		{
			ft_putnbr(w,pr,zero,n / 10);
			ft_putnbr(w,pr,zero,n % 10);
		}
		else
			ft_putchar(n + '0');
	}
}
