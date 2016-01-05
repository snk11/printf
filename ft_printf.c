/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 01:53:43 by syusof            #+#    #+#             */
/*   Updated: 2016/01/05 03:40:48 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

# include <stdio.h>

int	ft_printf(char *str, ...)
{
	
	va_list		ap;
	int			d;
	unsigned int	u;
	long		l;
	unsigned long		ul;
	char		*s;
	char		*s2;
	char		c;
	int			cnt;
	int			i;
	int			ind1;
	wchar_t		*ss;

	
	cnt = 0;
	ind1 = 0;
	va_start(ap, str);
	while (*str != 0)
	{
		if ( *str == '%' && ind1 == 0)
		{
			str++;
			if (*str == '%')
				ft_putstr("%");
			else if (*str == 0)
				cnt--;
			else if (*str == 'c')
			{
				c = va_arg(ap, int);
				ft_putchar(c);
			}
			else if (*str == 'C')
			{
				c = va_arg(ap, int);
				ft_putchar(c);
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
				cnt--;
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
				cnt--;
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
				cnt--;
			}
			else if (*str == 'u')
			{
				ul = va_arg(ap, unsigned long);
				ft_putlongnbr(ul);
				cnt = cnt + ft_countl(ul);
				cnt--;
			}
			else if (*str == 'U')
			{
				ul = va_arg(ap, unsigned long);
				ft_putulongnbr(ul);
				cnt = cnt + ft_countul(ul);
				cnt--;
			}
			else if (*str == 'd' || *str == 'i')
			{
				d = va_arg(ap, int);
				ft_putnbr(d);
				cnt = cnt + ft_countd(d);
				cnt--;
			}
			else if (*str == 'D')
			{
				l = va_arg(ap, long);
				ft_putlongnbr(l);
				cnt = cnt + ft_countl(l);
				cnt--;
			}
			else if (*str == 'x')
			{
				u = va_arg(ap, unsigned int);
				s2 = ft_ltohex(u);
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
				cnt--;
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
				cnt--;
			}
			else if (*str == 'o')
			{
				u = va_arg(ap, unsigned int);
				s2 = ft_ltooct(u);
				ft_putstr(s2);
				cnt = cnt + ft_strlen(s2);
				cnt--;
			}
			else if (*str == 'O')
			{
				ul = va_arg(ap,  unsigned long);
				s2 = ft_ltooct2(ul);
				ft_putstr(s2);
				cnt = cnt + ft_strlen(s2);
				cnt--;
			}
			else
			{
				str--;
				cnt--;
			}
			cnt++;
		}
		else if (*str == '%' && ind1 != 0)
		{
			ft_putchar(*str);
			cnt++;
		}
		else
		{
			ft_putchar(*str);
			cnt++;
		}
		if (*str == '%')
		{
			str++;
			while (*str == ' ')
			{
				str++;
				ind1 = 1;
			}
		}
		else if (*str != 0)
			str++;
	}
	 va_end(ap);
	return (cnt);
}
