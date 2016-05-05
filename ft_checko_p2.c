/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checko_p2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:09:11 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 14:11:51 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checko21(t_numb *e)
{
	int	cnt;

	cnt = 0;
	e->s = ft_ltooct(e->u);
	e->g = ft_strlen(e->s);
	if (e->indsharp == 1 && e->u != 0 && e->pr == 0)
	{
		ft_putchar('0');
		cnt++;
	}
	if (e->indsharp == 1)
	{
		ft_putstr(e->s);
		cnt = cnt + ft_checko21a(e);
	}
	if (e->indsharp == 0)
	{
		cnt = cnt + ft_checko21a(e);
	}
	cnt = cnt + e->g;
	return (cnt);
}

int		ft_checko21a(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->w >= e->g && e->indsharp == 0)
		cnt = cnt + ft_checko21a42a(e);
	else if (e->pr >= e->g && e->indsharp == 0)
		cnt = cnt + ft_checko21a42b(e);
	else if (e->indsharp == 0)
	{
		ft_putstr(e->s);
		cnt = cnt + ft_checko21a1(e);
	}
	else if (e->indsharp == 1)
		cnt = cnt + ft_checko21a1(e);
	return (cnt);
}

int		ft_checko21a42a(t_numb *e)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	cnt = cnt + ft_checko21a42a1(e);
	if (e->pr >= e->g)
	{
		while (e->w - e->pr > 0)
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

int		ft_checko21a42a1(t_numb *e)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (i < e->pr - e->g)
	{
		ft_putchar('0');
		cnt++;
		i++;
	}
	ft_putstr(e->s);
	return (cnt);
}

int		ft_checko21a42b(t_numb *e)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
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
	ft_putstr(e->s);
	return (cnt);
}
