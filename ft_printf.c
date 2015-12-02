/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 01:53:43 by syusof            #+#    #+#             */
/*   Updated: 2015/12/02 12:56:54 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

# include <stdio.h>

int	ft_printf(char *str, ...)
{
	va_list		ap;
	int			d;
	long		l;
	char		*s;
	char		c;
	int			cnt;
	int			i;

	
	cnt = 0;
	va_start(ap, str);
	while (*str != 0)
	{
		if ( *str == '%')
		{
			str++;
			if (*str == '%')
				ft_putstr("%");
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
			else if (*str == 'p')
			{
				l = va_arg(ap, long);
//				ft_putnbr(l);
//				cnt = cnt + ft_countd(l);
				cnt = cnt + printf("%p",l);
				cnt--;
			}
			else if (*str == 'd')
			{
				d = va_arg(ap, int);
				ft_putnbr(d);
				cnt = cnt + ft_countd(d);
				cnt--;
			}
			cnt++;
		}
		else
		{
			ft_putchar(*str);
			cnt++;
		}
		str++;
	}
	 va_end(ap);
	return (cnt);
}
