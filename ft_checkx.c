/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 02:42:08 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 14:46:11 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkx(t_numb *e)
{
	int	cnt;

	e->s = ft_ltohex(e->u);
	e->g = ft_strlen(e->s);
	cnt = 0;
	if (e->u == 0 && e->pr == 0 & e->indpr == 1)
	{
		while (e->w)
		{
			ft_putchar(' ');
			e->w--;
			cnt++;
		}
	}
	else if (e->indminus == 1)
		cnt = cnt + ft_checkx0(e);
	else if (e->indminus == 0)
		cnt = cnt + ft_checkx1(e);
	if (e->s)
	{
		free(e->s);
		e->s = NULL;
	}
	return (cnt);
}

int		ft_checkx0(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indsharp == 1 && e->u != 0)
	{
		ft_putchar('0');
		ft_putchar('x');
		cnt++;
		cnt++;
	}
	if (e->indzero == 1 && e->pr == 0)
		cnt = cnt + ft_checkx0a(e);
	else if (e->indsharp == 0)
	{
		ft_putstr(e->s);
		cnt = cnt + ft_checkx1a(e);
	}
	cnt = cnt + e->g;
	return (cnt);
}

int		ft_checkx0a(t_numb *e)
{
	int	cnt;

	cnt = 0;
	ft_putstr(e->s);
	if (e->indsharp == 1)
	{
		while (e->w - (e->g + 2) > 0)
		{
			ft_putchar(' ');
			cnt++;
			(e->w)--;
		}
	}
	else
	{
		while (e->w - e->g > 0)
		{
			ft_putchar(' ');
			cnt++;
			(e->w)--;
		}
	}
	return (cnt);
}

int		ft_checkx1(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indsharp == 1 && e->u != 0)
		cnt = cnt + ft_checkx142a(e);
	if (e->indzero == 1 && e->pr == 0)
		cnt = cnt + ft_checkx142b(e);
	else if (e->indsharp == 0)
		cnt = cnt + ft_checkx1a(e);
	ft_putstr(e->s);
	cnt = cnt + e->g;
	return (cnt);
}

int		ft_checkx142a(t_numb *e)
{
	int	cnt;
	int	i;

	cnt = 0;
	if (e->indzero == 0)
	{
		while (e->w - (e->g + 2) > 0)
		{
			ft_putchar(' ');
			cnt++;
			(e->w)--;
		}
	}
	ft_putchar('0');
	ft_putchar('x');
	cnt++;
	cnt++;
	i = 0;
	while (i < e->pr - e->g)
	{
		ft_putchar('0');
		cnt++;
		i++;
	}
	return (cnt);
}
