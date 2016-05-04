/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 16:42:54 by syusof            #+#    #+#             */
/*   Updated: 2016/05/04 14:11:35 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n, t_numb *e)
{
	int		r1;

	r1 = 0;
	if (e->valzero == 0)
	{
		if (n == UINT_MAX)
		{
			ft_putstr("4294967295");
			r1 = 10;
		}
		else
			r1 = r1 + ft_putunbr1(n, e);
	}
	else if (e->valzero == 1)
	{
		if (e->indpr == 1)
			r1 = r1 + ft_putunbr42a(e);
		else
			r1 = r1 + ft_putunbr42b(e);
	}
	return (r1);
}

int	ft_putunbr42a(t_numb *e)
{
	int	r1;

	r1 = 0;
	while (e->w - e->pr > 0)
	{
		ft_putchar(' ');
		r1++;
		e->w--;
	}
	while ((e->pr) > 0)
	{
		ft_putchar('0');
		r1++;
		e->pr--;
	}
	return (r1);
}

int	ft_putunbr42b(t_numb *e)
{
	int	r1;

	r1 = 0;
	if (e->indminus == 0)
	{
		if (e->w == 0)
		{
			ft_putchar('0');
			r1++;
		}
		while (e->w)
		{
			e->w--;
			ft_putchar('0');
			r1++;
		}
	}
	else if (e->indminus == 1)
	{
		ft_putchar('0');
		r1++;
	}
	return (r1);
}

int	ft_putunbr1(unsigned int n, t_numb *e)
{
	int		r1;

	r1 = 0;
	if (n >= 10)
	{
		r1 = r1 + ft_putunbr(n / 10, e);
		r1 = r1 + ft_putunbr(n % 10, e);
	}
	else
	{
		ft_putchar(n + '0');
		r1++;
	}
	return (r1);
}

int	ft_putunbr2(unsigned int n, t_numb *e)
{
	int		r1;

	r1 = 0;
	r1 = r1 + ft_putunbr2a(n, e);
	return (r1);
}

int	ft_putunbr2a(unsigned int n, t_numb *e)
{
	int		r1;

	r1 = 0;
	if (n >= 10)
	{
		r1 = r1 + ft_putunbr2(n / 10, e);
		r1 = r1 + ft_putunbr2(n % 10, e);
	}
	else
	{
		ft_putchar(n + '0');
		r1++;
	}
	return (r1);
}

int	ft_putunbr2a1(unsigned int n, t_numb *e)
{
	int		i;
	int		r1;

	i = 0;
	r1 = 0;
	i = ft_count2(n);
	if (e->indzero == 1 && e->w > i && e->pr == 0 && e->indminus == 0)
	{
	}
	else if (e->pr < i)
	{
		ft_putchar('-');
		r1++;
	}
	return (r1);
}
