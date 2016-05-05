/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkd_p2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:01:20 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 14:07:09 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkd1b1(t_numb *e)
{
	int	cnt;
	int	i;
	int	j;

	cnt = 0;
	i = ft_count(e->d);
	j = 0;
	while (j < e->w - i)
	{
		ft_putchar(' ');
		j++;
		cnt++;
	}
	return (cnt);
}

int		ft_countd(t_numb *e, int n)
{
	t_count *f;
	int		ret;

	ret = 0;
	f = (t_count*)malloc(sizeof(t_count));
	f->i = 0;
	f->neg = 0;
	if (n == -2147483648)
	{
		f->i = 11;
		f->neg = 1;
	}
	else
		ft_countd2(f, n);
	if (e->indzero == 1 && e->pr == 0)
		ret = ret + ft_countd3(e, f);
	else
		ret = ret + ft_countd4(e, f);
	free(f);
	f = NULL;
	return (ret);
}

void	ft_countd2(t_count *f, int n)
{
	if (n < 0)
	{
		f->i++;
		n = -n;
		f->neg = 1;
	}
	if (n >= 10)
	{
		while (n >= 10)
		{
			n = n / 10;
			f->i++;
		}
	}
	f->i++;
}

int		ft_countd3(t_numb *e, t_count *f)
{
	int		r1;

	r1 = 0;
	if (e->w > f->i)
		r1 = r1 + ft_countd342a(e, f);
	else if (e->w <= f->i)
		r1 = r1 + ft_countd342b(e, f);
	return (r1);
}

int		ft_countd342a(t_numb *e, t_count *f)
{
	int		r1;

	r1 = 0;
	if (f->neg == 1 || e->indminus == 1)
		r1 = r1 + ft_countd342a1(e, f);
	else if (e->w > f->i)
		r1 = r1 + ft_countd3a(e, f);
	return (r1);
}
