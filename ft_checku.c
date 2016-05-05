/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checku.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 00:43:58 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 14:43:35 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checku(t_numb *e)
{
	int		cnt;
	int		i;

	cnt = 0;
	i = ft_count2(e->u);
	if (e->u == 0)
		e->valzero = 1;
	if (e->indminus == 1)
		cnt = cnt + ft_checku1(e);
	else if (e->indminus == 0)
	{
		if (e->valzero == 1)
		{
			cnt = cnt + ft_putunbr(e->u, e);
		}
		else
		{
			cnt = cnt + ft_countu(e, e->u);
			cnt = cnt + ft_putunbr(e->u, e);
		}
	}
	ft_initialize(e);
	return (cnt);
}

int		ft_checku1(t_numb *e)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = ft_count2(e->u);
	if (e->indpr == 1)
		cnt = cnt + ft_checku1a(e);
	cnt = cnt + ft_putunbr(e->u, e);
	cnt = cnt + ft_checku1b(e);
	return (cnt);
}

int		ft_checku1a(t_numb *e)
{
	int	cnt;
	int	i;
	int	j;

	cnt = 0;
	i = ft_count2(e->u);
	j = 0;
	if (i > e->pr)
		cnt = cnt + ft_checku1a1(e);
	else if (i <= e->pr)
	{
		while (j < e->pr - i)
		{
			ft_putchar('0');
			cnt++;
			j++;
		}
	}
	return (cnt);
}

int		ft_checku1a1(t_numb *e)
{
	int	cnt;
	int	i;
	int	j;

	cnt = 0;
	i = ft_count2(e->u);
	j = 0;
	return (cnt);
}

int		ft_checku1b(t_numb *e)
{
	int	cnt;
	int	i;
	int	j;

	cnt = 0;
	i = ft_count2(e->u);
	if (i > e->pr)
		cnt = cnt + ft_checku1b1(e);
	else if (i <= e->pr)
	{
		j = 0;
		while (j < e->w - e->pr)
		{
			ft_putchar(' ');
			j++;
			cnt++;
		}
	}
	return (cnt);
}
