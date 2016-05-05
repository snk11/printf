/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_p2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 15:13:34 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 15:14:08 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr2a(unsigned int n, t_numb *e)
{
	int		r1;

	r1 = 0;
	if (n >= 10)
	{
		r1 = r1 + ft_putunbr2(n / 10, e);
		r1 = r1 + ft_putunbr2(n % 10, e);
	}
	else
	{
		ft_putchar(n + '0');
		r1++;
	}
	return (r1);
}

int	ft_putunbr2a1(unsigned int n, t_numb *e)
{
	int		i;
	int		r1;

	i = 0;
	r1 = 0;
	i = ft_count2(n);
	if (e->indzero == 1 && e->w > i && e->pr == 0 && e->indminus == 0)
	{
	}
	else if (e->pr < i)
	{
		ft_putchar('-');
		r1++;
	}
	return (r1);
}
