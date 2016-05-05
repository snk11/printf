/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks_p5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:28:25 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 14:34:59 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fullsn(char *sn)
{
	sn[0] = '(';
	sn[1] = 'n';
	sn[2] = 'u';
	sn[3] = 'l';
	sn[4] = 'l';
	sn[5] = ')';
	sn[6] = 0;
}

int		ft_checks2b(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indminus == 1)
		cnt = cnt + ft_checks2b1(e);
	else if (e->indminus == 0)
		cnt = cnt + ft_checks2b2(e);
	return (cnt);
}

int		ft_checks2b1(t_numb *e)
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
	cnt = cnt + ft_checks2b1a(e);
	return (cnt);
}

int		ft_checks2b1a(t_numb *e)
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

int		ft_checks2b2(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indzero == 1)
		cnt = cnt + ft_checks2b2a(e);
	else
		cnt = cnt + ft_checks2b2b(e);
	return (cnt);
}
