/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 21:41:15 by syusof            #+#    #+#             */
/*   Updated: 2016/05/04 18:01:16 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkc(t_numb *e)
{
	if (e->indzero == 0)
		return (ft_checkc1(e));
	else
	{
		return (ft_checkc2(e));
	}
	return (0);
}

int		ft_checkc1(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indminus == 1)
		return (ft_checkc1a(e));
	else
		return (ft_checkc1b(e));
}

int		ft_checkc1a(t_numb *e)
{
	int	cnt;

	cnt = 0;
	cnt++;
	ft_putchar(e->d);
	while ((e->w - 1) > 0)
	{
		cnt++;
		ft_putchar(' ');
		(e->w)--;
	}
	return (cnt);
}

int		ft_checkc1b(t_numb *e)
{
	int	cnt;

	cnt = 0;
	while ((e->w - 1) > 0)
	{
		cnt++;
		ft_putchar(' ');
		(e->w)--;
	}
	ft_putchar(e->d);
	cnt++;
	return (cnt);
}

int		ft_checkc2(t_numb *e)
{
	int		cnt;

	cnt = 0;
	if (e->w < 0)
		return (ft_checkc2a(e));
	else
		return (ft_checkc2b(e));
}

int		ft_checkc2a(t_numb *e)
{
	int	cnt;

	cnt = 0;
	ft_putchar(e->d);
	cnt++;
	while ((e->w - 1) > 0)
	{
		cnt++;
		ft_putchar('0');
		(e->w)--;
	}
	return (cnt);
}

int		ft_checkc2b(t_numb *e)
{
	int	cnt;

	cnt = 0;
	while ((e->w - 1) > 0)
	{
		cnt++;
		ft_putchar('0');
		(e->w)--;
	}
	ft_putchar(e->d);
	cnt++;
	return (cnt);
}
