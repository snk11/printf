/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:50:22 by syusof            #+#    #+#             */
/*   Updated: 2016/02/09 17:44:00 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char const *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_putstr2(int pr,char const *s)
{
	int		i;

	i = 0;
	while (s[i] && pr > 0)
	{
		ft_putchar(s[i]);
		i++;
		pr--;
	}
}

void	ft_putstrad(char const *s)
{
	int		i;
	int n;

	i = 0;
	n = 0;
	while (s[i])
	{
		i++;
	}
	if (i < 9 && i > 1)
	{
		while(n < 9 - i)
		{
			ft_putchar('1');
			n++;
		}
	}
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_putstrad2(int pr,char const *s)
{
	int		i;
	int n;

	i = 0;
	n = 0;
	while (s[i])
	{
		i++;
	}
	if (pr > i)
	{
		if (i < pr && i > 1)
		{
			while(n < pr - i)
			{
				ft_putchar('0');
				n++;
			}
		}
		i = 0;
		while (s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
	}
	else
	{
		i = 0;
		while (s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
	}
}

void	ft_putstrad3(int pr,char const *s)
{
	int		i;
	int n;

	i = 0;
	n = 0;
	while (s[i])
	{
		i++;
	}
	if (pr > i)
	{
		if (i < pr && i >= 1)
		{
			while(n < pr - i)
			{
				ft_putchar('0');
				n++;
			}
		}
		i = 0;
		while (s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
	}
	else
	{
		i = 0;
		while (s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
	}
}
