/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 20:30:57 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 14:07:26 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkd(t_numb *e)
{
	int		cnt;
	int		i;

	cnt = 0;
	i = ft_count(e->d);
	if (e->d == 0)
		e->valzero = 1;
	if (e->indminus == 1)
		cnt = cnt + ft_checkd1(e);
	else if (e->indminus == 0)
	{
		if (e->valzero == 1)
		{
			cnt = cnt + ft_putnbr(e->d, e);
		}
		else
		{
			cnt = cnt + ft_countd(e, e->d);
			cnt = cnt + ft_putnbr(e->d, e);
		}
	}
	ft_initialize(e);
	return (cnt);
}

int		ft_checkd1(t_numb *e)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = ft_count(e->d);
	if (e->d < 0)
	{
		ft_putchar('-');
		cnt++;
	}
	if ((e->indplus == 1 && e->indminus == 0 && e->d < 0)
			|| (e->indplus == 1 && e->indminus == 1 && e->d > 0))
		e->w--;
	if ((e->indplus == 1 && e->indminus == 0 && e->d < 0)
			|| (e->indplus == 1 && e->indminus == 1 && e->d > 0))
	{
		ft_putchar('+');
		cnt++;
	}
	if (e->indpr == 1)
		cnt = cnt + ft_checkd1a(e);
	cnt = cnt + ft_putnbr(e->d, e);
	cnt = cnt + ft_checkd1b(e);
	return (cnt);
}

int		ft_checkd1a(t_numb *e)
{
	int	cnt;
	int	i;
	int	j;

	cnt = 0;
	i = ft_count(e->d);
	j = 0;
	if (i > e->pr)
		cnt = cnt + ft_checkd1a1(e);
	else if (i <= e->pr)
	{
		while (j < (e->pr - i))
		{
			ft_putchar('0');
			cnt++;
			j++;
		}
	}
	return (cnt);
}

int		ft_checkd1a1(t_numb *e)
{
	int	cnt;
	int	i;
	int	j;

	cnt = 0;
	i = ft_count(e->d);
	j = 0;
	return (cnt);
}

int		ft_checkd1b(t_numb *e)
{
	int	cnt;
	int	i;
	int	j;

	cnt = 0;
	i = ft_count(e->d);
	if (i > e->pr)
		cnt = cnt + ft_checkd1b1(e);
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
