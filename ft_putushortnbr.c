/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putushortnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 13:31:50 by syusof            #+#    #+#             */
/*   Updated: 2016/01/26 13:37:43 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

void	ft_putushortnbr(unsigned short n)
{
	if (n == USHRT_MAX)
		ft_putstr("65535");
	else
	{
		if (n >= 10)
		{
			ft_putushortnbr(n / 10);
			ft_putushortnbr(n % 10);
		}
		else
			ft_putchar(n + '0');
	}
}
