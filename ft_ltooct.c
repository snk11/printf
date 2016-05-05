/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltooct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:11:15 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 15:06:17 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ltooct(long l)
{
	char	*res;
	int		i;
	long	l1;

	l1 = l;
	i = 1;
	while (l > 8)
	{
		l = l / 8;
		i++;
	}
	if (l1 >= 512 && l1 <= 575)
	{
		i++;
		res = (char*)malloc(sizeof(char) * (i + 1));
	}
	else
		res = (char*)malloc(sizeof(char) * (i + 1));
	res[i] = 0;
	l = l1;
	if (l1 >= 512 && l1 <= 575)
		ft_ltooct10(res, l, i);
	else
		ft_ltooct11(res, l, i);
	return (res);
}

void	ft_ltooct10(char *res, long l, int i)
{
	res = res + i - 1;
	while (l > 8)
	{
		*res = '0' + l % 8;
		l = l / 8;
		res--;
	}
	*res = '0' + l % 8;
	res--;
	*res = '1';
}

void	ft_ltooct11(char *res, long l, int i)
{
	res = res + i - 1;
	while (l > 8)
	{
		*res = '0' + l % 8;
		l = l / 8;
		res--;
	}
	*res = '0' + l % 8;
}

void	ft_ltooct12(char *res, unsigned long l, int i)
{
	res = res + i - 1;
	while (l > 8)
	{
		*res = '0' + l % 8;
		l = l / 8;
		res--;
	}
	*res = '0' + l % 8;
}

void	ft_ltooct13(char *res, unsigned short l, int i)
{
	res = res + i - 1;
	while (l > 8)
	{
		*res = '0' + l % 8;
		l = l / 8;
		res--;
	}
	*res = '0' + l % 8;
}
