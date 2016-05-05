/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_altprime_p2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 13:38:49 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 13:39:49 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_altprime2a1(char *str, t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indminus == 1)
		cnt = cnt + ft_altprime2a1a(str, e);
	else
	{
		while ((e->w - 1) > 0)
		{
			cnt++;
			ft_putchar(' ');
			(e->w)--;
		}
		if (*str)
		{
			ft_putchar(*str);
			cnt++;
		}
	}
	return (cnt);
}

int		ft_altprime2a1a(char *str, t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (*str)
	{
		ft_putchar(*str);
		cnt++;
	}
	while ((e->w - 1) > 0)
	{
		cnt++;
		ft_putchar(' ');
		(e->w)--;
	}
	return (cnt);
}

int		ft_altprime2a2(char *str, t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indminus == 1)
		cnt = cnt + ft_altprime2a2a(str, e);
	else
	{
		while ((e->w - 1) > 0)
		{
			cnt++;
			ft_putchar('0');
			(e->w)--;
		}
		if (*str)
		{
			ft_putchar(*str);
			cnt++;
		}
	}
	return (cnt);
}

int		ft_altprime2a2a(char *str, t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (*str)
	{
		ft_putchar(*str);
		cnt++;
	}
	while ((e->w - 1) > 0)
	{
		cnt++;
		ft_putchar(' ');
		(e->w)--;
	}
	return (cnt);
}
