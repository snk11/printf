/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putjnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 01:47:53 by syusof            #+#    #+#             */
/*   Updated: 2016/03/29 01:54:06 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"


int	ft_putjnbr(intmax_t n,t_numb *e)
{
	int		i;
	int		j;
	int		r1;

	i = 0;
	r1 = 0;
	i = ft_count4(n);
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
			r1 = r1 + ft_putjnbr1(n,e);
	}
//	else if (e->valzero == 1 && e->pr == 0 && e->w != 0)
//	{
//		ft_putchar(' ');
//		r1++;
//	}
//	else if (e->valzero == 1 && e->pr == 0 && e->w == 0)
//	{
//		ft_putchar('0');
//		r1++;
//	}
	else if (e->valzero == 1)
	{
		if (e->indpr == 1)
		{
			if (e->indplus == 1)
			{
				e->w--;
			}
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
			while((e->pr) > 0)
			{
				ft_putchar('0');
				r1++;
				e->pr--;
			}
		}
		else
		{
			if (e->indminus == 0)
			{
				if (e->indplus == 1)
				{
					e->w--;
				}
				if (e->indspace== 1)
				{
					e->w--;
				}
//			j = 0;
//			while( j < e->w - 1)
//			{
//				ft_putchar(' ');
//				r1++;
//				j++;
//			}
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
			}
			else if (e->indminus == 1)
			{
				ft_putchar('0');
				r1++;
			}
		}
	}
	return (r1);
}

int	ft_putjnbr1(intmax_t n,t_numb *e)
{
	int		i;
	int		j;
	int		r1;

	i = 0;
	r1 = 0;
	i = ft_count4(n);
			if (n < 0 )
			{
				if (e->indzero == 1 && e->w > i && e->pr == 0 && e->indminus == 0)
				{
				}
				n = -n;
			}
			if (n >= 10)
			{
				r1 = r1 + ft_putjnbr(n / 10,e);
				r1 = r1 + ft_putjnbr(n % 10,e);
			}
			else
			{
				ft_putchar(n + '0');
				r1++;
			}
	return (r1);
}

int	ft_putjnbr2(intmax_t n,t_numb *e)
{
	int		i;
	int		j;
	int		r1;

	i = 0;
	r1 = 0;
	i = ft_count4(n);
	if (n == -2147483648)
	{
		{
			ft_putstr("-2147483648");
			r1 = 11;
		}
	}
	else
		r1 = r1 + ft_putjnbr2a(n,e);
	return (r1);
}

int	ft_putjnbr2a(intmax_t n,t_numb *e)
{
	int		i;
	int		j;
	int		r1;

	i = 0;
	r1 = 0;
	i = ft_count4(n);
		if (n < 0 )
		{
			r1 = r1 + ft_putnbr2a1(n,e);
			n = -n;
		}
		if (n >= 10)
		{
			r1 = r1 + ft_putjnbr2(n / 10,e);
			r1 = r1 + ft_putjnbr2(n % 10,e);
		}
		else
		{
			ft_putchar(n + '0');
			r1++;
		}
	return (r1);
}


