/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checku_p2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:40:59 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 14:43:05 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checku1b1(t_numb *e)
{
	int	cnt;
	int	i;
	int	j;

	cnt = 0;
	i = ft_count2(e->u);
	j = 0;
	while (j < e->w - i)
	{
		ft_putchar(' ');
		j++;
		cnt++;
	}
	return (cnt);
}

int		ft_countu(t_numb *e, unsigned int n)
{
	t_count *f;
	int		ret;

	ret = 0;
	f = (t_count*)malloc(sizeof(t_count));
	f->i = 0;
	f->neg = 0;
	if (n == UINT_MAX)
		f->i = 10;
	else
		ft_countu2(f, n);
	if (e->indzero == 1 && e->pr == 0)
		ret = ret + ft_countu3(e, f);
	else
		ret = ret + ft_countu4(e, f);
	free(f);
	f = NULL;
	return (ret);
}

void	ft_countu2(t_count *f, unsigned int n)
{
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

int		ft_countu3(t_numb *e, t_count *f)
{
	int		r1;

	r1 = 0;
	if (e->w > f->i)
		r1 = r1 + ft_countu342a(e, f);
	else if (e->w <= f->i)
		r1 = r1 + ft_countu342b(e, f);
	return (r1);
}

int		ft_countu342a(t_numb *e, t_count *f)
{
	int		j;
	int		r1;

	r1 = 0;
	j = 0;
	if (f->neg == 1 || e->indminus == 1)
		r1 = r1 + ft_countu342a1(e, f);
	else if (e->w > f->i)
		r1 = r1 + ft_countu3a(e, f);
	return (r1);
}
