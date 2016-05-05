/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks_p3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:27:53 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 14:36:03 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checks1a(t_numb *e)
{
	int cnt;
	int	i;

	e->g = ft_strlen(e->s);
	cnt = 0;
	cnt = cnt + ft_checks1a1(e);
	if (e->s)
	{
		ft_putstr2(e->pr, e->s);
		i = 0;
		e->pr = e->prbegi;
		while (i < e->g && e->pr > 0)
		{
			cnt++;
			i++;
			(e->pr)--;
		}
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	return (cnt);
}

int		ft_checks1a1(t_numb *e)
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

void	ft_decr(t_numb *e)
{
	(e->w)--;
	(e->pr)--;
}

int		ft_checks1b(t_numb *e)
{
	int	cnt;

	cnt = 0;
	e->g = ft_strlen(e->s);
	if (e->g > e->pr)
		cnt = cnt + ft_checks1b1(e);
	else if (e->g < e->pr)
		cnt = cnt + ft_checks1b2(e);
	return (cnt);
}

int		ft_checks1b1(t_numb *e)
{
	int	cnt;
	int	i;

	cnt = 0;
	cnt = cnt + ft_checks1b1a(e);
	if (e->s)
	{
		ft_putstr2(e->pr, e->s);
		i = 0;
		while (e->pr > 0)
		{
			cnt++;
			(e->pr)--;
		}
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	return (cnt);
}
