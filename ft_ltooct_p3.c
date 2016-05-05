/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltooct_p3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 15:04:48 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 15:05:15 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ltooct4(unsigned long long l)
{
	char				*res;
	char				*bigi;
	int					i;
	unsigned long long	l1;

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
	ft_ltooct14(res, l, i);
	return (bigi);
}

char	*ft_ltooct5(unsigned short int l)
{
	char				*res;
	char				*bigi;
	int					i;
	unsigned short int	l1;

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
	ft_ltooct15(res, l, i);
	return (bigi);
}

char	*ft_ltooct6(unsigned char l)
{
	char			*res;
	char			*bigi;
	int				i;
	unsigned char	l1;

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
	ft_ltooct16(res, l, i);
	return (bigi);
}
