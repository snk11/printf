/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 01:53:43 by syusof            #+#    #+#             */
/*   Updated: 2016/03/08 16:28:52 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

# include <stdio.h>
//+3.3-06 d
int	ft_printf(char *str, ...)
{

	va_list		ap;
	int			d;
	short int		sd;
	unsigned int	u;
	unsigned short	us;
	long		l;
	long int	ld;
	long long	ll;
	unsigned long long	ull;
	unsigned long		ul;
	char		*s2;
	char		*s3;
	char		c;
	unsigned char		uc;
	int			cnt;
	int			i;
	char		*p;
	wchar_t		*ss;
	wchar_t		wc;
	int		cnt1;
	int		g;
	char	sn[]="(null)";
	t_numb	*e;


	e = (t_numb*)malloc(sizeof(t_numb));
	e->strini = str;
	p = NULL;

	cnt = 0;
	ft_initialize(&e);
	e->cursorap = 0;
	va_start(ap, str);
//	begi = &(str[0]);
	p = ft_check_perc0(str);
	if (p == NULL)
	{
		e->ind1++;
	}



	if (e->ind1 % 2 == 0)
	{
		while (*str != 0)
		{
			if ( *str == '%' || e->ind2 == 1)
			{
				if (*str)
					str++;
				if (e->ind2 == 1)
				{
					str--;
				}
				if (*str == 0)
				{
				}
				else if (*str == 'c')
				{
					e->d = va_arg(ap, int);
					e->cursorap++;
					cnt = cnt + ft_checkc(str,e);
					ft_initialize(&e);
				}
				else if (*str == 'C')
				{
					wc = va_arg(ap, wchar_t);
					e->cursorap++;
					cnt = cnt + ft_putwchar(wc);
				}
				else if (*str == 's')
				{
					e->prbegi = e->pr;
					e->s = va_arg(ap, char*);
					e->cursorap++;
					cnt = cnt + ft_checks(str,e);
					ft_initialize(&e);
				}
				else if (*str == 'S')
				{
					e->ss = va_arg(ap, wchar_t*);
					e->cursorap++;
					cnt = cnt + ft_checkbs(str,e);
					ft_initialize(&e);
				}
				else if (*str == 'p')
				{
					e->l = va_arg(ap, long);
					e->cursorap++;
					cnt = cnt + ft_checkp(str,e);
					ft_initialize(&e);
				}
				else if (*str == 'u')
				{
					u = va_arg(ap, unsigned int);
					e->cursorap++;
					if (e->pr == 0 && e->w == 0 && e->indpr == 1)
					{
					}
					else
					{
						if(e->w < 0)
						{
							ft_putunbr(e->w,e->pr,e->indzero,u);
							cnt = cnt + ft_countu(e->w,e->pr,e->indzero,e,u);
						}
						else
						{
							cnt = cnt + ft_countu(e->w,e->pr,e->indzero,e,u);
							ft_putunbr(e->w,e->pr,e->indzero,u);
						}
					}
					ft_initialize(&e);
				}
				else if (*str == 'U')
				{
					ul = va_arg(ap, unsigned long);
					e->cursorap++;
					ft_putulongnbr(ul);
					cnt = cnt + ft_countul(ul);
				}
				else if (*str == 'd' || *str == 'i')
				{
					d = va_arg(ap, int);
					e->cursorap++;
					if (e->pr == 0 && e->w == 0 && e->indpr == 1)
					{
					}
					else
					{
						if(e->indminus == 1)
						{
							ft_putnbr(e->w,e->pr,e->indzero,d);
							cnt = cnt + ft_countd(e->w,e->pr,e,d);
						}
						else
						{
							cnt = cnt + ft_countd(e->w,e->pr,e,d);
							ft_putnbr(e->w,e->pr,e->indzero,d);
						}
					}
					ft_initialize(&e);
				}
				else if (*str == 'D')
				{
					l = va_arg(ap, long);
					e->cursorap++;
					ft_putlongnbr(l);
					cnt = cnt + ft_countl(l);
				}
				else if (*str == 'x')
				{
					e->u = va_arg(ap, unsigned int);
					e->cursorap++;
					cnt = cnt + ft_checkx(str,e);
					ft_initialize(&e);
				}
				else if (*str == 'X')
				{
					e->u = va_arg(ap, unsigned int);
					e->cursorap++;
					cnt = cnt + ft_checkbx(str,e);
					ft_initialize(&e);
				}
				else if (*str == 'o')
				{
					e->u = va_arg(ap, unsigned int);
					e->cursorap++;
					cnt = cnt + ft_checko(str,e);
					ft_initialize(&e);
				}
				else if (*str == 'O')
				{
					e->ul = va_arg(ap,  unsigned long);
					e->cursorap++;
					cnt = cnt + ft_checkbo(str,e);
					ft_initialize(&e);
				}
				else if (*str == 'l' && (str[1] == 'd' || str[1] == 'i'))
				{
					ld = va_arg(ap,long);
					e->cursorap++;
					ft_putldnbr(ld);
					cnt = cnt + ft_countld(ld);
					str++;
				}
				else if (*str == 'h' && (str[1] == 'd' || str[1] == 'i'))
				{
					sd = va_arg(ap,short int);
					e->cursorap++;
					ft_putsdnbr(sd);
					cnt = cnt + ft_countsd(sd);
					str++;
				}
				else if ((*str == 'j' || *str == 'z') && (str[1] == 'd' || str[1] == 'i'))
				{
					ll = va_arg(ap,long long);
					e->cursorap++;
					ft_putllnbr(ll);
					cnt = cnt + ft_countlld(ll);
					str++;
				}
				else if (*str == 'l' && str[1] == 'l' && (str[2] == 'd' || str[2] == 'i'))
				{
					ll = va_arg(ap, long long);
					e->cursorap++;
					ft_putllnbr(ll);
					cnt = cnt + ft_countlld(ll);
					str++;
					str++;
				}
				else if (*str == 'h' && str[1] == 'h' && (str[2] == 'd' || str[2] == 'i'))
				{
					c = va_arg(ap, char);
					e->cursorap++;
					cnt = cnt + ft_countd(e->w,e->pr,e,c);
					ft_putnbr(e->w,e->pr,e->indzero,c);
					str++;
					str++;
				}
				else if (*str == 'l' && str[1] == 'u')
				{
					ul = va_arg(ap, unsigned long);
					e->cursorap++;
					ft_putulongnbr(ul);
					cnt = cnt + ft_countul(ul);
					str++;
				}
				else if (*str == 'h' && str[1] == 'u')
				{
					us = va_arg(ap, unsigned short);
					e->cursorap++;
					ft_putushortnbr(us);
					cnt = cnt + ft_countus(us);
					str++;
				}
				else if ((*str == 'j' || *str == 'z') && str[1] == 'u')
				{
					ull = va_arg(ap, unsigned long long);
					e->cursorap++;
					ft_putulonglongnbr(ull);
					cnt = cnt + ft_countull(ull);
					str++;
				}
				else if (*str == 'l' && str[1] == 'l' && str[2] == 'u')
				{
					ull = va_arg(ap, unsigned long long);
					e->cursorap++;
					ft_putulonglongnbr(ull);
					cnt = cnt + ft_countul(ull);
					str++;
					str++;
				}
				else if (*str == 'h' && str[1] == 'h' && str[2] == 'u')
				{
					uc = va_arg(ap, unsigned char);
					e->cursorap++;
					ft_putnbr(e->w,e->pr,e->indzero,uc);
					cnt = cnt + ft_countuc(uc);
					str++;
					str++;
				}
				else if (*str == 'l' && str[1] == 'o')
				{
					ul = va_arg(ap, unsigned long);
					e->cursorap++;
					s2 = ft_ltooct2(ul);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
				}
				else if (*str == 'h' && str[1] == 'o')
				{
					us = va_arg(ap, unsigned short);
					e->cursorap++;
					s2 = ft_ltooct5(us);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
				}
				else if ((*str == 'j' || *str == 'z') && str[1] == 'o')
				{
					ull = va_arg(ap, unsigned long long);
					e->cursorap++;
					s2 = ft_ltooct4(ull);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
				}
				else if (*str == 'l' && str[1] == 'l' && str[2] == 'o')
				{
					ull = va_arg(ap, unsigned long long);
					e->cursorap++;
					s2 = ft_ltooct4(ull);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
					str++;
				}
				else if (*str == 'h' && str[1] == 'h' && str[2] == 'o')
				{
					uc = va_arg(ap, unsigned char);
					e->cursorap++;
					s2 = ft_ltooct6(uc);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
					str++;
				}
				else if (*str == 'l' && str[1] == 'x')
				{
					ul = va_arg(ap, unsigned long);
					e->cursorap++;
					s2 = ft_ltohex3(ul);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
				}
				else if (*str == 'h' && str[1] == 'x')
				{
					us = va_arg(ap, unsigned short);
					e->cursorap++;
					s2 = ft_ltohex6(us);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
				}
				else if ((*str == 'j' || *str == 'z') && str[1] == 'x')
				{
					ull = va_arg(ap, unsigned long long);
					e->cursorap++;
					s2 = ft_ltohex3(ull);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
				}
				else if (*str == 'l' && str[1] == 'l' && str[2] == 'x')
				{
					ull = va_arg(ap, unsigned long long);
					e->cursorap++;
					s2 = ft_ltohex4(ull);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
					str++;
				}
				else if (*str == 'h' && str[1] == 'h' && str[2] == 'x')
				{
					uc = va_arg(ap, unsigned char);
					e->cursorap++;
					s2 = ft_ltohex8(uc);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
					str++;
				}
				else if (*str == 'l' && str[1] == 'X')
				{
					ul = va_arg(ap, unsigned long);
					e->cursorap++;
					s2 = ft_ltohex2(ul);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
				}
				else if (*str == 'h' && str[1] == 'X')
				{
					us = va_arg(ap, unsigned short);
					e->cursorap++;
					s2 = ft_ltohex7(us);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
				}
				else if ((*str == 'j' || *str == 'z') && str[1] == 'X')
				{
					ull = va_arg(ap, unsigned long long);
					e->cursorap++;
					s2 = ft_ltohex5(ull);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
				}
				else if (*str == 'l' && str[1] == 'l' && str[2] == 'X')
				{
					ull = va_arg(ap, unsigned long long);
					e->cursorap++;
					s2 = ft_ltohex5(ull);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
					str++;
				}
				else if (*str == 'h' && str[1] == 'h' && str[2] == 'X')
				{
					uc = va_arg(ap, unsigned char);
					e->cursorap++;
					s2 = ft_ltohex9(uc);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
					str++;
				}
				else if (*str == 'l' && str[1] == 'c')
				{
					wc = va_arg(ap, wchar_t);
					e->cursorap++;
					cnt = cnt + ft_putwchar(wc);
					str++;
				}
				else if (*str == 'h' && str[1] == 'h' && str[2] == 'C')
				{
					wc = va_arg(ap, wchar_t);
					e->cursorap++;
					cnt = cnt + ft_putwchar(wc);
					str++;
					str++;
				}
				else if (*str == 'l' && str[1] == 's')
				{
					ss = va_arg(ap, wchar_t*);
					e->cursorap++;
					if (ss)
					{
						cnt = cnt + ft_putwstr(ss);
					}
					else
					{
						ft_putstr("(null)");
						cnt = cnt + 6;
					}
					str++;
				}
				else if (*str == 'h' && str[1] == 'h' && str[2] == 'S')
				{
					ss = va_arg(ap, wchar_t*);
					e->cursorap++;
					if (ss)
					{
						cnt = cnt + ft_putwstr(ss);
					}
					else
					{
						ft_putstr("(null)");
						cnt = cnt + 6;
					}
					str++;
					str++;
				}
				else if ((*str == 'l' || *str == 'h' || *str == 'j' || *str == 'z') && str[1] == 'O')
				{
					us = va_arg(ap, unsigned short);
					e->cursorap++;
					s2 = ft_ltooct3(us);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
				}
				else if (*str == 'l' && str[1] == 'l' && str[2] == 'O')
				{
					us = va_arg(ap, unsigned short);
					e->cursorap++;
					s2 = ft_ltooct3(us);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
					str++;
				}
				else if (*str == 'h' && str[1] == 'h' && str[2] == 'O')
				{
					us = va_arg(ap, unsigned short);
					e->cursorap++;
					s2 = ft_ltooct3(us);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
					str++;
				}
				else if ((*str == 'l' || *str == 'h' || *str == 'j' || *str == 'z') && (str[1] == 'U' || str[1] == 'D'))
				{
					us = va_arg(ap, unsigned short);
					e->cursorap++;
					ft_putushortnbr(us);
					cnt = cnt + ft_countus(us);
					str++;
				}
				else if (*str == 'l' && str[1] == 'l' && (str[2] == 'U' || str[2] == 'D'))
				{
					us = va_arg(ap, unsigned short);
					e->cursorap++;
					ft_putushortnbr(us);
					cnt = cnt + ft_countus(us);
					str++;
					str++;
				}
				else if (*str == 'h' && str[1] == 'h' && (str[2] == 'U' || str[2] == 'D'))
				{
					us = va_arg(ap, unsigned short);
					e->cursorap++;
					ft_putushortnbr(us);
					cnt = cnt + ft_countus(us);
					str++;
					str++;
				}
				else if (*str == 'l' && str[1] == 'p')
				{
					l = va_arg(ap, long);
					e->cursorap++;
					ft_putstr("0x");
					ft_putstr(ft_ltohex(l));
					cnt = cnt + ft_strlen(ft_ltohex(l)) + 2;
					str++;
				}
				else if ((*str >= '0' && *str <= '9') || *str == '-' ||*str == '+' || *str == '.' || *str == ' ' || *str == '#')
				{
					if (e->ind2 == 0)
					{
						e->begi = NULL;
						e->begi = ft_getfield(str);
						if (e->begi)
							e->ret1 = ft_checkflag(e,e->begi);
						if (e->w == 0 && e->begi)
							e->w = ft_checkwidth(e->begi);
						if (e->pr == 0 && e->begi)
							e->pr = ft_checkprec(e->begi);
					}
					e->ind2 = 1;
				}
				else
				{
					cnt = cnt + ft_elseend(str,e);
					cnt++;
					ft_initialize(&e);
				}
			}
			else
			{
				ft_putchar(*str);
				cnt++;
			}
			if (*str != 0)
				str++;
		}
	}


	else if (e->ind1 % 2 == 1)
	{
		e->ind6 = 0;
		e->cnt1 = 0;
//		cnt2 = 0;
//		c2 = 0;
		e->indlast = 0;
		e->ind2 = 0;
		
		cnt = cnt + ft_altprime(str,e);
	}

	va_end(ap);
	return (cnt);
}
