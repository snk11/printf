/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 01:53:43 by syusof            #+#    #+#             */
/*   Updated: 2016/01/26 13:47:43 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

# include <stdio.h>

int	ft_printf(char *str, ...)
{
	
	va_list		ap;
	int			d;
	unsigned int	u;
	unsigned short	us;
	long		l;
	long int	ld;
	unsigned long		ul;
	char		*s;
	char		*s2;
	char		c;
	int			cnt;
	int			i;
	char		*p;
	int bl;
	int			max;
	wchar_t		*ss;
	wchar_t		wc;
	char		*bigi;
	int		cnt1;
	int c2;
	char	*p3;
	int		ind1;

	
	cnt = 0;
	ind1 = 0;
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
		if ( *str == '%')
		{
			cnt1 = 1;
			str++;
			if (*str == '%')
				cnt1++;
//			printf("p1 = %d\n", p);
			 if (*str == 0)
			{
			}
			else if (*str == 'c')
			{
				c = va_arg(ap, int);
				ft_putchar(c);
				cnt++;
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
				{
					cnt = cnt + ft_putwstr(ss);
				}
				else
				{
					ft_putstr("(null)");
					cnt = cnt + 6;
				}
			}
			else if (*str == 'p')
			{
				l = va_arg(ap, long);
				ft_putstr("0x");
				ft_putstrad(ft_ltohex(l));
				cnt = cnt + ft_strlen(ft_ltohex(l)) + 2;
				int g;
				g =(ft_strlen(ft_ltohex(l)));
				int o = 0;
				if (g < 9 && g > 1)
				{
					while (o < 9 - g)
					{
						cnt++;
						o++;
					}
				}
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
				ft_putnbr(d);
				cnt = cnt + ft_countd(d);
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
//				d = printf("%s",s2);
//				s2 = "e82183e";
				ft_putstr(s2);
//				printf("%x",u);
//				d = printf("%x",u);
//				printf("strlen = %d\n",ft_strlen(s2));
//				printf("%d\n",d);
				cnt = cnt + ft_strlen(s2);
//				cnt = cnt + d;
//				cnt = 9;
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
				ld = va_arg(ap, long);
				ft_putldnbr(ld);
				cnt = cnt + ft_countld(ld);
				str++;
			}
			else if (*str == 'l' && str[1] == 'u')
			{
				ul = va_arg(ap, unsigned long);
				ft_putulongnbr(ul);
				cnt = cnt + ft_countul(ul);
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
			else if (*str == 'l' && str[1] == 'x')
			{
				ul = va_arg(ap, unsigned long);
				s2 = ft_ltohex3(ul);
				ft_putstr(s2);
				cnt = cnt + ft_strlen(s2);
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
			else if (*str == 'l' && str[1] == 'c')
			{
				wc = va_arg(ap, wchar_t);
				cnt = cnt + ft_putwchar(wc);
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
			else if (*str == 'l' && str[1] == 'O')
			{
				us = va_arg(ap, unsigned short);
				s2 = ft_ltooct3(us);
				ft_putstr(s2);
				cnt = cnt + ft_strlen(s2);
				str++;
			}
			else if (*str == 'l' && (str[1] == 'U' || str[1] == 'D'))
			{
				us = va_arg(ap, unsigned short);
				ft_putushortnbr(us);
				cnt = cnt + ft_countus(us);
				str++;
			}
			else if (*str == '%' && cnt1 % 2 == 1)
			{
			}
			else
			{
				ft_putchar(*str);
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
