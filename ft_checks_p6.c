/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks_p6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:28:32 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 14:34:39 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checks2b2a(t_numb *e)
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

int		ft_checks2b2b(t_numb *e)
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

int		ft_checks2c(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indminus == 1)
		cnt = cnt + ft_checks2c1(e);
	else if (e->indminus == 0)
		cnt = cnt + ft_checks2c2(e);
	return (cnt);
}

int		ft_checks2c1(t_numb *e)
{
	int		cnt;
	int		i;
	char	sn[7];

	ft_fullsn(sn);
	cnt = 0;
	i = 0;
	while (i < 6)
	{
		ft_putchar(sn[i]);
		cnt++;
		i++;
	}
	if (e->w > 6)
		cnt = cnt + ft_checks2c1a(e);
	return (cnt);
}

int		ft_checks2c1a(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indzero == 1)
	{
		while ((e->w - e->pr) > 0)
		{
			cnt++;
			ft_putchar('0');
			(e->w)--;
		}
	}
	else
	{
		while ((e->w - e->pr) > 0)
		{
			cnt++;
			ft_putchar(' ');
			(e->w)--;
		}
	}
	return (cnt);
}
