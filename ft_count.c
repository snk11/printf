/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 08:29:33 by syusof            #+#    #+#             */
/*   Updated: 2016/03/21 20:45:36 by syusof           ###   ########.fr       */
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

int	ft_countu(t_numb *e,unsigned int n)
{
	t_count *f;
	int ret;

	f = (t_count*)malloc(sizeof(t_count));
	f->i = 0;
	f->minus = 0;
	f->neg = 0;
	f->w = e->w;
	f->pr = e->pr;
	f->u = f->pr;
	f->v = f->w;
	ft_countud1(f);
	if (n == UINT_MAX)
		f->i = 10;
	else
		ft_countud2(f,n);
	if (e->indzero == 1 && f->pr == 0)
		ft_countud3(e,f);
	else
		ft_countud4(e,f);
	ret = (ft_countud5(e,f));
	free(f);
	f = NULL;
	return (ret);
}

void 	ft_countud1(t_count *f)
{
	if (f->w < 0)
	{
		f->w = -(f->w);
		f->minus = 1;
	}
}

void 	ft_countud2(t_count *f,unsigned int n)
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

void	ft_countud3(t_numb *e,t_count *f)
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
		}
}

void	ft_countud3a(t_numb *e,t_count *f)
{
			if (f->minus == 1)
				ft_countud3a0(e,f);
			else
				ft_countud3a1(e,f);
}

void	ft_countud3a0(t_numb *e,t_count *f)
{
					if (e->indplus == 1)
						f->w--;
					if (e->indplus == 1)
						ft_putchar('+');
					while(f->w - f->i > 0)
					{
						ft_putchar(' ');
						f->w--;
					}
}

void	ft_countud3a1(t_numb *e,t_count *f)
{
						if (e->indplus == 1)
						f->w--;
					if (e->indplus == 1)
						ft_putchar('+');
					while(f->w - f->i > 0)
					{
						ft_putchar('0');
						f->w--;
				}
}

void	ft_countud4(t_numb *e,t_count *f)
{
		if (f->pr >= f->i)
			ft_countd4a(e,f);
		else
		{
			while(f->w - f->i > 0)
			{
				ft_putchar(' ');
				f->w--;
			}
		}
}

void	ft_countud4a(t_numb *e,t_count *f)
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

void	ft_countud4a1(t_numb *e,t_count *f)
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

int	ft_countud5(t_numb *e,t_count *f)
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
	e->w = f->w;
	e->pr = f->pr;
	return (f->i);
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
