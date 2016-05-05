/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltohex_p4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 15:01:27 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 15:02:28 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ltohex7(unsigned short l)
{
	char			*res;
	char			*bigi;
	int				i;
	unsigned short	l1;

	bigi = NULL;
	l1 = l;
	i = 1;
	while (l > 16)
	{
		l = l / 16;
		i++;
	}
	res = (char*)malloc(sizeof(char) * (i + 1));
	res[i] = 0;
	bigi = res;
	l = l1;
	res = res + i - 1;
	while (l > 16)
		ft_ltohex17(&res, &l);
	ft_ltohex17(&res, &l);
	return (bigi);
}

char	*ft_ltohex8(unsigned char l)
{
	char			*res;
	char			*bigi;
	int				i;
	unsigned long	l1;

	bigi = NULL;
	l1 = l;
	i = 1;
	while (l > 16)
	{
		l = l / 16;
		i++;
	}
	res = (char*)malloc(sizeof(char) * (i + 1));
	res[i] = 0;
	bigi = res;
	l = l1;
	res = res + i - 1;
	while (l > 16)
		ft_ltohex18(&res, &l);
	ft_ltohex18(&res, &l);
	return (bigi);
}

char	*ft_ltohex9(unsigned char l)
{
	char			*res;
	char			*bigi;
	int				i;
	unsigned char	l1;

	bigi = NULL;
	l1 = l;
	i = 1;
	while (l > 16)
	{
		l = l / 16;
		i++;
	}
	res = (char*)malloc(sizeof(char) * (i + 1));
	res[i] = 0;
	bigi = res;
	l = l1;
	res = res + i - 1;
	while (l > 16)
		ft_ltohex19(&res, &l);
	ft_ltohex19(&res, &l);
	return (bigi);
}
