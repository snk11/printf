/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltooct_p2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 15:04:21 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 15:05:36 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ltooct14(char *res, unsigned long long l, int i)
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

void	ft_ltooct15(char *res, unsigned short int l, int i)
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

void	ft_ltooct16(char *res, unsigned char l, int i)
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

char	*ft_ltooct2(unsigned long l)
{
	char			*res;
	char			*bigi;
	int				i;
	unsigned long	l1;

	bigi = NULL;
	l1 = l;
	if ((long)l == LONG_MIN)
		return ("1000000000000000000000");
	i = 1;
	while (l > 8)
	{
		l = l / 8;
		i++;
	}
	res = (char*)malloc(sizeof(char) * (i + 1));
	res[i] = 0;
	bigi = res;
	l = l1;
	ft_ltooct12(res, l, i);
	return (bigi);
}

char	*ft_ltooct3(unsigned short l)
{
	char			*res;
	char			*bigi;
	int				i;
	unsigned short	l1;

	bigi = NULL;
	l1 = l;
	i = 1;
	while (l > 8)
	{
		l = l / 8;
		i++;
	}
	res = (char*)malloc(sizeof(char) * (i + 1));
	res[i] = 0;
	bigi = res;
	l = l1;
	ft_ltooct13(res, l, i);
	return (bigi);
}
