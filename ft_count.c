/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 08:29:33 by syusof            #+#    #+#             */
/*   Updated: 2016/02/10 15:44:50 by syusof           ###   ########.fr       */
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

int	ft_countd(int w,int pr,t_numb *e,int n)
{
	int i;
	int v;
	int u;
	int neg;

	i = 0;
/*
					printf("indpr= %d\n",e->indpr);
					printf("indzero= %d\n",e->indzero);
					printf("indplus= %d\n",e->indplus);
					printf("indspace= %d\n",e->indspace);
					printf("indsharp= %d\n",e->indsharp);
					printf("indminus= %d\n",e->indminus);
*/
	neg = 0;
	u = pr;
	v = w;
	if (n == -2147483648)
	{
		i = 11;
		neg = 1;
	}
	else
	{
		if (n < 0)
		{
			i++;
			n = -n;
			neg = 1;
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
	//	printf("i =%d \n",i);
	//	printf("zero =%d \n",zero);
	if (e->indzero == 1 && pr == 0)
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
				if(e->indminus == 1)
				{
					if (e->indplus == 1)
						w--;
					if (e->indplus == 1)
						ft_putchar('+');
					if (e->indspace == 1)
						w--;
					if (e->indspace == 1)
						ft_putchar(' ');
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
					if (e->indspace == 1)
						w--;
					if (e->indspace == 1)
						ft_putchar(' ');
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
			if (e->indspace == 1)
				ft_putchar(' ');
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
			if(e->indplus == 1)
				w--;
			if(e->indspace == 1 && e->indplus == 0 && neg == 0)
				ft_putchar(' ');
			while(w - i > 0)
			{
				ft_putchar(' ');
				w--;
			}
			if(e->indplus == 1 && neg == 0)
				ft_putchar('+');
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
	if ((e->indplus == 1 && neg == 0) || (e->indspace == 1 && neg == 0))
		return (i + 1);
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
			if(e->indplus == 1)
				w--;
//			if(e.indspace == 1 && e.indplus == 0 && neg == 0)
//				ft_putchar(' ');
			while(w - i > 0)
			{
				ft_putchar(' ');
				w--;
			}
			if(e->indplus == 1 && neg == 0)
				ft_putchar('+');
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
