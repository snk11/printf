/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkbs_p5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 13:45:11 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 13:54:46 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkbs2a2(t_numb *e)
{
	int	cnt;

	cnt = 0;
	while ((e->w - e->g) > 0)
	{
		cnt++;
		ft_putchar(' ');
		(e->w)--;
	}
	if (e->ss)
	{
		cnt = cnt + ft_putwstr(e->ss);
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	return (cnt);
}

int		ft_checkbs2b(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indminus == 1)
		cnt = cnt + ft_checkbs2b1(e);
	else
		cnt = cnt + ft_checkbs2b2(e);
	return (cnt);
}

int		ft_checkbs2b1(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->ss)
	{
		cnt = cnt + ft_putwstr(e->ss);
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	while ((e->w - e->g) > 0)
	{
		cnt++;
		ft_putchar(' ');
		(e->w)--;
	}
	return (cnt);
}

int		ft_checkbs2b2(t_numb *e)
{
	int	cnt;

	cnt = 0;
	while ((e->w - e->g) > 0)
	{
		cnt++;
		ft_putchar('0');
		(e->w)--;
	}
	if (e->ss)
	{
		cnt = cnt + ft_putwstr(e->ss);
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	return (cnt);
}
