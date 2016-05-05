/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks_p2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:27:14 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 14:36:26 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checks242b(t_numb *e)
{
	int	cnt;

	cnt = 0;
	e->g = ft_strlen(e->s);
	while (e->w - e->g > 0)
	{
		cnt++;
		ft_putchar(' ');
		(e->w)--;
	}
	return (cnt);
}

int		ft_checks42(t_numb *e)
{
	int	cnt;

	cnt = 0;
	cnt = cnt + ft_checks42a(e);
	cnt = cnt + ft_checks42b(e);
	return (cnt);
}

int		ft_checks42a(t_numb *e)
{
	int	cnt;

	cnt = 0;
	e->g = ft_strlen(e->s);
	if (e->indzero == 0)
	{
		while (e->w - e->g > 0)
		{
			cnt++;
			ft_putchar(' ');
			(e->w)--;
		}
	}
	else
	{
		while (e->w - e->g > 0)
		{
			cnt++;
			ft_putchar('0');
			(e->w)--;
		}
	}
	return (cnt);
}

int		ft_checks42b(t_numb *e)
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
	return (cnt);
}

int		ft_checks1(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->pr > e->w)
		cnt = cnt + ft_checks1a(e);
	else if (e->w > e->pr)
		cnt = cnt + ft_checks1b(e);
	return (cnt);
}
