/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checku.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 00:43:58 by syusof            #+#    #+#             */
/*   Updated: 2016/03/22 01:49:42 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		ft_checku(char *str,t_numb *e)
{
	int cnt;
	int	j;
	int		i;
	
	cnt = 0;
	i = ft_count2(e->u);
	if (e->u == 0 && e->indpr == 1 && e->indzero == 0)
		e->valzero = 1;
	if(e->indminus == 1)
	{
//		if (e->pr == 0 && e->w == 0 && e->indpr == 1)
//		{
//		}
//		else
		{
//			cnt = cnt + ft_countd(e,e->d);
			if (e->indplus == 1)
				e->w--;
			if (e->indplus == 1)
			{
				ft_putchar('+');
				cnt++;
			}
			if (e->indpr == 1)
			{
				j = 0;
				while(j < abs(i - e->pr))
				{
					ft_putchar('0');
					cnt++;
					j++;
				}
			}
			cnt = cnt + ft_putunbr(e->w,e->pr,e->indzero,e->u,e);
			j = 0;
			if (i >= e->pr)
			{
				while(j < e->w - i)
				{
					ft_putchar(' ');
					j++;
					cnt++;
				}
			}
			else if (i <= e->pr)
			{
				while(j < e->w - e->pr)
				{
					ft_putchar(' ');
					j++;
					cnt++;
				}
			}
		}
	}
	else if (e->indminus == 0)
	{
//		if (e->pr == 0 && e->w == 0 && e->indpr == 1)
//		{
//		}
//		else
		{
			cnt = cnt + ft_countu(e,e->u);
			cnt = cnt + ft_putunbr(e->w,e->pr,e->indzero,e->u,e);
		}
	}
	ft_initialize(e);
	return (cnt);
}


int	ft_putunbr(int w,int pr,int zero,unsigned int n,t_numb *e)
{
	int		i;
	int		j;
	int		r1;

	i = 0;
	r1 = 0;
	i = ft_count(n);
	if (e->valzero == 0)
	{
		if (n == UINT_MAX)
		{
			ft_putstr("4294967295");
			r1 = 10;
		}
//		else
//		{
//			ft_putstr("2147483648");
//			r1 = 11;
//		}
		else
		{
			if (n >= 10)
			{
				r1 = r1 + ft_putunbr(w,pr,zero,n / 10,e);
				r1 = r1 + ft_putunbr(w,pr,zero,n % 10,e);
			}
			else
			{
				ft_putchar(n + '0');
				r1++;
			}
		}
	}
	else if (e->valzero == 1 && pr == 0 && w != 0)
	{
		ft_putchar(' ');
		r1++;
	}
	return (r1);
}

int	ft_countu(t_numb *e,unsigned n)
{
	t_count *f;
	int		ret;

	ret = 0;
	f = (t_count*)malloc(sizeof(t_count));
	f->i = 0;
	f->neg = 0;
	f->w = e->w;
	f->pr = e->pr;
	f->u = f->pr;
	f->v = f->w;
	if (n == UINT_MAX)
		f->i = 10;
	else
		ft_countu2(f,n);
	if (e->indzero == 1 && f->pr == 0)
		ret = ret + ft_countu3(e,f);
	else
		ret = ret + ft_countu4(e,f);
//	ret = (ft_countd5(e,f));
	free(f);
	f = NULL;
	return (ret);
}


void 	ft_countu2(t_count *f,unsigned int n)
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

int		ft_countu3(t_numb *e,t_count *f)
{
	int		j;
	int		r1;
	
	r1 = 0;
		if (f->w > f->i)
		{
			if (f->neg == 1 || e->indminus == 1)
			{
				ft_putchar('-');
				r1++;
				if (e->indpr == 1)
				{
					j = 0;
					while(j < f->i - f->pr)
					{
						ft_putchar('0');
						r1++;
						j++;
					}
				}
				if (e->indzero == 1 && e->indpr == 0)
				{
					j = 0;
					while(j < f->w - f->i)
					{
						ft_putchar('0');
						r1++;
						j++;
					}
				}
			}
			else if (f->w > f->i)
				r1 = r1 +ft_countu3a(e,f);
		}

		else if (f->w <= f->i)
		{
			if (e->indminus == 1 || f->neg == 1)
			{
				ft_putchar('-');
				r1++;
			}
//			if (e->indplus == 1)
//			{
//				ft_putchar('+');
//				r1++;
//			}
//			if (e->indspace == 1)
//			{
//				ft_putchar(' ');
//				r1++;
//			}
		}
	return (r1);
}

int	ft_countu3a(t_numb *e,t_count *f)
{
	int r1;

	r1 = 0;
			if (f->neg == 1)
			{
				ft_putchar('-');
				r1++;
				while((f->w - f->i) > 0)
				{
					ft_putchar('0');
					r1++;
					f->w--;
				}
			}
			else
				r1 =  r1 + ft_countu3a1(e,f);
	return (r1);
}

int	ft_countu3a1(t_numb *e,t_count *f)
{
	int	r1;

	r1 = 0;
				if(e->indminus == 1)
					r1 = r1 + ft_countu3a1a(e,f);
				else
				{
//					if (e->indplus == 1)
//						f->w--;
//					if (e->indplus == 1)
//					{
//						ft_putchar('+');
//						r1++;
//					}
//					if (e->indspace == 1)
//						f->w--;
//					if (e->indspace == 1)
//					{
//						ft_putchar(' ');
//						r1++;
//					}
					while(f->w - f->i > 0)
					{
						ft_putchar('0');
						r1++;
						f->w--;
					}
				}
	return (r1);
}


int	ft_countu3a1a(t_numb *e,t_count *f)
{
	int	r1;

	r1 = 0;
					if (e->indplus == 1)
						f->w--;
//					if (e->indplus == 1)
//					{
//						ft_putchar('+');
//						r1++;
//					}
					if (e->indspace == 1)
						f->w--;
//					if (e->indspace == 1)
//					{
//						ft_putchar(' ');
//						r1++;
//					}
					while(f->w - f->i > 0)
					{
						ft_putchar(' ');
						r1++;
						f->w--;
					}
	return (r1);
}

int	ft_countu4(t_numb *e,t_count *f)
{
	int r1;

	r1 = 0;
		if (f->pr >= f->i)
			r1 = r1 + ft_countu4a(e,f);
		else
		{
//			if(e->indplus == 1)
//				f->w--;
//			if(e->indspace == 1 && e->indplus == 0 && f->neg == 0)
//			{
//				ft_putchar(' ');
//				r1++;
//			}
			while(f->w - f->i > 0)
			{
				ft_putchar(' ');
				r1++;
				f->w--;
			}
//			if(e->indplus == 1 && f->neg == 0)
//			{
//				ft_putchar('+');
//				r1++;
//				f->w--;
//			}
			if (f->neg == 1 || e->indminus == 1)
				r1 = r1 + ft_countu4a1(e,f);
		}
	return (r1);
}

int	ft_countu4a(t_numb *e,t_count *f)
{
	int		r1;

	r1 = 0;
			if (f->neg == 1)
				r1 = r1 + ft_countu4a1(e,f);
			else
			{
//				if (e->indplus == 1)
//					f->w--;
//				if (e->indspace == 1)
//					f->w--;
//				if (e->indspace == 1)
//				{
//					ft_putchar(' ');
//					r1++;
//				}
				while(f->w - f->pr > 0)
				{
					ft_putchar(' ');
					r1++;
					f->w--;
				}
//				if (e->indplus == 1)
//				{
//					ft_putchar('+');
//					r1++;
//				}
				while((f->pr - f->i) > 0)
				{
					ft_putchar('0');
					r1++;
					f->pr--;
				}
			}
	return (r1);
}

int	ft_countu4a1(t_numb *e,t_count *f)
{
	int	r1;

	r1 = 0;
				ft_putchar('-');
				r1++;
				while((f->pr - f->i + 1) > 0)
				{
					ft_putchar('0');
					r1++;
					f->pr--;
				}
	return (r1);
}

