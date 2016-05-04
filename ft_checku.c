/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checku.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 00:43:58 by syusof            #+#    #+#             */
/*   Updated: 2016/05/04 17:34:39 by syusof           ###   ########.fr       */
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

int		ft_countu342a1(t_numb *e, t_count *f)
{
	int		j;
	int		r1;

	r1 = 0;
	r1 = r1 + ft_countu342a1a(e, f);
	if (e->indzero == 1 && e->indpr == 0)
	{
		j = 0;
		while (j < e->w - f->i)
		{
			ft_putchar('0');
			r1++;
			j++;
		}
	}
	return (r1);
}

int		ft_countu342a1a()
{
	int		r1;

	r1 = 0;
	ft_putchar('-');
	r1++;
	return (r1);
}

int		ft_countu342b()
{
	int		r1;

	r1 = 0;
	return (r1);
}

int		ft_countu3a(t_numb *e, t_count *f)
{
	int r1;

	r1 = 0;
	r1 = r1 + ft_countu3a1(e, f);
	return (r1);
}

int		ft_countu3a1(t_numb *e, t_count *f)
{
	int	r1;

	r1 = 0;
	if (e->indminus == 1)
		r1 = r1 + ft_countu3a1a(e, f);
	else
	{
		r1 = r1 + ft_countu3a142(e, f);
	}
	return (r1);
}

int		ft_countu3a142(t_numb *e, t_count *f)
{
	int	r1;

	r1 = 0;
	if (e->indpr == 0)
	{
		while (e->w - f->i > 0)
		{
			ft_putchar('0');
			r1++;
			e->w--;
		}
	}
	else if (e->indpr == 1)
	{
		while (e->w - f->i > 0)
		{
			ft_putchar(' ');
			r1++;
			e->w--;
		}
	}
	return (r1);
}

int		ft_countu3a1a(t_numb *e, t_count *f)
{
	int	r1;

	r1 = 0;
	while (e->w - f->i > 0)
	{
		ft_putchar(' ');
		r1++;
		e->w--;
	}
	return (r1);
}

int		ft_countu4(t_numb *e, t_count *f)
{
	int r1;

	r1 = 0;
	if (e->pr >= f->i)
		r1 = r1 + ft_countu4a(e, f);
	else
	{
		if (f->neg == 1 || e->indminus == 1)
			r1 = r1 + ft_countu4a2(e, f);
		else
			r1 = r1 + ft_countu442(e, f);
	}
	return (r1);
}

int		ft_countu442(t_numb *e, t_count *f)
{
	int r1;

	r1 = 0;
	while (e->w - f->i > 0)
	{
		ft_putchar(' ');
		r1++;
		e->w--;
	}
	return (r1);
}

int		ft_countu4a(t_numb *e, t_count *f)
{
	int		r1;

	r1 = 0;
	{
		r1 = r1 + ft_countu4a42(e, f);
	}
	return (r1);
}

int		ft_countu4a42(t_numb *e, t_count *f)
{
	int		r1;

	r1 = 0;
	while (e->w - e->pr > 0)
	{
		ft_putchar(' ');
		r1++;
		e->w--;
	}
	while ((e->pr - f->i) > 0)
	{
		ft_putchar('0');
		r1++;
		e->pr--;
	}
	return (r1);
}

int		ft_countu4a2(t_numb *e, t_count *f)
{
	int	r1;

	r1 = 0;
	r1 = r1 + ft_countu4a2a(e, f);
	ft_putchar('-');
	r1++;
	while ((e->pr - f->i + 1) > 0)
	{
		ft_putchar('0');
		r1++;
		e->pr--;
	}
	return (r1);
}

int		ft_countu4a2a(t_numb *e, t_count *f)
{
	int	r1;

	r1 = 0;
	if (e->indplus == 1)
	{
		while (e->w - f->i + 1 > 0)
		{
			ft_putchar(' ');
			r1++;
			e->w--;
		}
	}
	else
	{
		while (e->w - f->i > 0)
		{
			ft_putchar(' ');
			r1++;
			e->w--;
		}
	}
	return (r1);
}
