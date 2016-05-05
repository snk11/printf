/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checko.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 03:28:36 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 14:12:12 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checko(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indminus == 0)
		cnt = cnt + ft_checko42(e);
	else if (e->indminus == 1)
	{
		if (e->u == 0 && e->pr == 0 && e->indpr == 1 && e->indsharp == 0)
		{
		}
		else
			cnt = cnt + ft_checko21(e);
	}
	free(e->s);
	e->s = NULL;
	return (cnt);
}

int		ft_checko42(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->u == 0 && e->pr == 0 && e->indpr == 1 && e->indsharp == 0)
	{
		while (e->w)
		{
			ft_putchar(' ');
			e->w--;
			cnt++;
		}
	}
	else
		cnt = cnt + ft_checko1(e);
	return (cnt);
}

int		ft_checko1(t_numb *e)
{
	int	cnt;

	cnt = 0;
	e->s = ft_ltooct(e->u);
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
		cnt = cnt + ft_checko1a(e);
	if (e->indsharp == 1 && e->u != 0 && e->pr == 0)
	{
		ft_putchar('0');
		cnt++;
	}
	ft_putstr(e->s);
	cnt = cnt + e->g;
	return (cnt);
}

int		ft_checko1a(t_numb *e)
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
		cnt = cnt + ft_checko1a1(e);
	return (cnt);
}

int		ft_checko1a1(t_numb *e)
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
