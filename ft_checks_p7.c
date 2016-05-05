/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks_p7.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:28:40 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 14:34:12 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checks2c2(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indzero == 1)
		cnt = cnt + ft_checks2c2a(e);
	else
		cnt = cnt + ft_checks2c2b(e);
	return (cnt);
}

int		ft_checks2c2a(t_numb *e)
{
	int		cnt;
	int		i;
	char	sn[7];

	ft_fullsn(sn);
	cnt = 0;
	while ((e->w - e->pr) > 0)
	{
		cnt++;
		ft_putchar('0');
		(e->w)--;
	}
	i = 0;
	while (e->pr > 0)
	{
		ft_putchar(sn[i]);
		cnt++;
		i++;
		(e->pr)--;
	}
	return (cnt);
}

int		ft_checks2c2b(t_numb *e)
{
	int		cnt;
	int		i;
	char	sn[7];

	ft_fullsn(sn);
	cnt = 0;
	while ((e->w - e->pr) > 0)
	{
		cnt++;
		ft_putchar(' ');
		(e->w)--;
	}
	i = 0;
	while (e->pr > 0)
	{
		ft_putchar(sn[i]);
		cnt++;
		i++;
		(e->pr)--;
	}
	return (cnt);
}

int		ft_checks21(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->pr > e->w)
		cnt = cnt + ft_checks21a(e);
	else if (e->w > e->pr)
		cnt = cnt + ft_checks21b(e);
	return (cnt);
}

int		ft_checks21a(t_numb *e)
{
	int cnt;
	int	i;

	e->g = ft_strlen(e->s);
	cnt = 0;
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
	cnt = cnt + ft_checks21a1(e);
	return (cnt);
}
