/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checku.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 00:43:58 by syusof            #+#    #+#             */
/*   Updated: 2016/03/28 05:22:29 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"


int		ft_checku(char *str,t_numb *e)
{
	int cnt;
	int	j;
	int		i;

	cnt = 0;
//	printf("minus = %d\n",e->indminus);
	i = ft_count2(e->u);
//	if (e->d == 0 && e->indpr == 1 && e->indzero == 0)
	if (e->u == 0)
		e->valzero = 1;
	if(e->indminus == 1)
		cnt = cnt + ft_checku1(e);
	else if (e->indminus == 0)
	{
		if(e->valzero == 1)
		{
			cnt = cnt + ft_putunbr(e->u,e);
//			if(e->indplus == 1)
//			{
//				ft_putchar('+');
//				cnt++;
//			}
//			ft_putchar('0');
//			cnt++;
		}
		else
		{
			cnt = cnt + ft_countu(e,e->u);
			cnt = cnt + ft_putunbr(e->u,e);
		}
	}
	ft_initialize(e);
	return (cnt);
}


int	ft_putunbr(unsigned int n,t_numb *e)
{
	int		i;
	int		j;
	int		r1;

	i = 0;
	r1 = 0;
	i = ft_count2(n);
	if (e->valzero == 0)
	{
		if (n == UINT_MAX)
		{
			ft_putstr("4294967295");
			r1 = 10;
		}
		else
			r1 = r1 + ft_putunbr1(n,e);
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
			while(e->w - e->pr > 0)
			{
				ft_putchar(' ');
				r1++;
				e->w--;
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
				if (e->w == 0)
				{
					ft_putchar('0');
					r1++;
				}
				while (e->w)
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

int	ft_putunbr1(unsigned int n,t_numb *e)
{
	int		i;
	int		j;
	int		r1;

	i = 0;
	r1 = 0;
	i = ft_count2(n);
			if (n >= 10)
			{
				r1 = r1 + ft_putunbr(n / 10,e);
				r1 = r1 + ft_putunbr(n % 10,e);
			}
			else
			{
				ft_putchar(n + '0');
				r1++;
			}
	return (r1);
}

int	ft_putunbr2(unsigned int n,t_numb *e)
{
	int		i;
	int		j;
	int		r1;

	i = 0;
	r1 = 0;
	i = ft_count2(n);
		r1 = r1 + ft_putunbr2a(n,e);
	return (r1);
}

int	ft_putunbr2a(unsigned int n,t_numb *e)
{
	int		i;
	int		j;
	int		r1;

	i = 0;
	r1 = 0;
	i = ft_count2(n);
		if (n >= 10)
		{
			r1 = r1 + ft_putunbr2(n / 10,e);
			r1 = r1 + ft_putunbr2(n % 10,e);
		}
		else
		{
			ft_putchar(n + '0');
			r1++;
		}
	return (r1);
}

int	ft_putunbr2a1(unsigned int n,t_numb *e)
{
	int		i;
	int		j;
	int		r1;

	i = 0;
	r1 = 0;
	i = ft_count2(n);
			if (e->indzero == 1 && e->w > i && e->pr == 0 && e->indminus == 0)
			{
			}
			else if (e->pr < i)
			{
				ft_putchar('-');
				r1++;
			}
	return (r1);
}

int		ft_checku1(t_numb *e)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = ft_count2(e->u);
	if ((e->indplus == 1 && e->indminus == 0 && e->u < 0) || (e->indplus == 1 && e->indminus == 1 && e->u > 0) )
		e->w--;
	if (e->indpr == 1)
		cnt = cnt + ft_checku1a(e);
	cnt = cnt + ft_putunbr(e->u,e);
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
			while(j < e->pr - i)
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

			while(j < (i- 1 - e->pr))
			{
				ft_putchar('0');
				cnt++;
				j++;
			}
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
		while(j < e->w - e->pr)
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
		while(j < e->w - i)
		{
			ft_putchar(' ');
			j++;
			cnt++;
		}
	return (cnt);
}

int	ft_countu(t_numb *e,unsigned int n)
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
		r1 = r1 + ft_countu342a(e,f);
	else if (e->w <= f->i)
		r1 = r1 + ft_countu342b(e,f);
	return (r1);
}


int		ft_countu342a(t_numb *e,t_count *f)
{
	int		j;
	int		r1;

	r1 = 0;
		if (f->neg == 1 || e->indminus == 1)
			r1 = r1 +ft_countu342a1(e,f);
		else if (e->w > f->i)
			r1 = r1 +ft_countu3a(e,f);
	return (r1);
}

int		ft_countu342a1(t_numb *e,t_count *f)
{
	int		j;
	int		r1;

	r1 = 0;
			r1 = r1 +ft_countu342a1a(e,f);
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

int		ft_countu342a1a(t_numb *e,t_count *f)
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

int		ft_countu342b(t_numb *e,t_count *f)
{
	int		j;
	int		r1;

	r1 = 0;
	return (r1);
}

int	ft_countu3a(t_numb *e,t_count *f)
{
	int r1;

	r1 = 0;
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
		r1 = r1 + ft_countu3a142(e,f);
	}
	return (r1);
}


int	ft_countu3a142(t_numb *e,t_count *f)
{
	int	r1;

	r1 = 0;
		while(e->w - f->i > 0)
		{
			ft_putchar('0');
			r1++;
			e->w--;
		}
	return (r1);
}


int	ft_countu3a1a(t_numb *e,t_count *f)
{
	int	r1;

	r1 = 0;
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
		if (f->neg == 1 || e->indminus == 1)
			r1 = r1 + ft_countu4a2(e,f);
		else
			r1 = r1 + ft_countu442(e,f);
	}
	return (r1);
}

int	ft_countu442(t_numb *e,t_count *f)
{
	int r1;

	r1 = 0;
			while(e->w - f->i > 0)
			{
				ft_putchar(' ');
				r1++;
				e->w--;
			}
	return (r1);
}

int	ft_countu4a(t_numb *e,t_count *f)
{
	int		r1;

	r1 = 0;
	{
		r1 = r1 + ft_countu4a42(e,f);
	}
	return (r1);
}


int	ft_countu4a42(t_numb *e,t_count *f)
{
	int		r1;

	r1 = 0;
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
	return (r1);
}


int	ft_countu4a2(t_numb *e,t_count *f)
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


/*
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
			cnt = cnt + ft_putunbr(e->u,e);
		}
	}
	ft_initialize(e);
	return (cnt);
}


int	ft_putunbr(unsigned int n,t_numb *e)
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
			r1 = r1 + ft_putunbr1(n,e);
	}
	else if (e->valzero == 1 && e->pr == 0 && e->w != 0)
	{
		ft_putchar(' ');
		r1++;
	}
	return (r1);
}

int	ft_putunbr1(unsigned int n,t_numb *e)
{
	int		i;
	int		j;
	int		r1;

	i = 0;
	r1 = 0;
	i = ft_count(n);
			if (n >= 10)
			{
				r1 = r1 + ft_putunbr(n / 10,e);
				r1 = r1 + ft_putunbr(n % 10,e);
			}
			else
			{
				ft_putchar(n + '0');
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
			cnt = cnt + ft_putunbr(e->u,e);
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
*/
