/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 02:47:12 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 15:03:55 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ltohex(long l)
{
	char	*res;
	char	*bigi;
	int		i;
	long	l1;

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
		ft_ltohex11(&res, &l);
	ft_ltohex11(&res, &l);
	return (bigi);
}

void	ft_ltohex11(char **res, long *l)
{
	if (*l % 16 < 10)
		**res = '0' + *l % 16;
	else if (*l % 16 == 10)
		**res = 'a';
	else if (*l % 16 == 11)
		**res = 'b';
	else if (*l % 16 == 12)
		**res = 'c';
	else if (*l % 16 == 13)
		**res = 'd';
	else if (*l % 16 == 14)
		**res = 'e';
	else if (*l % 16 == 15)
		**res = 'f';
	*l = *l / 16;
	(*res)--;
}

void	ft_ltohex12(char **res, unsigned long *l)
{
	if (*l % 16 < 10)
		**res = '0' + *l % 16;
	else if (*l % 16 == 10)
		**res = 'A';
	else if (*l % 16 == 11)
		**res = 'B';
	else if (*l % 16 == 12)
		**res = 'C';
	else if (*l % 16 == 13)
		**res = 'D';
	else if (*l % 16 == 14)
		**res = 'E';
	else if (*l % 16 == 15)
		**res = 'F';
	*l = *l / 16;
	(*res)--;
}

void	ft_ltohex13(char **res, unsigned long *l)
{
	if (*l % 16 < 10)
		**res = '0' + *l % 16;
	else if (*l % 16 == 10)
		**res = 'a';
	else if (*l % 16 == 11)
		**res = 'b';
	else if (*l % 16 == 12)
		**res = 'c';
	else if (*l % 16 == 13)
		**res = 'd';
	else if (*l % 16 == 14)
		**res = 'e';
	else if (*l % 16 == 15)
		**res = 'f';
	*l = *l / 16;
	(*res)--;
}

void	ft_ltohex14(char **res, unsigned long long *l)
{
	if (*l % 16 < 10)
		**res = '0' + *l % 16;
	else if (*l % 16 == 10)
		**res = 'a';
	else if (*l % 16 == 11)
		**res = 'b';
	else if (*l % 16 == 12)
		**res = 'c';
	else if (*l % 16 == 13)
		**res = 'd';
	else if (*l % 16 == 14)
		**res = 'e';
	else if (*l % 16 == 15)
		**res = 'f';
	*l = *l / 16;
	(*res)--;
}
