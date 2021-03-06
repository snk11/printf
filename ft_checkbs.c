/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkbs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 20:30:16 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 13:56:05 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkbs(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->ss)
		e->g = ft_strlen2(e->ss);
	if (!(e->ss))
		e->g = 6;
	if (e->indpr == 1)
		cnt = cnt + ft_checkbs1(e);
	else
		cnt = cnt + ft_checkbs2(e);
	return (cnt);
}

int		ft_checkbs1(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indminus == 1 && e->pr > 0 && e->w == 0)
		return (0);
	else if (e->indminus == 1 && e->w > 0)
	{
		while (e->w)
		{
			ft_putchar(' ');
			e->w--;
			cnt++;
		}
	}
	else if (e->pr > e->w)
		cnt = cnt + ft_checkbs1a(e);
	else if (e->w > e->pr)
		cnt = cnt + ft_checkbs1b(e);
	return (cnt);
}

int		ft_checkbs1a(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indzero == 0)
		cnt = cnt + ft_checkbs1a1(e);
	else
		cnt = cnt + ft_checkbs1a2(e);
	return (cnt);
}

int		ft_checkbs1a1(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indminus == 1)
		cnt = cnt + ft_checkbs1a1a(e);
	else
		cnt = cnt + ft_checkbs1a1b(e);
	return (cnt);
}

int		ft_checkbs1a1a(t_numb *e)
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
