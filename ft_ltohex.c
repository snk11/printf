/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 02:47:12 by syusof            #+#    #+#             */
/*   Updated: 2016/01/26 17:17:22 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

char	*ft_ltohex( long l)
{
	char	*res;
	char	*bigi;
	int i;
	 long l1;
	int tab[100];

	bigi = NULL;
	l1 = l;
	i = 1;
	while(l > 16)
	{
		l = l / 16;
		i++;
	}
	res = (char*)malloc(sizeof(char)*(i + 1));
	res[i] = 0;
	bigi  = res;
	l = l1;
	res = res + i - 1;
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
//		printf("%s\n",res);
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
		
//		printf("%s\n",res);
/*
		int j = 0;
		tab[j] = *res;
		while (j < i-1)
		{
			res--;
			j++;
			tab[j] = *res;
		}
		j = 0;
		*res = tab[j];
		while (j < i-1)
		{
			res++;
			j++;
			*res = tab[j];
		}
		j = 0;*/
//		printf("der = %s\n",res);
	return (bigi);
}


char	*ft_ltohex2(unsigned long l)
{
	char	*res;
	char	*bigi;
	int i;
	unsigned long l1;

	bigi = NULL;
	l1 = l;
	i = 1;
	while(l > 16)
	{
		l = l / 16;
		i++;
	}
	res = (char*)malloc(sizeof(char)*(i + 1));
	res[i] = 0;
	bigi  = res;
	l = l1;
	res = res + i - 1;
	while (l > 16)
	{
		if (l % 16 < 10)
			*res = '0' + l % 16;
		else if (l % 16 == 10)
			*res = 'A';
		else if (l % 16 == 11)
			*res = 'B';
		else if (l % 16 == 12)
			*res = 'C';
		else if (l % 16 == 13)
			*res = 'D';
		else if (l % 16 == 14)
			*res = 'E';
		else if (l % 16 == 15)
			*res = 'F';
		l = l / 16;
		res--;
	}
		if (l % 16 < 10)
			*res = '0' + l % 16;
		else if (l % 16 == 10)
			*res = 'A';
		else if (l % 16 == 11)
			*res = 'B';
		else if (l % 16 == 12)
			*res = 'C';
		else if (l % 16 == 13)
			*res = 'D';
		else if (l % 16 == 14)
			*res = 'E';
		else if (l % 16 == 15)
			*res = 'F';
	return (bigi);
}


char	*ft_ltohex3( unsigned long l)
{
	char	*res;
	char	*bigi;
	int i;
	unsigned long l1;

	bigi = NULL;
	l1 = l;
	i = 1;
	while(l > 16)
	{
		l = l / 16;
		i++;
	}
	res = (char*)malloc(sizeof(char)*(i + 1));
	res[i] = 0;
	bigi  = res;
	l = l1;
	res = res + i - 1;
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
	return (bigi);
}


char	*ft_ltohex4(unsigned long long l)
{
	char	*res;
	char	*bigi;
	int i;
	unsigned long long l1;

	bigi = NULL;
	l1 = l;
	i = 1;
	while(l > 16)
	{
		l = l / 16;
		i++;
	}
	res = (char*)malloc(sizeof(char)*(i + 1));
	res[i] = 0;
	bigi  = res;
	l = l1;
	res = res + i - 1;
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
	return (bigi);
}

char	*ft_ltohex5(unsigned long long l)
{
	char	*res;
	char	*bigi;
	int i;
	unsigned long long l1;

	bigi = NULL;
	l1 = l;
	i = 1;
	while(l > 16)
	{
		l = l / 16;
		i++;
	}
	res = (char*)malloc(sizeof(char)*(i + 1));
	res[i] = 0;
	bigi  = res;
	l = l1;
	res = res + i - 1;
	while (l > 16)
	{
		if (l % 16 < 10)
			*res = '0' + l % 16;
		else if (l % 16 == 10)
			*res = 'A';
		else if (l % 16 == 11)
			*res = 'B';
		else if (l % 16 == 12)
			*res = 'C';
		else if (l % 16 == 13)
			*res = 'D';
		else if (l % 16 == 14)
			*res = 'E';
		else if (l % 16 == 15)
			*res = 'F';
		l = l / 16;
		res--;
	}
		if (l % 16 < 10)
			*res = '0' + l % 16;
		else if (l % 16 == 10)
			*res = 'A';
		else if (l % 16 == 11)
			*res = 'B';
		else if (l % 16 == 12)
			*res = 'C';
		else if (l % 16 == 13)
			*res = 'D';
		else if (l % 16 == 14)
			*res = 'E';
		else if (l % 16 == 15)
			*res = 'F';
	return (bigi);
}

char	*ft_ltohex6(unsigned short l)
{
	char	*res;
	char	*bigi;
	int i;
	unsigned short l1;

	bigi = NULL;
	l1 = l;
	i = 1;
	while(l > 16)
	{
		l = l / 16;
		i++;
	}
	res = (char*)malloc(sizeof(char)*(i + 1));
	res[i] = 0;
	bigi  = res;
	l = l1;
	res = res + i - 1;
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
	return (bigi);
}

char	*ft_ltohex7(unsigned short l)
{
	char	*res;
	char	*bigi;
	int i;
	unsigned short l1;

	bigi = NULL;
	l1 = l;
	i = 1;
	while(l > 16)
	{
		l = l / 16;
		i++;
	}
	res = (char*)malloc(sizeof(char)*(i + 1));
	res[i] = 0;
	bigi  = res;
	l = l1;
	res = res + i - 1;
	while (l > 16)
	{
		if (l % 16 < 10)
			*res = '0' + l % 16;
		else if (l % 16 == 10)
			*res = 'A';
		else if (l % 16 == 11)
			*res = 'B';
		else if (l % 16 == 12)
			*res = 'C';
		else if (l % 16 == 13)
			*res = 'D';
		else if (l % 16 == 14)
			*res = 'E';
		else if (l % 16 == 15)
			*res = 'F';
		l = l / 16;
		res--;
	}
		if (l % 16 < 10)
			*res = '0' + l % 16;
		else if (l % 16 == 10)
			*res = 'A';
		else if (l % 16 == 11)
			*res = 'B';
		else if (l % 16 == 12)
			*res = 'C';
		else if (l % 16 == 13)
			*res = 'D';
		else if (l % 16 == 14)
			*res = 'E';
		else if (l % 16 == 15)
			*res = 'F';
	return (bigi);
}
