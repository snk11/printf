/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 08:29:33 by syusof            #+#    #+#             */
/*   Updated: 2016/01/12 18:36:11 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"


int	ft_countd(int n)
{
	int i;

	i = 0;
	if (n == -2147483648)
		return (11);
	else
	{
		if (n < 0)
		{
			i++;
			n = -n;
		}
		if (n >= 10)
		{
			while (n >= 10)
			{
				n = n / 10;
				i++;
			}
		}
		i++;
	}
	return (i);
}


int	ft_countl(long n)
{
	int i;

	i = 0;
	if (n == LONG_MIN)
		return (20);
	else
	{
		if (n < 0)
		{
			i++;
			n = -n;
		}
		if (n >= 10)
		{
			while (n >= 10)
			{
				n = n / 10;
				i++;
			}
		}
		i++;
	}
	return (i);
}

int	ft_countu(unsigned int n)
{
	int i;
	unsigned long c;

	c = 0;
	i = 0;
	if (n == UINT_MAX)
		return (10);
	else
	{
		if (n >= 10)
		{
			while (n >= 10)
			{
				n = n / 10;
				i++;
			}
		}
		i++;
	}
	return (i);
}

int	ft_countul(unsigned long n)
{
	int i;
	unsigned long c;

	c = 0;
	i = 0;
	if (n == ULONG_MAX)
		return (20);
	else
	{
		if (n >= 10)
		{
			while (n >= 10)
			{
				n = n / 10;
				i++;
			}
		}
		i++;
	}
	return (i);
}
