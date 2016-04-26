/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 20:30:57 by syusof            #+#    #+#             */
/*   Updated: 2016/04/26 16:59:27 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkd(char *str,t_numb *e)
{
	int cnt;
	int	j;
	int		i;

	cnt = 0;
	i = ft_count(e->d);
	if (e->d == 0)
		e->valzero = 1;
	if(e->indminus == 1)
		cnt = cnt + ft_checkd1(e);
	else if (e->indminus == 0)
	{
		if(e->valzero == 1)
		{
			cnt = cnt + ft_putnbr(e->d,e);
		}
		else
		{
			cnt = cnt + ft_countd(e,e->d);
			cnt = cnt + ft_putnbr(e->d,e);
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
	if ((e->indplus == 1 && e->indminus == 0 && e->d < 0) || (e->indplus == 1 && e->indminus == 1 && e->d > 0) )
		e->w--;
	if ((e->indplus == 1 && e->indminus == 0 && e->d < 0) || (e->indplus == 1 && e->indminus == 1 && e->d > 0) )
	{
		ft_putchar('+');
		cnt++;
	}
	if (e->indpr == 1)
		cnt = cnt + ft_checkd1a(e);
	cnt = cnt + ft_putnbr(e->d,e);
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
			while(j < (e->pr - i))
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
		while(j < e->w - e->pr)
		{
			ft_putchar(' ');
			j++;
			cnt++;
		}
	}
	return (cnt);
}

int		ft_checkd1b1(t_numb *e)
{
	int	cnt;
	int	i;
	int	j;

	cnt = 0;
	i = ft_count(e->d);
		j = 0;
		while(j < e->w - i)
		{
			ft_putchar(' ');
			j++;
			cnt++;
		}
	return (cnt);
}

int	ft_countd(t_numb *e,int n)
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
		ft_countd2(f,n);
	if (e->indzero == 1 && e->pr == 0)
		ret = ret + ft_countd3(e,f);
	else
		ret = ret + ft_countd4(e,f);
	free(f);
	f = NULL;
	return (ret);
}

void 	ft_countd2(t_count *f,int n)
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

int		ft_countd3(t_numb *e,t_count *f)
{
	int		j;
	int		r1;
	r1 = 0;
	if (e->w > f->i)
		r1 = r1 + ft_countd342a(e,f);
	else if (e->w <= f->i)
		r1 = r1 + ft_countd342b(e,f);
	return (r1);
}


int		ft_countd342a(t_numb *e,t_count *f)
{
	int		j;
	int		r1;

	r1 = 0;
		if (f->neg == 1 || e->indminus == 1)
			r1 = r1 +ft_countd342a1(e,f);
		else if (e->w > f->i)
			r1 = r1 +ft_countd3a(e,f);
	return (r1);
}

int		ft_countd342a1(t_numb *e,t_count *f)
{
	int		j;
	int		r1;

	r1 = 0;
	j = 0;
	if (e->indpr == 1)
	{
		while (j < e->w - f->i)
		{
			ft_putchar(' ');
			r1++;
			j++;
		}
	}
			r1 = r1 +ft_countd342a1a(e,f);
			if (e->indzero == 1 && e->indpr == 0)
			{
				j = 0;
				while(j < e->w - f->i)
				{
					ft_putchar('0');
					r1++;
					j++;
				}
			}
	return (r1);
}

int		ft_countd342a1a(t_numb *e,t_count *f)
{
	int		j;
	int		r1;

	r1 = 0;
			ft_putchar('-');
			r1++;
	return (r1);
}

int		ft_countd342b(t_numb *e,t_count *f)
{
	int		j;
	int		r1;

	r1 = 0;
		if (e->indminus == 1 || f->neg == 1)
		{
			ft_putchar('-');
			r1++;
		}
		if (e->indplus == 1 && e->indminus == 0)
		{
			ft_putchar('+');
			r1++;
		}
		if (e->indspace == 1 && f->neg == 0)
		{
			ft_putchar(' ');
			r1++;
		}
	return (r1);
}

int	ft_countd3a(t_numb *e,t_count *f)
{
	int r1;

	r1 = 0;
	if (f->neg == 1)
	{
		ft_putchar('-');
		r1++;
		while((e->w - f->i) > 0)
		{
			ft_putchar('0');
			r1++;
			e->w--;
		}
	}
	else
		r1 =  r1 + ft_countd3a1(e,f);
	return (r1);
}

int	ft_countd3a1(t_numb *e,t_count *f)
{
	int	r1;

	r1 = 0;
	if(e->indminus == 1)
		r1 = r1 + ft_countd3a1a(e,f);
	else
	{
		if (e->indplus == 1)
			e->w--;
		if (e->indplus == 1)
		{
			ft_putchar('+');
			r1++;
		}
		r1 = r1 + ft_countd3a142(e,f);
	}
	return (r1);
}


int	ft_countd3a142(t_numb *e,t_count *f)
{
	int	r1;
	r1 = 0;
		if (e->indspace == 1)
			e->w--;
		if (e->indspace == 1)
		{
			ft_putchar(' ');
			r1++;
		}
		if(e->indpr == 1)
		{
			while(e->w - f->i > 0)
			{
				ft_putchar(' ');
				r1++;
				e->w--;
			}
		}
		else if(e->indpr == 0)
		{
			while(e->w - f->i > 0)
			{
				ft_putchar('0');
				r1++;
				e->w--;
			}
		}
	return (r1);
}


int	ft_countd3a1a(t_numb *e,t_count *f)
{
	int	r1;

	r1 = 0;
	if (e->indplus == 1 && e->indminus == 0)
		e->w--;
	if (e->indplus == 1 && e->indminus == 0)
	{
		ft_putchar('+');
		r1++;
	}
	if (e->indspace == 1)
		e->w--;
	if (e->indspace == 1)
	{
		ft_putchar(' ');
		r1++;
	}
	while(e->w - f->i > 0)
	{
		ft_putchar(' ');
		r1++;
		e->w--;
	}
	return (r1);
}

int	ft_countd4(t_numb *e,t_count *f)
{
	int r1;

	r1 = 0;
	if (e->pr >= f->i)
		r1 = r1 + ft_countd4a(e,f);
	else
	{
		if(e->indplus == 1)
			e->w--;
		if(e->indspace == 1 && e->indplus == 0 && f->neg == 0 && e->w < f->i)
		{
			ft_putchar(' ');
			r1++;
		}
		if (f->neg == 1 || e->indminus == 1)
			r1 = r1 + ft_countd4a2(e,f);
		else
			r1 = r1 + ft_countd442(e,f);
	}
	return (r1);
}

int	ft_countd442(t_numb *e,t_count *f)
{
	int r1;

	r1 = 0;
			while(e->w - f->i > 0)
			{
				ft_putchar(' ');
				r1++;
				e->w--;
			}
			if(e->indplus == 1 && f->neg == 0 && e->indminus == 0)
			{
				ft_putchar('+');
				r1++;
				e->w--;
			}
	return (r1);
}

int	ft_countd4a(t_numb *e,t_count *f)
{
	int		r1;

	r1 = 0;
	if (f->neg == 1)
		r1 = r1 + ft_countd4a1(e,f);
	else
	{
		if (e->indplus == 1)
			e->w--;
		if (e->indspace == 1)
			e->w--;
		if (e->indspace == 1)
		{
			ft_putchar(' ');
			r1++;
		}
		r1 = r1 + ft_countd4a42(e,f);
	}
	return (r1);
}


int	ft_countd4a42(t_numb *e,t_count *f)
{
	int		r1;

	r1 = 0;
		while(e->w - e->pr > 0)
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
		while((e->pr - f->i) > 0)
		{
			ft_putchar('0');
			r1++;
			e->pr--;
		}
	return (r1);
}

int	ft_countd4a1(t_numb *e,t_count *f)
{
	int	r1;

	r1 = 0;
	while(e->w - e->pr - 1 > 0)
	{
		ft_putchar(' ');
		r1++;
		e->w--;
	}
	ft_putchar('-');
	r1++;
	while((e->pr - f->i + 1) > 0)
	{
		ft_putchar('0');
		r1++;
		e->pr--;
	}
	return (r1);
}

int	ft_countd4a2(t_numb *e,t_count *f)
{
	int	r1;

	r1 = 0;
	if (e->indplus == 1)
	{
		while(e->w - f->i + 1  > 0)
		{
			ft_putchar(' ');
			r1++;
			e->w--;
		}
	}
	else
	{
		while(e->w - f->i > 0)
		{
			ft_putchar(' ');
			r1++;
			e->w--;
		}
	}
	ft_putchar('-');
	r1++;
	while((e->pr - f->i + 1) > 0)
	{
		ft_putchar('0');
		r1++;
		e->pr--;
	}
	return (r1);
}

