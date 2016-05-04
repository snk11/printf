/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 16:55:06 by syusof            #+#    #+#             */
/*   Updated: 2016/05/04 13:51:03 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, t_numb *e)
{
	int		r1;

	r1 = 0;
	if (e->valzero == 0)
	{
		if (n == -2147483648)
		{
			{
				ft_putstr("2147483648");
				r1 = 10;
			}
		}
		else
			r1 = r1 + ft_putnbr1(n, e);
	}
	else if (e->valzero == 1)
		r1 = r1 + ft_putnbr42(e);
	return (r1);
}

int	ft_putnbr42(t_numb *e)
{
	int	r1;

	r1 = 0;
	if (e->indpr == 1)
		r1 = r1 + ft_putnbr42a(e);
	else
	{
		if (e->indminus == 0)
		{
			if (e->indplus == 1)
				e->w--;
			if (e->indspace == 1)
				e->w--;
			r1 = r1 + ft_putnbr42b(e);
		}
		else if (e->indminus == 1)
		{
			ft_putchar('0');
			r1++;
		}
	}
	return (r1);
}

int	ft_putnbr42a(t_numb *e)
{
	int	r1;

	r1 = 0;
	if (e->indplus == 1)
		e->w--;
	while (e->w - e->pr > 0)
	{
		ft_putchar(' ');
		r1++;
		e->w--;
	}
	if (e->indplus == 1 && e->indminus == 0)
	{
		ft_putchar('+');
		r1++;
	}
	while ((e->pr) > 0)
	{
		ft_putchar('0');
		r1++;
		e->pr--;
	}
	return (r1);
}

int	ft_putnbr42b(t_numb *e)
{
	int	r1;

	r1 = 0;
	if (e->indspace == 1)
	{
		ft_putchar(' ');
		r1++;
	}
	if (e->indplus == 1 && e->indminus == 0)
	{
		ft_putchar('+');
		r1++;
	}
	if (e->w < 0)
	{
		ft_putchar('0');
		r1++;
	}
	while (e->w > 0)
	{
		e->w--;
		ft_putchar('0');
		r1++;
	}
	return (r1);
}

int	ft_putnbr1(int n, t_numb *e)
{
	int		i;
	int		r1;

	i = 0;
	r1 = 0;
	i = ft_count(n);
	if (n < 0)
	{
		if (e->indzero == 1 && e->w > i && e->pr == 0 && e->indminus == 0)
		{
		}
		n = -n;
	}
	if (n >= 10)
	{
		r1 = r1 + ft_putnbr(n / 10, e);
		r1 = r1 + ft_putnbr(n % 10, e);
	}
	else
	{
		ft_putchar(n + '0');
		r1++;
	}
	return (r1);
}

int	ft_putnbr2(int n, t_numb *e)
{
	int		i;
	int		j;
	int		r1;

	i = 0;
	r1 = 0;
	i = ft_count(n);
	if (n == -2147483648)
	{
		{
			ft_putstr("-2147483648");
			r1 = 11;
		}
	}
	else
		r1 = r1 + ft_putnbr2a(n, e);
	return (r1);
}

int	ft_putnbr2a(int n, t_numb *e)
{
	int		r1;

	r1 = 0;
	if (n < 0)
	{
		r1 = r1 + ft_putnbr2a1(n, e);
		n = -n;
	}
	if (n >= 10)
	{
		r1 = r1 + ft_putnbr2(n / 10, e);
		r1 = r1 + ft_putnbr2(n % 10, e);
	}
	else
	{
		ft_putchar(n + '0');
		r1++;
	}
	return (r1);
}

int	ft_putnbr2a1(int n, t_numb *e)
{
	int		i;
	int		r1;

	i = 0;
	r1 = 0;
	i = ft_count(n);
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
