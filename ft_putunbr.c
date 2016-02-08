/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 18:30:53 by syusof            #+#    #+#             */
/*   Updated: 2016/02/08 18:18:50 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void	ft_putunbr(int w,int pr,int zero,unsigned int n)
{
	if (n == UINT_MAX)
		ft_putstr("4294967295");
	else
	{
		if (n >= 10)
		{
			ft_putunbr(w,pr,zero,n / 10);
			ft_putunbr(w,pr,zero,n % 10);
		}
		else
			ft_putchar(n + '0');
	}
}
