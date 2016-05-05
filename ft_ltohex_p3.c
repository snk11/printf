/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltohex_p3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 15:01:17 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 15:03:19 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ltohex2(unsigned long l)
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
		ft_ltohex12(&res, &l);
	ft_ltohex12(&res, &l);
	return (bigi);
}

char	*ft_ltohex3(unsigned long l)
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
		ft_ltohex13(&res, &l);
	ft_ltohex13(&res, &l);
	return (bigi);
}

char	*ft_ltohex4(unsigned long long l)
{
	char				*res;
	char				*bigi;
	int					i;
	unsigned long long	l1;

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
		ft_ltohex14(&res, &l);
	ft_ltohex14(&res, &l);
	return (bigi);
}

char	*ft_ltohex5(unsigned long long l)
{
	char				*res;
	char				*bigi;
	int					i;
	unsigned long long	l1;

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
		ft_ltohex15(&res, &l);
	ft_ltohex15(&res, &l);
	return (bigi);
}

char	*ft_ltohex6(unsigned short l)
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
		ft_ltohex16(&res, &l);
	ft_ltohex16(&res, &l);
	return (bigi);
}
