/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks_p4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:28:18 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 14:35:26 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checks1b1a(t_numb *e)
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

int		ft_checks1b2(t_numb *e)
{
	int	cnt;
	int	i;

	cnt = 0;
	e->g = ft_strlen(e->s);
	cnt = cnt + ft_checks1b2a(e);
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

int		ft_checks1b2a(t_numb *e)
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

int		ft_checks2(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->pr > 6)
		e->pr = 6;
	if (e->w == 0 && e->pr == 0 && e->indpr == 0)
		cnt = cnt + ft_checks2a(e);
	else if (e->indpr == 1)
		cnt = cnt + ft_checks2b(e);
	else if (e->indpr == 0)
		cnt = cnt + ft_checks2c(e);
	return (cnt);
}

int		ft_checks2a(void)
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
