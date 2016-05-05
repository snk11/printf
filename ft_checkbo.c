/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkbo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 03:41:10 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 16:03:43 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkbo(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indminus == 0)
		cnt = cnt + ft_checkbo42(e);
	else if (e->indminus == 1)
	{
		if (e->ul == 0 && e->pr == 0 && e->indpr == 1 && e->indsharp == 0)
		{
		}
		else
			cnt = cnt + ft_checkbo21(e);
	}
	if (e->s)
	{
		if (ft_strcmp(e->s, "1000000000000000000000") != 0)
		{
			free(e->s);
			e->s = NULL;
		}
	}
	return (cnt);
}

int		ft_checkbo42(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->ul == 0 && e->pr == 0 && e->indpr == 1 && e->indsharp == 0)
	{
		while (e->w)
		{
			ft_putchar(' ');
			e->w--;
			cnt++;
		}
	}
	else
		cnt = cnt + ft_checkbo1(e);
	return (cnt);
}

int		ft_checkbo1(t_numb *e)
{
	int	cnt;

	cnt = 0;
	e->s = ft_ltooct2(e->ul);
	e->g = ft_strlen(e->s);
	if (e->indzero == 1 && e->pr == 0)
	{
		while (e->w - e->g > 0)
		{
			ft_putchar('0');
			cnt++;
			e->w--;
		}
	}
	else
		cnt = cnt + ft_checkbo1a(e);
	if (e->indsharp == 1 && e->ul != 0 && e->pr == 0)
	{
		ft_putchar('0');
		cnt++;
	}
	ft_putstr(e->s);
	cnt = cnt + e->g;
	return (cnt);
}

int		ft_checkbo1a(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->pr >= e->g)
	{
		while (e->w - e->pr > 0)
		{
			ft_putchar(' ');
			cnt++;
			(e->w)--;
		}
		while ((e->pr - e->g) > 0)
		{
			ft_putchar('0');
			cnt++;
			(e->pr)--;
		}
	}
	else
		cnt = cnt + ft_checkbo1a1(e);
	return (cnt);
}

int		ft_checkbo1a1(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indsharp == 0)
	{
		while (e->w - e->g > 0)
		{
			ft_putchar(' ');
			cnt++;
			(e->w)--;
		}
	}
	else if (e->indsharp == 1)
	{
		while (e->w - e->g - 1 > 0)
		{
			ft_putchar(' ');
			cnt++;
			(e->w)--;
		}
	}
	return (cnt);
}
