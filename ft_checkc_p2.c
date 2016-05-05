/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkc_p2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 13:58:30 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 13:59:57 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkc2a(t_numb *e)
{
	int	cnt;

	cnt = 0;
	ft_putchar(e->d);
	cnt++;
	while ((e->w - 1) > 0)
	{
		cnt++;
		ft_putchar('0');
		(e->w)--;
	}
	return (cnt);
}

int		ft_checkc2b(t_numb *e)
{
	int	cnt;

	cnt = 0;
	while ((e->w - 1) > 0)
	{
		cnt++;
		ft_putchar('0');
		(e->w)--;
	}
	ft_putchar(e->d);
	cnt++;
	return (cnt);
}
