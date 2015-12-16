/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 02:47:12 by syusof            #+#    #+#             */
/*   Updated: 2015/12/16 08:23:01 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

char	*ft_ltohex(long l)
{
	char	*res;
	int i;
	long l1;

	l1 = l;
	i = 1;
	while(l > 16)
	{
		l = l / 16;
		i++;
	}
	res = (char*)malloc(sizeof(char)*(i + 1));
	res[i] = 0;
	l = l1;
	res = res + i;
	while (l > 16)
	{
		if (l % 16 < 10)
			*res = '0' + l % 16;
		else if (l % 16 == 10)
			*res = 'a';
		else if (l % 16 == 11)
			*res = 'b';
		else if (l % 16 == 12)
			*res = 'c';
		else if (l % 16 == 13)
			*res = 'd';
		else if (l % 16 == 14)
			*res = 'e';
		else if (l % 16 == 15)
			*res = 'f';
		l = l / 16;
//		printf("%s",res);
		res--;
	}
		if (l % 16 < 10)
			*res = '0' + l % 16;
		else if (l % 16 == 10)
			*res = 'a';
		else if (l % 16 == 11)
			*res = 'b';
		else if (l % 16 == 12)
			*res = 'c';
		else if (l % 16 == 13)
			*res = 'd';
		else if (l % 16 == 14)
			*res = 'e';
		else if (l % 16 == 15)
			*res = 'f';
	return (res);
}
