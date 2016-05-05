/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks_p9.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:29:01 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 14:32:31 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checks21b2a(t_numb *e)
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

int		ft_checks22(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->pr > 6)
		e->pr = 6;
	if (e->w == 0 && e->pr == 0 && e->indpr == 0)
		cnt = cnt + ft_checks22a(e);
	else if (e->indpr == 1)
		cnt = cnt + ft_checks22b(e);
	else if (e->indpr == 0)
		cnt = cnt + ft_checks22c(e);
	return (cnt);
}

int		ft_checks22a(void)
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
	return (cnt);
}

int		ft_checks22b(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indminus == 1)
		cnt = cnt + ft_checks22b1(e);
	else if (e->indminus == 0)
		cnt = cnt + ft_checks22b2(e);
	return (cnt);
}

int		ft_checks22b1(t_numb *e)
{
	int		cnt;
	int		i;
	char	sn[7];

	ft_fullsn(sn);
	cnt = 0;
	if (e->pr > 0)
	{
		e->prbegi = e->pr;
		i = 0;
		while (i < 6 && e->pr > 0)
		{
			ft_putchar(sn[i]);
			cnt++;
			i++;
			(e->pr)--;
		}
		e->pr = e->prbegi;
	}
	cnt = cnt + ft_checks22b1a(e);
	return (cnt);
}
