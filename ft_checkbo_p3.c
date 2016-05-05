/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkbo_p3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 13:42:00 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 13:43:34 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkbo21a1(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indsharp == 0)
	{
		while (e->w - e->g > 0)
		{
			ft_putchar(' ');
			cnt++;
			(e->w)--;
		}
	}
	else if (e->indsharp == 1)
	{
		while (e->w - e->g - 1 > 0)
		{
			ft_putchar(' ');
			cnt++;
			(e->w)--;
		}
	}
	return (cnt);
}
