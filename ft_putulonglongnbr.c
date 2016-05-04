/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putulonglongnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 15:45:16 by syusof            #+#    #+#             */
/*   Updated: 2016/05/04 14:06:33 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putulonglongnbr(unsigned long long n)
{
	if (n == ULLONG_MAX)
		ft_putstr("18446744073709551615");
	else
	{
		if (n >= 10)
		{
			ft_putulonglongnbr(n / 10);
			ft_putulonglongnbr(n % 10);
		}
		else
			ft_putchar(n + '0');
	}
}
