/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 01:53:43 by syusof            #+#    #+#             */
/*   Updated: 2015/12/16 04:11:02 by syusof           ###   ########.fr       */
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
	char		*s;
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
					cnt = ft_putwstr(ss);
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
//				ft_putlongnbr(l);
				ft_putstr("0x");
				ft_putstr(ft_ltohex(l));
				cnt = cnt + ft_strlen(ft_ltohex(l)) + 2;
				cnt--;
			}
			else if (*str == 'u')
			{
				u = va_arg(ap, unsigned int);
				ft_putlongnbr(u);
				cnt = cnt + ft_countl(u);
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
