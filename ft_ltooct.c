/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltooct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:11:15 by syusof            #+#    #+#             */
/*   Updated: 2016/01/26 17:58:40 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

char	*ft_ltooct(long l)
{
	char	*res;
	char	*bigi;
	int i;
	long l1;

	bigi = NULL;
	l1 = l;
	i = 1;
	while(l > 8)
	{
		l = l / 8;
		i++;
	}
	res = (char*)malloc(sizeof(char)*(i + 1));
	res[i] = 0;
	bigi  = res;
	l = l1;
	res = res + i - 1;
	while (l > 8)
	{
			*res = '0' + l % 8;
		l = l / 8;
		res--;
	}
			*res = '0' + l % 8;
	return (bigi);
}


char	*ft_ltooct2(unsigned long l)
{
	char	*res;
	char	*bigi;
	int i;
	 unsigned long l1;

	bigi = NULL;
	l1 = l;
	i = 1;
	while(l > 8)
	{
		l = l / 8;
		i++;
	}
	res = (char*)malloc(sizeof(char)*(i + 1));
	res[i] = 0;
	bigi  = res;
	l = l1;
	res = res + i - 1;
	while (l > 8)
	{
			*res = '0' + l % 8;
		l = l / 8;
		res--;
	}
			*res = '0' + l % 8;
	return (bigi);
}

char	*ft_ltooct3(unsigned short l)
{
	char	*res;
	char	*bigi;
	int i;
	 unsigned short l1;

	bigi = NULL;
	l1 = l;
	i = 1;
	while(l > 8)
	{
		l = l / 8;
		i++;
	}
	res = (char*)malloc(sizeof(char)*(i + 1));
	res[i] = 0;
	bigi  = res;
	l = l1;
	res = res + i - 1;
	while (l > 8)
	{
			*res = '0' + l % 8;
		l = l / 8;
		res--;
	}
			*res = '0' + l % 8;
	return (bigi);
}

char	*ft_ltooct4(unsigned long long l)
{
	char	*res;
	char	*bigi;
	int i;
	 unsigned long long l1;

	bigi = NULL;
	l1 = l;
	i = 1;
	while(l > 8)
	{
		l = l / 8;
		i++;
	}
	res = (char*)malloc(sizeof(char)*(i + 1));
	res[i] = 0;
	bigi  = res;
	l = l1;
	res = res + i - 1;
	while (l > 8)
	{
			*res = '0' + l % 8;
		l = l / 8;
		res--;
	}
			*res = '0' + l % 8;
	return (bigi);
}

char	*ft_ltooct5(unsigned short int l)
{
	char	*res;
	char	*bigi;
	int i;
	 unsigned short int l1;

	bigi = NULL;
	l1 = l;
	i = 1;
	while(l > 8)
	{
		l = l / 8;
		i++;
	}
	res = (char*)malloc(sizeof(char)*(i + 1));
	res[i] = 0;
	bigi  = res;
	l = l1;
	res = res + i - 1;
	while (l > 8)
	{
			*res = '0' + l % 8;
		l = l / 8;
		res--;
	}
			*res = '0' + l % 8;
	return (bigi);
}

char	*ft_ltooct6(unsigned char l)
{
	char	*res;
	char	*bigi;
	int i;
	 unsigned char l1;

	bigi = NULL;
	l1 = l;
	i = 1;
	while(l > 8)
	{
		l = l / 8;
		i++;
	}
	res = (char*)malloc(sizeof(char)*(i + 1));
	res[i] = 0;
	bigi  = res;
	l = l1;
	res = res + i - 1;
	while (l > 8)
	{
			*res = '0' + l % 8;
		l = l / 8;
		res--;
	}
			*res = '0' + l % 8;
	return (bigi);
}
