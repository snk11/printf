/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 01:53:43 by syusof            #+#    #+#             */
/*   Updated: 2016/02/01 14:38:30 by syusof           ###   ########.fr       */
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
	char		*bigi;
	char		*bigi2;
	int		cnt1;
	int c2;
	char	*p3;
	int		ind1;
	int		w;
	int		pr;
	int		ind2;
	int		g;
//	int		b;

	
	cnt = 0;
	ind1 = 0;
	w = 0;
	pr = 0;
	ind2 = 0;
	va_start(ap, str);
	bigi = &(str[0]);

	p = ft_check_perc0(str);
	if (p != NULL)
		ind1++;
	
	while(*str !=0)
	{

	
	if (ind1 % 2 == 0)
	{
		p = ft_check_perc(str);

	while (*str != 0 && str !=p)
	{
		if ( *str == '%' || ind2 == 1)
		{
			cnt1 = 1;
			str++;
			if (ind2 == 1)
				str--;
//			printf("ind2 = %d,str1 =%c\n",ind2,*str);
			if (*str == '%')
				cnt1++;
//			printf("p1 = %d\n", p);
			 if (*str == 0)
			{
			}
			else if (*str == 'c')
			{
				c = va_arg(ap, int);
				while((w - 1) > 0)
				{
					cnt++;
					ft_putchar(' ');
					w--;
				}
				ft_putchar(c);
				cnt++;
				ind2 = 0;
				w = 0;
				pr = 0;
			}
			else if (*str == 'C')
			{
				wc = va_arg(ap, wchar_t);
				cnt = cnt + ft_putwchar(wc);
			}
			else if (*str == 's')
			{
				s = va_arg(ap, char*);
				if (s)
				{
						ft_putstr(s);
					i = 0;
					while (i < ft_strlen(s))
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
			else if (*str == 'S')
			{
				ss = va_arg(ap, wchar_t*);
				if (ss)
					g = ft_strlen2(ss);
				if (!ss)
					g = 6;
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
				ind2 = 0;
				w = 0;
				pr = 0;
			}
			else if (*str == 'p')
			{
				l = va_arg(ap, long);
				g =(ft_strlen(ft_ltohex(l)));
				while((w - (g + 2)) > 0)
				{
					cnt++;
					ft_putchar(' ');
					w--;
				}
				ft_putstr("0x");
				ft_putstrad(ft_ltohex(l));
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
			}
			else if (*str == 'u')
			{
				u = va_arg(ap, unsigned int);
				ft_putunbr(u);
				cnt = cnt + ft_countu(u);
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
				cnt = cnt + ft_countd(w,pr,d);
				ft_putnbr(d);
				ind2 = 0;
				w = 0;
				pr = 0;
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
				s2 = ft_ltohex(u);
				ft_putstr(s2);
				cnt = cnt + ft_strlen(s2);
			}
			else if (*str == 'X')
			{
				u = va_arg(ap, unsigned int);
				s2 = ft_ltohex2(u);
				ft_putstr(s2);
				cnt = cnt + ft_strlen(s2);
			}
			else if (*str == 'o')
			{
				u = va_arg(ap, unsigned int);
				s2 = ft_ltooct(u);
				ft_putstr(s2);
				cnt = cnt + ft_strlen(s2);
			}
			else if (*str == 'O')
			{
				ul = va_arg(ap,  unsigned long);
				s2 = ft_ltooct2(ul);
				ft_putstr(s2);
				cnt = cnt + ft_strlen(s2);
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
				ft_putnbr(c);
				cnt = cnt + ft_countd(w,pr,c);
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
				ft_putnbr(uc);
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
			else if (*str == '%' && cnt1 % 2 == 1)
			{
			}
			else if (((*str >= '0' && *str <= '9') || *str == '-' || *str == '.' || *str == ' '))
			{
				if (ind2 == 0)
				{
					i = 0;
					while(*str != 'd' && *str != 'c' && *str != 'p')
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
//					printf("s3 = %s\n",s3);
					if (w == 0)
						w = ft_checkwidth(s3);
					if (pr == 0)
						pr = ft_checkprec(s3);
				}
//				printf("w = %d\n",w);
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
				while((w - 1) > 0)
			{
				ft_putchar(' ');
				cnt++;
				w--;
			}
				ft_putchar(*str);
				ind2 = 0;
				w = 0;
				pr = 0;
				cnt++;
			}
		}
		else
		{
			ft_putchar(*str);
			cnt++;
		}
		if (*str != 0)
			str++;
//		printf("str = %c\n",*str);
	}
	ind1++;

	}



	if (ind1 % 2 == 1)
	{
//		bigi = &(str[0]);
		cnt1 = 0;
		c2 = 0;
		p = ft_check_perc(str);
		p3 = p;
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
		while (*str != 0 && str != p)
		{
			if (*str != ' ')
			{
				if (*str == '%')
					cnt1++;
				if (*str == '%' && str[1] == ' ')
				{
				}
				if (*str == '%' && cnt1 % 2 == 1)
				{
				}
				else
				{
					ft_putchar(*str);
					cnt++;
				}
			}
			if (*str != 0)
				str++;
		}
//		bigi = str;
	}
	if(*str == '%')
	{
		ft_putchar(*str);
	}
	ind1++;
	
	}


	 va_end(ap);
	return (cnt);
}
