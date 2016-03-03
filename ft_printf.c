/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 01:53:43 by syusof            #+#    #+#             */
/*   Updated: 2016/03/03 09:19:28 by syusof           ###   ########.fr       */
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
	int bl;
	int			max;
	wchar_t		*ss;
	wchar_t		wc;
	char		*begi;
	char		*bigi2;
	int		cnt1;
	int c2;
	char	*p3;
	int		d2;
	int		g;
	char	*beg1;
	char	*p2;
	int		cnt2;
	int		prbegi;
	char	sn[]="(null)";
	t_numb	*e;
	int		ret1;


	e = (t_numb*)malloc(sizeof(t_numb));
	p = NULL;

	cnt = 0;
	cnt1 = 0;
	e->ind1 = 0;
	e->w = 0;
	e->pr = 0;
	e->ind2 = 0;
	e->indletter = 0;
	prbegi = 0;
	va_start(ap, str);
	begi = &(str[0]);
	e->indsharp = 0;
	e->indplus = 0;
	e->indspace = 0;
	e->indminus = 0;
	e->indzero = 0;
	e->indpr = 0;
	p = ft_check_perc0(str);
	ret1 = 0;
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
					cnt = cnt + ft_onelettercase(str,e);
					ft_initialize(&e);
				}
				else if (*str == 'C')
				{
					wc = va_arg(ap, wchar_t);
					cnt = cnt + ft_putwchar(wc);
				}
				else if (*str == 's')
				{
					e->prbegi = e->pr;
					e->s = va_arg(ap, char*);
					cnt = cnt + ft_checks(str,e);
					ft_initialize(&e);
					e->ind2 = 0;
				}
				else if (*str == 'S')
				{
					e->ss = va_arg(ap, wchar_t*);
					cnt = cnt + ft_checkbs(str,e);
					e->ind2 = 0;
					e->w = 0;
					e->pr = 0;
					e->indletter = 1;
					e->indpr = 0;
				}
				else if (*str == 'p')
				{
					e->l = va_arg(ap, long);
					cnt = cnt + ft_checkp(str,e);
					e->ind2 = 0;
					e->w = 0;
					e->pr = 0;
					e->indletter = 1;
					e->indpr = 0;
					e->indminus = 0;
					e->indplus = 0;
					e->indzero = 0;
					e->indspace = 0;
					e->indsharp = 0;
				}
				else if (*str == 'u')
				{
					u = va_arg(ap, unsigned int);
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
					e->ind2 = 0;
					e->w = 0;
					e->pr = 0;
					e->indletter = 1;
					e->indzero = 0;
					e->indpr = 0;
					e->indplus = 0;
					e->indspace = 0;
				}
				else if (*str == 'U')
				{
					ul = va_arg(ap, unsigned long);
					ft_putulongnbr(ul);
					cnt = cnt + ft_countul(ul);
				}
				else if (*str == 'd' || *str == 'i')
				{
					d = va_arg(ap, int);
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
					e->ind2 = 0;
					e->w = 0;
					e->pr = 0;
					e->indletter = 1;
					e->indzero = 0;
					e->indpr = 0;
					e->indplus = 0;
					e->indspace = 0;
					e->indminus = 0;
				}
				else if (*str == 'D')
				{
					l = va_arg(ap, long);
					ft_putlongnbr(l);
					cnt = cnt + ft_countl(l);
				}
				else if (*str == 'x')
				{
					e->u = va_arg(ap, unsigned int);
					cnt = cnt + ft_checkx(str,e);
					e->ind2 = 0;
					e->w = 0;
					e->pr = 0;
					e->indletter = 1;
					e->indzero = 0;
					e->indpr = 0;

				}
				else if (*str == 'X')
				{
					e->u = va_arg(ap, unsigned int);
					cnt = cnt + ft_checkbx(str,e);
					e->ind2 = 0;
					e->w = 0;
					e->pr = 0;
					e->indletter = 1;
					e->indzero = 0;
					e->indpr = 0;
				}
				else if (*str == 'o')
				{
					e->u = va_arg(ap, unsigned int);
					cnt = cnt + ft_checko(str,e);
					e->ind2 = 0;
					e->w = 0;
					e->pr = 0;
					e->indletter = 1;
					e->indzero = 0;
					e->indpr = 0;
					e->indsharp = 0;
				}
				else if (*str == 'O')
				{
					e->ul = va_arg(ap,  unsigned long);
					cnt = cnt + ft_checkbo(str,e);
					e->ind2 = 0;
					e->w = 0;
					e->pr = 0;
					e->indletter = 1;
					e->indzero = 0;
					e->indpr = 0;
					e->indsharp = 0;
				}
				else if (*str == 'l' && (str[1] == 'd' || str[1] == 'i'))
				{
					ld = va_arg(ap,long);
					ft_putldnbr(ld);
					cnt = cnt + ft_countld(ld);
					str++;
				}
				else if (*str == 'h' && (str[1] == 'd' || str[1] == 'i'))
				{
					sd = va_arg(ap,short int);
					ft_putsdnbr(sd);
					cnt = cnt + ft_countsd(sd);
					str++;
				}
				else if ((*str == 'j' || *str == 'z') && (str[1] == 'd' || str[1] == 'i'))
				{
					ll = va_arg(ap,long long);
					ft_putllnbr(ll);
					cnt = cnt + ft_countlld(ll);
					str++;
				}
				else if (*str == 'l' && str[1] == 'l' && (str[2] == 'd' || str[2] == 'i'))
				{
					ll = va_arg(ap, long long);
					ft_putllnbr(ll);
					cnt = cnt + ft_countlld(ll);
					str++;
					str++;
				}
				else if (*str == 'h' && str[1] == 'h' && (str[2] == 'd' || str[2] == 'i'))
				{
					c = va_arg(ap, char);
					cnt = cnt + ft_countd(e->w,e->pr,e,c);
					ft_putnbr(e->w,e->pr,e->indzero,c);
					str++;
					str++;
				}
				else if (*str == 'l' && str[1] == 'u')
				{
					ul = va_arg(ap, unsigned long);
					ft_putulongnbr(ul);
					cnt = cnt + ft_countul(ul);
					str++;
				}
				else if (*str == 'h' && str[1] == 'u')
				{
					us = va_arg(ap, unsigned short);
					ft_putushortnbr(us);
					cnt = cnt + ft_countus(us);
					str++;
				}
				else if ((*str == 'j' || *str == 'z') && str[1] == 'u')
				{
					ull = va_arg(ap, unsigned long long);
					ft_putulonglongnbr(ull);
					cnt = cnt + ft_countull(ull);
					str++;
				}
				else if (*str == 'l' && str[1] == 'l' && str[2] == 'u')
				{
					ull = va_arg(ap, unsigned long long);
					ft_putulonglongnbr(ull);
					cnt = cnt + ft_countul(ull);
					str++;
					str++;
				}
				else if (*str == 'h' && str[1] == 'h' && str[2] == 'u')
				{
					uc = va_arg(ap, unsigned char);
					ft_putnbr(e->w,e->pr,e->indzero,uc);
					cnt = cnt + ft_countuc(uc);
					str++;
					str++;
				}
				else if (*str == 'l' && str[1] == 'o')
				{
					ul = va_arg(ap, unsigned long);
					s2 = ft_ltooct2(ul);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
				}
				else if (*str == 'h' && str[1] == 'o')
				{
					us = va_arg(ap, unsigned short);
					s2 = ft_ltooct5(us);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
				}
				else if ((*str == 'j' || *str == 'z') && str[1] == 'o')
				{
					ull = va_arg(ap, unsigned long long);
					s2 = ft_ltooct4(ull);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
				}
				else if (*str == 'l' && str[1] == 'l' && str[2] == 'o')
				{
					ull = va_arg(ap, unsigned long long);
					s2 = ft_ltooct4(ull);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
					str++;
				}
				else if (*str == 'h' && str[1] == 'h' && str[2] == 'o')
				{
					uc = va_arg(ap, unsigned char);
					s2 = ft_ltooct6(uc);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
					str++;
				}
				else if (*str == 'l' && str[1] == 'x')
				{
					ul = va_arg(ap, unsigned long);
					s2 = ft_ltohex3(ul);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
				}
				else if (*str == 'h' && str[1] == 'x')
				{
					us = va_arg(ap, unsigned short);
					s2 = ft_ltohex6(us);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
				}
				else if ((*str == 'j' || *str == 'z') && str[1] == 'x')
				{
					ull = va_arg(ap, unsigned long long);
					s2 = ft_ltohex3(ull);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
				}
				else if (*str == 'l' && str[1] == 'l' && str[2] == 'x')
				{
					ull = va_arg(ap, unsigned long long);
					s2 = ft_ltohex4(ull);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
					str++;
				}
				else if (*str == 'h' && str[1] == 'h' && str[2] == 'x')
				{
					uc = va_arg(ap, unsigned char);
					s2 = ft_ltohex8(uc);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
					str++;
				}
				else if (*str == 'l' && str[1] == 'X')
				{
					ul = va_arg(ap, unsigned long);
					s2 = ft_ltohex2(ul);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
				}
				else if (*str == 'h' && str[1] == 'X')
				{
					us = va_arg(ap, unsigned short);
					s2 = ft_ltohex7(us);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
				}
				else if ((*str == 'j' || *str == 'z') && str[1] == 'X')
				{
					ull = va_arg(ap, unsigned long long);
					s2 = ft_ltohex5(ull);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
				}
				else if (*str == 'l' && str[1] == 'l' && str[2] == 'X')
				{
					ull = va_arg(ap, unsigned long long);
					s2 = ft_ltohex5(ull);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
					str++;
				}
				else if (*str == 'h' && str[1] == 'h' && str[2] == 'X')
				{
					uc = va_arg(ap, unsigned char);
					s2 = ft_ltohex9(uc);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
					str++;
				}
				else if (*str == 'l' && str[1] == 'c')
				{
					wc = va_arg(ap, wchar_t);
					cnt = cnt + ft_putwchar(wc);
					str++;
				}
				else if (*str == 'h' && str[1] == 'h' && str[2] == 'C')
				{
					wc = va_arg(ap, wchar_t);
					cnt = cnt + ft_putwchar(wc);
					str++;
					str++;
				}
				else if (*str == 'l' && str[1] == 's')
				{
					ss = va_arg(ap, wchar_t*);
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
					s2 = ft_ltooct3(us);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
				}
				else if (*str == 'l' && str[1] == 'l' && str[2] == 'O')
				{
					us = va_arg(ap, unsigned short);
					s2 = ft_ltooct3(us);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
					str++;
				}
				else if (*str == 'h' && str[1] == 'h' && str[2] == 'O')
				{
					us = va_arg(ap, unsigned short);
					s2 = ft_ltooct3(us);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
					str++;
				}
				else if ((*str == 'l' || *str == 'h' || *str == 'j' || *str == 'z') && (str[1] == 'U' || str[1] == 'D'))
				{
					us = va_arg(ap, unsigned short);
					ft_putushortnbr(us);
					cnt = cnt + ft_countus(us);
					str++;
				}
				else if (*str == 'l' && str[1] == 'l' && (str[2] == 'U' || str[2] == 'D'))
				{
					us = va_arg(ap, unsigned short);
					ft_putushortnbr(us);
					cnt = cnt + ft_countus(us);
					str++;
					str++;
				}
				else if (*str == 'h' && str[1] == 'h' && (str[2] == 'U' || str[2] == 'D'))
				{
					us = va_arg(ap, unsigned short);
					ft_putushortnbr(us);
					cnt = cnt + ft_countus(us);
					str++;
					str++;
				}
				else if (*str == 'l' && str[1] == 'p')
				{
					l = va_arg(ap, long);
					ft_putstr("0x");
					ft_putstr(ft_ltohex(l));
					cnt = cnt + ft_strlen(ft_ltohex(l)) + 2;
					str++;
				}
				else if ((*str >= '0' && *str <= '9') || *str == '-' ||*str == '+' || *str == '.' || *str == ' ' || *str == '#')
				{
					if (e->ind2 == 0)
					{
						begi = NULL;
						begi = ft_getfield(str);
						if (begi)
							ret1 = ft_checkflag(e,begi);
						if (e->w == 0 && begi)
							e->w = ft_checkwidth(begi);
						if (e->pr == 0 && begi)
							e->pr = ft_checkprec(begi);
					}
					e->ind2 = 1;
				}
				else
				{
					if (e->indletter == 1)
					{
						while((e->w - 1) > 0)
						{
							ft_putchar(' ');
							cnt++;
							(e->w)--;
						}
					}
					if (e->indzero == 1)
					{
						while(((e->w) - 1) > 0)
						{
							cnt++;
							ft_putchar('0');
							(e->w)--;
						}
						ft_putchar(*str);
					}
					else
					{
						if (e->w < 0)
						{
							e->w = -(e->w);
							ft_putchar(*str);
							while((e->w - 1) > 0)
							{
								cnt++;
								ft_putchar(' ');
								(e->w)--;
							}
						}
						else
						{
							while((e->w - 1) > 0)
							{
								cnt++;
								ft_putchar(' ');
								(e->w)--;
							}
							ft_putchar(*str);
						}
					}
					e->ind2 = 0;
					e->w = 0;
					e->pr = 0;
					cnt++;
					e->indletter = 0;
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
		int ind6 = 0;
		cnt1 = 0;
		cnt2 = 0;
		c2 = 0;
		e->indlast = 0;
		e->ind2 = 0;
		while (*str != 0)
		{
//			printf("str = %c , cnt1 = %d\n",*str,cnt1);
			g =0;
			ret1 = 0;
			if (*str == '%')
			{
				if (str[1])
				{
					str++;
				}
				else
					e->indlast = 1;
//				if (cnt1 % 2 == 0)
//					e->ind2 = 1;
//				else
//					e->ind2 = 0;

				i = 0;
				begi = NULL;
				begi = ft_getfield(str);
				if (begi)
				{
					ind6++;
					g = ft_strlen(begi);
				}
				while (i < g)
				{
					str++;
					i++;
				}
				ret1 = ft_checkflag(e,begi);
				if (e->w == 0 && begi)
					e->w = ft_checkwidth(begi);
				if (e->pr == 0 && begi)
					e->pr = ft_checkprec(begi);
			}

			if (cnt1 % 2 == 0 && *str == '%' && e->indlast == 0 && ind6 != 1)
			{
				ft_putchar('%');
				cnt++;
			}
			else if (e->indlast == 0)
			{
//				if (ft_checkstrlast(str) && *str == '%')
//				{
//					e->indlast = 1;
//				}
//				if (cnt1 % 2 == 0)
				{
//					if (*str == '%' && e->indlast == 1)
//					{
//					}
//					else
					{
						if (e->indzero == 0)
						{
							if(e->indminus == 1)
							{
								ft_putchar(*str);
								cnt++;
								while((e->w - 1) > 0)
								{
									cnt++;
									ft_putchar(' ');
									(e->w)--;
								}
							}
							else
							{
								while((e->w - 1) > 0)
								{
									cnt++;
									ft_putchar(' ');
									(e->w)--;
								}
								ft_putchar(*str);
								cnt++;
							}
						}
						else if (e->indzero == 1)
						{
							if(e->indminus == 1)
							{
								ft_putchar(*str);
								cnt++;
								while((e->w - 1) > 0)
								{
									cnt++;
									ft_putchar('0');
									(e->w)--;
								}
							}
							else
							{
								while((e->w - 1) > 0)
								{
									cnt++;
									ft_putchar('0');
									(e->w)--;
								}
								ft_putchar(*str);
								cnt++;
							}
						}
						e->w = 0;
						e->pr = 0;
						e->indzero = 0;
					}
//					if (ind6 == 1)
//					{
//						ft_putchar('%');
//						cnt++;
//						ind6 = 0;
//					}
				}
				if (*str == '%')
					cnt1++;
//				if (cnt1 % 2 == 1 && e->indlast == 1)
//					cnt1++;
			}
			str++;
		}
	}


	va_end(ap);
	return (cnt);
}
