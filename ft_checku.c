/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checku.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 00:43:58 by syusof            #+#    #+#             */
/*   Updated: 2016/03/22 06:23:36 by syusof           ###   ########.fr       */
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
		cnt = cnt + ft_checku1(e);
	else if (e->indminus == 0)
	{
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


int		ft_checku1(t_numb *e)
{
	int cnt;
	int	j;
	int		i;
	
	cnt = 0;
	i = ft_count2(e->u);
		cnt = cnt + ft_checku1a(e);
			cnt = cnt + ft_putunbr(e->w,e->pr,e->indzero,e->u,e);
			if (i >= e->pr)
			{
			j = 0;
				while(j < e->w - i)
				{
					ft_putchar(' ');
					j++;
					cnt++;
				}
			}
			else if (i <= e->pr)
				cnt = cnt + ft_checku1b(e);
	return (cnt);
}

int		ft_checku1a(t_numb *e)
{
	int cnt;
	int	j;
	int		i;
	
	cnt = 0;
	i = ft_count2(e->u);
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
	return (cnt);
}
int		ft_checku1b(t_numb *e)
{
	int cnt;
	int	j;
	int		i;
	
	cnt = 0;
	i = ft_count2(e->u);
			j = 0;
				while(j < e->w - e->pr)
				{
					ft_putchar(' ');
					j++;
					cnt++;
				}
	return (cnt);
}


int	ft_countu(t_numb *e,unsigned n)
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
		ft_countu2(f,n);
	if (e->indzero == 1 && e->pr == 0)
		ret = ret + ft_countu3(e,f);
	else
		ret = ret + ft_countu4(e,f);
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
		if (e->w > f->i)
			r1 = r1 + ft_countu342(e,f);

		else if (e->w <= f->i)
		{
			if (e->indminus == 1 || f->neg == 1)
			{
				ft_putchar('-');
				r1++;
			}
		}
	return (r1);
}

int		ft_countu342(t_numb *e,t_count *f)
{
	int		j;
	int		r1;
	
	r1 = 0;

			if (f->neg == 1 || e->indminus == 1)
			{
				r1 = r1 + ft_countu342a(e,f);
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
			}
			else if (e->w > f->i)
				r1 = r1 +ft_countu3a(e,f);
	return (r1);
}

int		ft_countu342a(t_numb *e,t_count *f)
{
	int		j;
	int		r1;
	
	r1 = 0;
				ft_putchar('-');
				r1++;
				if (e->indpr == 1)
				{
					j = 0;
					while(j < f->i - e->pr)
					{
						ft_putchar('0');
						r1++;
						j++;
					}
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
				while((e->w - f->i) > 0)
				{
					ft_putchar('0');
					r1++;
					e->w--;
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
					while(e->w - f->i > 0)
					{
						ft_putchar('0');
						r1++;
						e->w--;
					}
				}
	return (r1);
}


int	ft_countu3a1a(t_numb *e,t_count *f)
{
	int	r1;

	r1 = 0;
					if (e->indplus == 1)
						e->w--;
					if (e->indspace == 1)
						e->w--;
					while(e->w - f->i > 0)
					{
						ft_putchar(' ');
						r1++;
						e->w--;
					}
	return (r1);
}

int	ft_countu4(t_numb *e,t_count *f)
{
	int r1;

	r1 = 0;
		if (e->pr >= f->i)
			r1 = r1 + ft_countu4a(e,f);
		else
		{
			while(e->w - f->i > 0)
			{
				ft_putchar(' ');
				r1++;
				e->w--;
			}
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
				while(e->w - e->pr > 0)
				{
					ft_putchar(' ');
					r1++;
					e->w--;
				}
				while((e->pr - f->i) > 0)
				{
					ft_putchar('0');
					r1++;
					e->pr--;
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
				while((e->pr - f->i + 1) > 0)
				{
					ft_putchar('0');
					r1++;
					e->pr--;
				}
	return (r1);
}

