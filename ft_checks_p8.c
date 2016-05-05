/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks_p8.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:28:53 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 14:33:07 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checks21a1(t_numb *e)
{
	int cnt;

	cnt = 0;
	e->g = ft_strlen(e->s);
	if (e->indzero == 0)
	{
		while (e->w - e->g > 0 && e->pr > 0)
		{
			cnt++;
			ft_putchar(' ');
			ft_decr(e);
		}
	}
	else
	{
		while (e->w - e->g > 0 && e->pr > 0)
		{
			cnt++;
			ft_putchar('0');
			ft_decr(e);
		}
	}
	return (cnt);
}

int		ft_checks21b(t_numb *e)
{
	int	cnt;

	cnt = 0;
	e->g = ft_strlen(e->s);
	if (e->g > e->pr)
		cnt = cnt + ft_checks21b1(e);
	else if (e->g < e->pr)
		cnt = cnt + ft_checks21b2(e);
	return (cnt);
}

int		ft_checks21b1(t_numb *e)
{
	int	cnt;
	int	i;

	cnt = 0;
	if (e->s)
	{
		ft_putstr2(e->pr, e->s);
		i = 0;
		while (i < e->pr)
		{
			cnt++;
			i++;
		}
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	cnt = cnt + ft_checks21b1a(e);
	return (cnt);
}

int		ft_checks21b1a(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indzero == 0)
	{
		while ((e->w - e->pr) > 0)
		{
			cnt++;
			ft_putchar(' ');
			(e->w)--;
		}
	}
	else
	{
		while ((e->w - e->pr) > 0)
		{
			cnt++;
			ft_putchar('0');
			(e->w)--;
		}
	}
	return (cnt);
}

int		ft_checks21b2(t_numb *e)
{
	int	cnt;
	int	i;

	cnt = 0;
	e->g = ft_strlen(e->s);
	if (e->s)
	{
		ft_putstr(e->s);
		i = 0;
		while (i < e->g)
		{
			cnt++;
			i++;
		}
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	cnt = cnt + ft_checks21b2a(e);
	return (cnt);
}
