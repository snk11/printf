/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkbs_p3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 13:44:56 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 13:51:59 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkbs1b1(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indminus == 1)
		cnt = cnt + ft_checkbs1b1a(e);
	else
		cnt = cnt + ft_checkbs1b1b(e);
	return (cnt);
}

int		ft_checkbs1b1a(t_numb *e)
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
		ft_putchar('0');
		(e->w)--;
	}
	return (cnt);
}

int		ft_checkbs1b1b(t_numb *e)
{
	int	cnt;

	cnt = 0;
	while ((e->w - ft_countwstr(e->pr, e->ss)) > 0)
	{
		cnt++;
		ft_putchar(' ');
		(e->w)--;
	}
	if (e->ss)
	{
		cnt = cnt + ft_putwstr2(e->pr, e->ss);
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	return (cnt);
}

int		ft_checkbs1b2(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indminus == 1)
		cnt = cnt + ft_checkbs1b2a(e);
	else
		cnt = cnt + ft_checkbs1b2b(e);
	return (cnt);
}

int		ft_checkbs1b2a(t_numb *e)
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
		ft_putchar('0');
		(e->w)--;
	}
	return (cnt);
}
