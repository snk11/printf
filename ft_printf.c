/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 01:53:43 by syusof            #+#    #+#             */
/*   Updated: 2015/11/25 03:37:53 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"


void	ft_printf(char *str, ...)
{
	va_list		ap;
	int			d;
	char		*s;
	char		c;


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
				ft_putstr(s);
			}
			else if (*str == 'd')
			{
				d = va_arg(ap, int);
				ft_putnbr(d);
			}
		}
		else
			ft_putchar(*str);
		str++;
	}
	va_end(ap);
}
