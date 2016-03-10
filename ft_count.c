/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 08:29:33 by syusof            #+#    #+#             */
/*   Updated: 2016/03/10 14:21:40 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int	ft_count(int n)
{
	int i;

	i = 0;
	if (n == -2147483648)
	{
		i = 11;
	}
	else
	{
		if (n < 0)
		{
			i++;
			n = -n;
		}
		if (n >= 10)
		{
			while (n >= 10)
			{
				n = n / 10;
				i++;
			}
		}
		i++;
	}
	return (i);
}

int	ft_countd(t_numb *e,int n)
{
	t_count *f;

	f = (t_count*)malloc(sizeof(t_count));
	f->i = 0;
	f->neg = 0;
	f->w = e->w;
	f->pr = e->pr;
	f->u = f->pr;
	f->v = f->w;
	ft_countd1(f,n);
	if (n == -2147483648)
		ft_countd1(f,n);
	else
		ft_countd2(f,n);
	if (e->indzero == 1 && f->pr == 0)
		ft_countd3(e,f);
	else
		ft_countd4(e,f);
	return (ft_countd5(e,f));
}

void 	ft_countd1(t_count *f,int n)
{
	if (n == -2147483648)
	{
		f->i = 11;
		f->neg = 1;
	}
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

void	ft_countd3(t_numb *e,t_count *f)
{
		if (f->w > f->i)
		{
			if (f->neg == 1)
			{
				ft_putchar('-');
				while((f->w - f->i) > 0)
				{
					ft_putchar('0');
					f->w--;
				}
			}
			else
				ft_countd3a(e,f);
		}
		else
		{
			if (e->indplus == 1)
				ft_putchar('+');
			if (e->indspace == 1)
				ft_putchar(' ');
		}
}

void	ft_countd3a(t_numb *e,t_count *f)
{
			if (f->neg == 1)
			{
				ft_putchar('-');
				while((f->w - f->i) > 0)
				{
					ft_putchar('0');
					f->w--;
				}
			}
			else
				ft_countd3a1(e,f);
}

void	ft_countd3a1(t_numb *e,t_count *f)
{
				if(e->indminus == 1)
					ft_countd3a1a(e,f);
				else
				{
					if (e->indplus == 1)
						f->w--;
					if (e->indplus == 1)
						ft_putchar('+');
					if (e->indspace == 1)
						f->w--;
					if (e->indspace == 1)
						ft_putchar(' ');
					while(f->w - f->i > 0)
					{
						ft_putchar('0');
						f->w--;
					}
				}
}


void	ft_countd3a1a(t_numb *e,t_count *f)
{
					if (e->indplus == 1)
						f->w--;
					if (e->indplus == 1)
						ft_putchar('+');
					if (e->indspace == 1)
						f->w--;
					if (e->indspace == 1)
						ft_putchar(' ');
					while(f->w - f->i > 0)
					{
						ft_putchar(' ');
						f->w--;
					}
}

void	ft_countd4(t_numb *e,t_count *f)
{
		if (f->pr >= f->i)
			ft_countd4a(e,f);
		else
		{
			if(e->indplus == 1)
				f->w--;
			if(e->indspace == 1 && e->indplus == 0 && f->neg == 0)
				ft_putchar(' ');
			while(f->w - f->i > 0)
			{
				ft_putchar(' ');
				f->w--;
			}
			if(e->indplus == 1 && f->neg == 0)
			{
				ft_putchar('+');
				f->w--;
			}
		}
}

void	ft_countd4a(t_numb *e,t_count *f)
{
			if (f->neg == 1)
				ft_countd4a1(e,f);
			else
			{
				while(f->w - f->pr > 0)
				{
					ft_putchar(' ');
					f->w--;
				}
				while((f->pr - f->i) > 0)
				{
					ft_putchar('0');
					f->pr--;
				}
			}
}

void	ft_countd4a1(t_numb *e,t_count *f)
{
				while(f->w - f->pr - 1 > 0)
				{
					ft_putchar(' ');
					f->w--;
				}
				ft_putchar('-');
				while((f->pr - f->i + 1) > 0)
				{
					ft_putchar('0');
					f->pr--;
				}
}

int	ft_countd5(t_numb *e,t_count *f)
{
	if (f->u > f->i)
	{
		if (f->v > f->u)
			return (f->v);
		if (f->neg == 1)
			return (f->u + 1);
		return (f->u);
	}
	if (f->v > f->i)
	{
		return (f->v);
	}
	if ((e->indplus == 1 && f->neg == 0) || (e->indspace == 1 && f->neg == 0))
		return (f->i + 1);
	e->w = f->w;
	e->pr = f->pr;
	return (f->i);
}

int	ft_countsd(short int n)
{
	int i;

	i = 0;
	if (n == -32768)
		return (6);
	else
	{
		if (n < 0)
		{
			i++;
			n = -n;
		}
		if (n >= 10)
		{
			while (n >= 10)
			{
				n = n / 10;
				i++;
			}
		}
		i++;
	}
	return (i);
}
int	ft_countl(long n)
{
	int i;

	i = 0;
	if (n == LONG_MIN)
		return (20);
	else
	{
		if (n < 0)
		{
			i++;
			n = -n;
		}
		if (n >= 10)
		{
			while (n >= 10)
			{
				n = n / 10;
				i++;
			}
		}
		i++;
	}
	return (i);
}

int	ft_countld(long int n)
{
	int i;

	i = 0;
	if (n == LONG_MIN)
		return (20);
	else
	{
		if (n < 0)
		{
			i++;
			n = -n;
		}
		if (n >= 10)
		{
			while (n >= 10)
			{
				n = n / 10;
				i++;
			}
		}
		i++;
	}
	return (i);
}

int	ft_countlld(long long n)
{
	int i;

	i = 0;
	if (n == LLONG_MIN)
		return (20);
	else
	{
		if (n < 0)
		{
			i++;
			n = -n;
		}
		if (n >= 10)
		{
			while (n >= 10)
			{
				n = n / 10;
				i++;
			}
		}
		i++;
	}
	return (i);
}
int	ft_countu(int w,int pr, int zero,t_numb *e,unsigned int n)
{
	int i;
	int v;
	int u;
	int neg;
	int minus;

	minus = 0;
	if (w < 0)
	{
		w = -w;
		minus = 1;
	}
	i = 0;
	neg = 0;
	u = pr;
	v = w;

	i = 0;
	if (n == UINT_MAX)
		i = 10;
	else
	{
		if (n >= 10)
		{
			while (n >= 10)
			{
				n = n / 10;
				i++;
			}
		}
		i++;
	}
	if (zero == 1 && pr == 0)
	{
//		if (neg == 1)
//			ft_putchar('-');
		if (w > i)
		{
			if (neg == 1)
			{
				ft_putchar('-');
				while((w - i) > 0)
				{
					ft_putchar('0');
					w--;
				}
			}
			else
			{
				if(minus == 1)
				{
					if (e->indplus == 1)
						w--;
					if (e->indplus == 1)
						ft_putchar('+');
//					if (e.indspace == 1)
//						w--;
//					if (e.indspace == 1)
//						ft_putchar(' ');
					while(w - i > 0)
					{
						ft_putchar(' ');
						w--;
					}
				}
				else
				{
					if (e->indplus == 1)
						w--;
					if (e->indplus == 1)
						ft_putchar('+');
//					if (e.indspace == 1)
//						w--;
//					if (e.indspace == 1)
//						ft_putchar(' ');
					while(w - i > 0)
					{
						ft_putchar('0');
						w--;
					}
				}
			}
		}
		else
		{
			if (e->indplus == 1)
				ft_putchar('+');
//			if (e.indspace == 1)
//				ft_putchar(' ');
		}
	}
	else
	{
//		if (neg == 1)
//			ft_putchar('-');
		if (pr >= i)
		{
			if (neg == 1)
			{
				while(w - pr - 1 > 0)
				{
					ft_putchar(' ');
					w--;
				}
				ft_putchar('-');
				while((pr - i + 1) > 0)
				{
					ft_putchar('0');
					pr--;
				}
			}
			else
			{
				while(w - pr > 0)
				{
					ft_putchar(' ');
					w--;
				}
				while((pr - i) > 0)
				{
					ft_putchar('0');
					pr--;
				}
			}
		}
		else
		{
//			if(e->indplus == 1)
//				w--;
//			if(e.indspace == 1 && e.indplus == 0 && neg == 0)
//				ft_putchar(' ');
			while(w - i > 0)
			{
				ft_putchar(' ');
				w--;
			}
//			if(e->indplus == 1 && neg == 0)
//				ft_putchar('+');
		}
	}
	if (u > i)
	{
		if (v > u)
			return (v);
		if (neg == 1)
			return (u + 1);
		return (u);
	}
	if (v > i)
	{
		return (v);
	}
//	if ((e.indplus == 1 && neg == 0) || (e.indspace == 1 && neg == 0))
//		return (i + 1);
	return (i);
}

int	ft_countus(unsigned short n)
{
	int i;
	unsigned short c;

	c = 0;
	i = 0;
	if (n == USHRT_MAX)
		return (5);
	else
	{
		if (n >= 10)
		{
			while (n >= 10)
			{
				n = n / 10;
				i++;
			}
		}
		i++;
	}
	return (i);
}

int	ft_countul(unsigned long n)
{
	int i;
	unsigned long c;

	c = 0;
	i = 0;
	if (n == ULONG_MAX)
		return (20);
	else
	{
		if (n >= 10)
		{
			while (n >= 10)
			{
				n = n / 10;
				i++;
			}
		}
		i++;
	}
	return (i);
}

int	ft_countull(unsigned long long n)
{
	int i;
	unsigned long long c;

	c = 0;
	i = 0;
	if (n == ULLONG_MAX)
		return (20);
	else
	{
		if (n >= 10)
		{
			while (n >= 10)
			{
				n = n / 10;
				i++;
			}
		}
		i++;
	}
	return (i);
}

int	ft_countuc(unsigned char n)
{
	int i;
	unsigned char c;

	c = 0;
	i = 0;
	if (n == ULONG_MAX)
		return (20);
	else
	{
		if (n >= 10)
		{
			while (n >= 10)
			{
				n = n / 10;
				i++;
			}
		}
		i++;
	}
	return (i);
}
