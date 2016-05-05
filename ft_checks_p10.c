/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks_p10.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:29:08 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 14:32:08 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checks22b1a(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->w > 6)
	{
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
	}
	return (cnt);
}

int		ft_checks22b2(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indzero == 1)
		cnt = cnt + ft_checks22b2a(e);
	else
		cnt = cnt + ft_checks22b2b(e);
	return (cnt);
}

int		ft_checks22b2a(t_numb *e)
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

int		ft_checks22b2b(t_numb *e)
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

int		ft_checks22c(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indminus == 1)
		cnt = cnt + ft_checks22c1(e);
	else if (e->indminus == 0)
		cnt = cnt + ft_checks22c2(e);
	return (cnt);
}
