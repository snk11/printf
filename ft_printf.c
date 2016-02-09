/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 01:53:43 by syusof            #+#    #+#             */
/*   Updated: 2016/02/09 15:28:55 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

# include <stdio.h>

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
	char		*s;
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
	int		ind1;
	int		w;
	int		pr;
	int		ind2;
	int		ind0;
	int		indletter;
	int		zero;
	int		g;
	char	*beg1;
	char	*p2;
	int		cnt2;
	int		indlast;
	int		indpr;
	int		prbegi;
	t_numb	e;
	//	int		b;


	cnt = 0;
	cnt1 = 0;
	ind1 = 0;
	w = 0;
	pr = 0;
	ind2 = 0;
	indletter = 0;
	zero = 0;
	indpr = 0;
	prbegi = 0;
	e.indsharp = 0;
	e.indplus = 0;
	e.indspace = 0;
	va_start(ap, str);
	begi = &(str[0]);
	//	printf("str = %s\n",str);
	p = ft_check_perc0(str);
//			printf("p= %s\n",p);
	if (p == NULL)
		ind1++;



	if (ind1 % 2 == 0)
	{
//			while (*str)
//			{
//				p = ft_check_perc(str);
//				p2 = p;
//				printf("p2= %s\n",p);
		while (*str != 0)
		{
			if ( *str == '%' || ind2 == 1)
			{
//						cnt1++;
				str++;
				if (ind2 == 1)
					str--;
				if (*str == ' ')
				{
					str++;
					e.indspace = 1;
				}
				if (*str == '#')
				{
					str++;
					e.indsharp = 1;
				}
				if (*str == '+')
				{
					str++;
					e.indplus = 1;
				}
//			printf("ind2 = %d,str1 =%c\n",ind2,*str);
//						if (*str == '%')
//							cnt1++;
//			printf("p1 = %d\n", p);
				if (*str == 0)
				{
				}
//						else if (*str == '%' && cnt1 % 2 == 1)
//						{
//						}
				else if (*str == 'c')
				{
					c = va_arg(ap, int);
					if (zero == 0)
					{
						if(w < 0)
						{
							w = -w;
							ft_putchar(c);
							cnt++;
							while((w - 1) > 0)
							{
								cnt++;
								ft_putchar(' ');
								w--;
							}
						}
						else
						{
							while((w - 1) > 0)
							{
								cnt++;
								ft_putchar(' ');
								w--;
							}
							ft_putchar(c);
							cnt++;
						}
					}
					else
					{
						if(w < 0)
						{
							w = -w;
							ft_putchar(c);
							cnt++;
							while((w - 1) > 0)
							{
								cnt++;
								ft_putchar('0');
								w--;
							}
						}
						else
						{
							while((w - 1) > 0)
							{
								cnt++;
								ft_putchar('0');
								w--;
							}
							ft_putchar(c);
							cnt++;
						}
					}
					ind2 = 0;
					w = 0;
					pr = 0;
					zero = 0;
					indpr = 0;
				}
				else if (*str == 'C')
				{
					wc = va_arg(ap, wchar_t);
					cnt = cnt + ft_putwchar(wc);
				}
				else if (*str == 's')
				{
					prbegi = pr;
					s = va_arg(ap, char*);
					g = ft_strlen(s);
					if (indpr == 1)
					{
						if (pr > w)
						{
							if (zero == 0)
							{
								while((w - g) > 0 && pr > 0)
								{
									cnt++;
									ft_putchar(' ');
									w--;
									pr--;
								}
							}
							else
							{
								while((w - g) > 0 && pr > 0)
								{
									cnt++;
									ft_putchar('0');
									w--;
									pr--;
								}
							}
							if (s)
							{
								ft_putstr2(pr,s);
								i = 0;
								pr =prbegi;
								while (i < g && pr > 0)
								{
									cnt++;
									i++;
									pr--;
								}
							}
							else
							{
								ft_putstr("(null)");
								cnt = cnt + 6;
							}
						}
						else if(w > pr)
						{
							if (g > pr)
							{
								if (zero == 0)
								{
									while((w - pr) > 0)
									{
										cnt++;
										ft_putchar(' ');
										w--;
									}
								}
								else
								{
									while((w - pr) > 0)
									{
										cnt++;
										ft_putchar('0');
										w--;
									}
								}
								if (s)
								{
									ft_putstr2(pr,s);
									i = 0;
									while (pr > 0)
									{
										cnt++;
										pr--;
									}
								}
								else
								{
									ft_putstr("(null)");
									cnt = cnt + 6;
								}
							}
							else if (g < pr)
							{
								if (zero == 0)
								{
									while((w - g) > 0)
									{
										cnt++;
										ft_putchar(' ');
										w--;
									}
								}
								else
								{
									while((w - g) > 0)
									{
										cnt++;
										ft_putchar('0');
										w--;
									}
								}
								if (s)
								{
									ft_putstr(s);
									i = 0;
									while (i < g)
									{
										cnt++;
										i++;
									}
								}
								else
								{
									ft_putstr("(null)");
									cnt = cnt + 6;
								}
							}
						}
					}
					else
					{
						if (zero == 0)
						{
							while((w - g) > 0)
							{
								cnt++;
								ft_putchar(' ');
								w--;
							}
						}
						else
						{
							while((w - g) > 0)
							{
								cnt++;
								ft_putchar('0');
								w--;
							}
						}
						if (s)
						{
							ft_putstr(s);
							i = 0;
							while (i < g)
							{
								cnt++;
								i++;
							}
						}
						else
						{
							ft_putstr("(null)");
							cnt = cnt + 6;
						}
					}
					ind2 = 0;
					w = 0;
					pr = 0;
					zero = 0;
					indpr = 0;
				}
				else if (*str == 'S')
				{
					ss = va_arg(ap, wchar_t*);
					if (ss)
						g = ft_strlen2(ss);
					if (!ss)
						g = 6;
					if (indpr == 1)
					{
						if (pr > w)
						{
							if (zero == 0)
							{
								if (w < 0)
								{
									w = -w;
									if (ss)
									{
										cnt = cnt + ft_putwstr(ss);
									}
									else
									{
										ft_putstr("(null)");
										cnt = cnt + 6;
									}
									while((w - g) > 0)
									{
										cnt++;
										ft_putchar(' ');
										w--;
									}
								}
								else
								{
									while((w - g) > 0)
									{
										cnt++;
										ft_putchar(' ');
										w--;
									}
									if (ss)
									{
										cnt = cnt + ft_putwstr2(pr,ss);
									}
									else
									{
										ft_putstr("(null)");
										cnt = cnt + 6;
									}
								}
							}
							else
							{
								if (w < 0)
								{
									w = -w;
									if (ss)
									{
										cnt = cnt + ft_putwstr(ss);
									}
									else
									{
										ft_putstr("(null)");
										cnt = cnt + 6;
									}
									while((w - g) > 0)
									{
										cnt++;
										ft_putchar('0');
										w--;
									}
								}
								else
								{
									while((w - g) > 0)
									{
										cnt++;
										ft_putchar('0');
										w--;
									}
									if (ss)
									{
										cnt = cnt + ft_putwstr(ss);
									}
									else
									{
										ft_putstr("(null)");
										cnt = cnt + 6;
									}
								}
							}
						}
						else if (w > pr)
						{
							if (zero == 0)
							{
								if (w < 0)
								{
									w = -w;
									if (ss)
									{
										cnt = cnt + ft_putwstr(ss);
									}
									else
									{
										ft_putstr("(null)");
										cnt = cnt + 6;
									}
									while((w - g) > 0)
									{
										cnt++;
										ft_putchar(' ');
										w--;
									}
								}
								else
								{
									while((w - ft_countwstr(pr,ss)) > 0)
									{
										cnt++;
										ft_putchar(' ');
										w--;
									}
									if (ss)
									{
										cnt = cnt + ft_putwstr2(pr,ss);
									}
									else
									{
										ft_putstr("(null)");
										cnt = cnt + 6;
									}
								}
							}
							else
							{
								if (w < 0)
								{
									w = -w;
									if (ss)
									{
										cnt = cnt + ft_putwstr(ss);
									}
									else
									{
										ft_putstr("(null)");
										cnt = cnt + 6;
									}
									while((w - g) > 0)
									{
										cnt++;
										ft_putchar('0');
										w--;
									}
								}
								else
								{
									while((w - g) > 0)
									{
										cnt++;
										ft_putchar('0');
										w--;
									}
									if (ss)
									{
										cnt = cnt + ft_putwstr(ss);
									}
									else
									{
										ft_putstr("(null)");
										cnt = cnt + 6;
									}
								}
							}
						}
					}
					else
					{
						if (zero == 0)
						{
							if (w < 0)
							{
								w = -w;
								if (ss)
								{
									cnt = cnt + ft_putwstr(ss);
								}
								else
								{
									ft_putstr("(null)");
									cnt = cnt + 6;
								}
								while((w - g) > 0)
								{
									cnt++;
									ft_putchar(' ');
									w--;
								}
							}
							else
							{
								while((w - g) > 0)
								{
									cnt++;
									ft_putchar(' ');
									w--;
								}
								if (ss)
								{
									cnt = cnt + ft_putwstr(ss);
								}
								else
								{
									ft_putstr("(null)");
									cnt = cnt + 6;
								}
							}
						}
						else
						{
							if (w < 0)
							{
								w = -w;
								if (ss)
								{
									cnt = cnt + ft_putwstr(ss);
								}
								else
								{
									ft_putstr("(null)");
									cnt = cnt + 6;
								}
								while((w - g) > 0)
								{
									cnt++;
									ft_putchar('0');
									w--;
								}
							}
							else
							{
								while((w - g) > 0)
								{
									cnt++;
									ft_putchar('0');
									w--;
								}
								if (ss)
								{
									cnt = cnt + ft_putwstr(ss);
								}
								else
								{
									ft_putstr("(null)");
									cnt = cnt + 6;
								}
							}
						}
					}
					ind2 = 0;
					w = 0;
					pr = 0;
					indletter = 1;
					indpr = 0;
				}
				else if (*str == 'p')
				{
					l = va_arg(ap, long);
					g =(ft_strlen(ft_ltohex(l)));
					if (zero == 1)
					{
						ft_putstr("0x");
						ft_putstrad(ft_ltohex(l));
						while((w - (g + 2)) > 0)
						{
							cnt++;
							ft_putchar('0');
							w--;
						}
					}
					else
					{
						if (w < 0)
						{
							w = -w;
							ft_putstr("0x");
							ft_putstrad(ft_ltohex(l));
							while((w - (g + 2)) > 0)
							{
								cnt++;
								ft_putchar(' ');
								w--;
							}
						}
						else
						{
							while((w - (g + 2)) > 0)
							{
								cnt++;
								ft_putchar(' ');
								w--;
							}
							ft_putstr("0x");
							ft_putstrad(ft_ltohex(l));
						}
					}
					cnt = cnt + g + 2;
					int o = 0;
					if (g < 9 && g > 1)
					{
						while (o < 9 - g)
						{
							cnt++;
							o++;
						}
					}
					ind2 = 0;
					w = 0;
					pr = 0;
					indletter = 1;
					indpr = 0;
				}
				else if (*str == 'u')
				{
					u = va_arg(ap, unsigned int);
//					ft_putunbr(u);
//					cnt = cnt + ft_countu(u);
					if (pr == 0 && w == 0 && indpr == 1)
					{
					}
					else
					{
						if(w < 0)
						{
							ft_putunbr(w,pr,zero,u);
							cnt = cnt + ft_countu(w,pr,zero,e,u);
						}
						else
						{
							cnt = cnt + ft_countu(w,pr,zero,e,u);
							ft_putunbr(w,pr,zero,u);
						}
					}
					ind2 = 0;
					w = 0;
					pr = 0;
					indletter = 1;
					zero = 0;
					indpr = 0;
					e.indplus = 0;
					e.indspace = 0;
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
//					if (e.indspace == 1 && d >= 0 && e.indplus == 0)
//					{
//						ft_putchar(' ');
//						cnt++;
//					}
					if (pr == 0 && w == 0 && indpr == 1)
					{
					}
					else
					{
						if(w < 0)
						{
							ft_putnbr(w,pr,zero,d);
							cnt = cnt + ft_countd(w,pr,zero,e,d);
						}
						else
						{
							cnt = cnt + ft_countd(w,pr,zero,e,d);
							ft_putnbr(w,pr,zero,d);
						}
					}
					ind2 = 0;
					w = 0;
					pr = 0;
					indletter = 1;
					zero = 0;
					indpr = 0;
					e.indplus = 0;
					e.indspace = 0;
				}
				else if (*str == 'D')
				{
					l = va_arg(ap, long);
					ft_putlongnbr(l);
					cnt = cnt + ft_countl(l);
				}
				else if (*str == 'x')
				{
					u = va_arg(ap, unsigned int);
					if (u == 0 && pr == 0 & indpr == 1)
					{
					}
					else
					{
					s2 = ft_ltohex(u);
					g = ft_strlen(s2);
					if (e.indsharp == 1 && u != 0)
					{
						ft_putchar('0');
						ft_putchar('x');
						cnt++;
						cnt++;
					}
					if (zero == 1 && pr == 0)
					{
						while(w - g > 0)
						{
							ft_putchar('0');
							cnt++;
							w--;
						}
					}
					else
					{
						if (pr >= g)
						{
							while(w - pr > 0)
							{
								ft_putchar(' ');
								cnt++;
								w--;
							}

							while((pr - g) > 0)
							{
								ft_putchar('0');
								cnt++;
								pr--;
							}
						}
						else
						{
							while(w - g > 0)
							{
								ft_putchar(' ');
								cnt++;
								w--;
							}
						}
					}
					ft_putstr(s2);
					cnt = cnt + g;
					}
					ind2 = 0;
					w = 0;
					pr = 0;
					indletter = 1;
					zero = 0;
					indpr = 0;

				}
				else if (*str == 'X')
				{
					u = va_arg(ap, unsigned int);
					if (u == 0 && pr == 0 & indpr == 1)
					{
					}
					else
					{
					s2 = ft_ltohex2(u);
					g = ft_strlen(s2);
					if (e.indsharp == 1 && u != 0)
					{
						ft_putchar('0');
						ft_putchar('X');
						cnt++;
						cnt++;
					}
					if (zero == 1 && pr == 0)
					{
						while(w - g > 0)
						{
							ft_putchar('0');
							cnt++;
							w--;
						}
					}
					else
					{
						if (pr >= g)
						{
							while(w - pr > 0)
							{
								ft_putchar(' ');
								cnt++;
								w--;
							}

							while((pr - g) > 0)
							{
								ft_putchar('0');
								cnt++;
								pr--;
							}
						}
						else
						{
							while(w - g > 0)
							{
								ft_putchar(' ');
								cnt++;
								w--;
							}
						}
					}
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					}
					ind2 = 0;
					w = 0;
					pr = 0;
					indletter = 1;
					zero = 0;
					indpr = 0;
				}
				else if (*str == 'o')
				{
					u = va_arg(ap, unsigned int);
					if (u == 0 && pr == 0 && indpr == 1)
					{
					}
					else
					{
					s2 = ft_ltooct(u);
					g = ft_strlen(s2);
					if (e.indsharp == 1 && u != 0)
					{
						ft_putchar('0');
						cnt++;
					}
					if (zero == 1 && pr == 0)
					{
						while(w - g > 0)
						{
							ft_putchar('0');
							cnt++;
							w--;
						}
					}
					else
					{
						if (pr >= g)
						{
							while(w - pr > 0)
							{
								ft_putchar(' ');
								cnt++;
								w--;
							}

							while((pr - g) > 0)
							{
								ft_putchar('0');
								cnt++;
								pr--;
							}
						}
						else
						{
							while(w - g > 0)
							{
								ft_putchar(' ');
								cnt++;
								w--;
							}
						}
					}
					ft_putstr(s2);
					cnt = cnt + g;
					}
					ind2 = 0;
					w = 0;
					pr = 0;
					indletter = 1;
					zero = 0;
					indpr = 0;
					e.indsharp = 0;
				}
				else if (*str == 'O')
				{
					ul = va_arg(ap,  unsigned long);
					if (ul == 0 && pr == 0 && indpr == 1 && e.indsharp == 0)
					{
					}
					else
					{
						s2 = ft_ltooct2(ul);
						g = ft_strlen(s2);
						if (e.indsharp == 1 && ul != 0)
						{
							ft_putchar('0');
							cnt++;
						}
						if (zero == 1 && pr == 0)
						{
							while(w - g > 0)
							{
								ft_putchar('0');
								cnt++;
								w--;
							}
						}
						else
						{
							if (pr >= g)
							{
								while(w - pr > 0)
								{
									ft_putchar(' ');
									cnt++;
									w--;
								}

								while((pr - g) > 0)
								{
									ft_putchar('0');
									cnt++;
									pr--;
								}
							}
							else
							{
								while(w - g > 0)
								{
									ft_putchar(' ');
									cnt++;
									w--;
								}
							}
						}
						ft_putstr(s2);
						cnt = cnt + g;
					}
					ind2 = 0;
					w = 0;
					pr = 0;
					indletter = 1;
					zero = 0;
					indpr = 0;
					e.indsharp = 0;
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
					cnt = cnt + ft_countd(w,pr,zero,e,c);
					ft_putnbr(w,pr,zero,c);
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
					ft_putnbr(w,pr,zero,uc);
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
				else if ((*str >= '0' && *str <= '9') || *str == '-' || *str == '.' || *str == ' ')
				{
					if (*str == '.')
						indpr = 1;
					if (ind2 == 0)
					{
						i = 0;
						while (ft_checkletter(str) == 0)
						{
							i++;
							str++;
						}
						str--;
						s3 = (char*)malloc(sizeof(char)*i + 1);
						s3[i] = 0;
						while(i > 0)
						{
							s3[i - 1] = *str;
							i--;
							str--;
						}
//											printf("s3 = %s\n",s3);
						if (w == 0)
							w = ft_checkwidth(s3);
						if (pr == 0)
							pr = ft_checkprec(s3);
						if (str[1] == '0')
							zero = 1;
					}
//									printf("w = %d\n",w);
					//				printf("pr = %d\n",pr);
					ind2 = 1;
				}
				else
				{
					//				i = 0;
					//				b = 0;
					//				while(s3[i] != 0)
					//				{
					//					
					//					if (s3[i] != '.' && !(s3[i] >= '0' && s3[i] <= '9'))
					//						b++;
					//					i++;
					//				}
					//				printf("S3 = %s,b= %d\n",s3,b);
					if (indletter == 1)
					{
						while((w - 1) > 0)
						{
							ft_putchar(' ');
							cnt++;
							w--;
						}
					}
					if (zero == 1)
					{
						while((w - 1) > 0)
						{
							cnt++;
							ft_putchar('0');
							w--;
						}
						ft_putchar(*str);
					}
					else
					{
						if (w < 0)
						{
							w = -w;
							ft_putchar(*str);
							while((w - 1) > 0)
							{
								cnt++;
								ft_putchar(' ');
								w--;
							}
						}
						else
						{
							while((w - 1) > 0)
							{
								cnt++;
								ft_putchar(' ');
								w--;
							}
							ft_putchar(*str);
						}
					}
					ind2 = 0;
					w = 0;
					pr = 0;
					cnt++;
					indletter = 0;
				}
			}
			else
			{
				ft_putchar(*str);
				cnt++;
			}
//				printf("str = %c\n",*str);
			if (*str != 0)
				str++;
		}
//			}
	}


	else if (ind1 % 2 == 1)
	{
		//		bigi = &(str[0]);
		cnt1 = 0;
		cnt2 = 0;
		c2 = 0;
		//				printf("str = %c\n",*str);
		//			p = ft_check_perc(str);
		//			p3 = p;
		indlast = 0;
		//			printf("p3 = %s\n",p3);
		/*
		   while((*str != 0) && (*str == '%' || *str == ' ') && p == NULL)
		   {
		   if (*str == '%')
		   c2++;
		   if ((c2 % 2 == 1) && (str[1] == ' '))
		   {
		   if (str != p3)
		   p = str;
		   else
		   c2--;
		   }
		   str++;
		   }
*/
//		str = bigi;
//				printf("cnt1 = %d,str = %c begi = %c \n",cnt1,*str,begi[ft_strlen(begi)-2]);
//			printf("str = %s\n",str);
		while (*str != 0)
		{
			//				printf("cnt1 = %d,str = %c begi = %c \n",cnt1,*str,begi[ft_strlen(begi)-2]);
//				printf("check = %d\n",ft_checkstrlast(str));
				if (*str == '%')
				{
					str++;
						i = 0;
						while (((*str >= '0' && *str <= '9') || *str == '-' || *str == '.' || *str == ' '))
						{
							i++;
							str++;
						}
						begi = str;
//						printf("begi =%c\n",*begi);
						str--;
						s3 = (char*)malloc(sizeof(char)*i + 1);
						s3[i] = 0;
						while(i > 0)
						{
							s3[i - 1] = *str;
							i--;
							str--;
						}
						//					printf("s3 = %s\n",s3);
						if (w == 0)
							w = ft_checkwidth(s3);
						if (pr == 0)
							pr = ft_checkprec(s3);
						if (str[1] == '0')
							zero = 1;
//				printf("w = %d\n",w);
//				printf("pr = %d\n",pr);
				if (w != 0 || pr != 0 || zero != 0)
					str = begi;
				}
			if (ft_checkstrlast(str) && *str == '%')
			{
				indlast = 1;
				//					cntlast = cnt1;
			}
			if (cnt1 % 2 == 0)
			{
				if (*str == '%' && indlast == 1)
				{
				}
				else
				{
					if (zero == 0)
					{
						if(w < 0)
						{
							w = -w;
							ft_putchar(*str);
							cnt++;
							while((w - 1) > 0)
							{
								cnt++;
								ft_putchar(' ');
								w--;
							}
						}
						else
						{
							while((w - 1) > 0)
							{
								cnt++;
								ft_putchar(' ');
								w--;
							}
							ft_putchar(*str);
							cnt++;
						}
					}
					else if (zero == 1)
					{
						if(w < 0)
						{
							w = -w;
							ft_putchar(*str);
							cnt++;
							while((w - 1) > 0)
							{
								cnt++;
								ft_putchar('0');
								w--;
							}
						}
						else
						{
							while((w - 1) > 0)
							{
								cnt++;
								ft_putchar('0');
								w--;
							}
							ft_putchar(*str);
							cnt++;
						}
					}
					w = 0;
					pr = 0;
					zero = 0;
				}
			}
			if (*str == '%')
				cnt1++;
			if (cnt1 % 2 == 1 && indlast == 1)
				cnt1++;
			str++;
		}
	}


	va_end(ap);
	return (cnt);
}
