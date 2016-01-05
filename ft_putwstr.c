/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:55:06 by syusof            #+#    #+#             */
/*   Updated: 2016/01/05 03:10:57 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putwstr(wchar_t *s)
{
//	int		i;

	wchar_t c1;
	int		n;
	int		n2;
	char	*str;
	char	*str2;
	char	*bigi;
	char	*bigi2;
	int c2;
	int c3;
	int ret;
	
//	int i1 = 206;
//	int i2 = 177;
//	i = 0;
//	while (s[i])
	{
//		ft_putchar(s[i]);
//		write(1,&i1,1);
//		write(1,&i2,1);
//		i++;
	}
	ret = 0;
	while (*s)
	{
		c1 = *s;
		c2 = (int)c1;
		c3 = c2;
		n = 0;
		while(c2 > 0)
		{
			c2 = c2 / 2;
			n++;
		}
		if (n <=7)
		{
			str2 = (char*)malloc(sizeof(char)* 8 + 1);
			str2[7] = '0';
			str2[8] = 0;
			n2 = 7;
		}
			else if (n <= 11)
		{
			str2 = (char*)malloc(sizeof(char)* 16 + 1);
			str2[15] = '1';
			str2[14] = '1';
			str2[13] = '0';
			str2[7] = '1';
			str2[6] = '0';
			str2[16] = 0;
			n2 = 15;
		}
		else if (n > 11 && n <= 16)
		{
			str2 = (char*)malloc(sizeof(char)* 24 + 1);
			str2[23] = '1';
			str2[22] = '1';
			str2[21] = '1';
			str2[20] = '0';
			str2[15] = '1';
			str2[14] = '0';
			str2[7] = '1';
			str2[6] = '0';
			str2[24] = 0;
			n2 = 23;
		}
		else
		{
			str2 = (char*)malloc(sizeof(char)* 32 + 1);
			str2[31] = '1';
			str2[30] = '1';
			str2[29] = '1';
			str2[28] = '1';
			str2[27] = '0';
			str2[23] = '1';
			str2[22] = '0';
			str2[15] = '1';
			str2[14] = '0';
			str2[7] = '1';
			str2[6] = '0';
			str2[32] = 0;
			n2 = 31;
		}
		str = (char*)malloc(sizeof(char)* n + 1);
		bigi = str;
		c2 = c3;
		while(c2 > 0)
		{
			*str = '0' + c2 % 2;
			c2 = c2 / 2;
			str++;
		}
		*str = 0;
		bigi2 = str2;
		str = bigi;
		while (*str != 0)
		{
			if (*str2 == '1' || *str2 == '0')
				str2++;
			else
			{
				*str2 = *str;
				str2++;
				str++;
			}
		}
		str2 = bigi2;
		int i = 0;
		while (i <= n2)
		{
			if (*str2 == 0)
				*str2 = '0';
			str2++;
			i++;
		}
		i = 0;
		int j;
		int r;
		str2--;
		while (i < (n2 + 1) / 8)
		{
			j = 7;
			r = 0;
			while ( j >= 0 )
			{
				r = r + (*str2 - '0') * pow(2,j);
				j--;
				str2--;
			}
			i++;
			write(1,&r,1);
		}
	//	printf("%s",bigi2);
	//	printf("%d\n",L'米');
	//	printf("%d\n",'a');

	//	if (s <= 0x7F)
	//		printf("UU");
	s++;
	ret = ret + (n2 + 1) / 8;
	}
	return ret;
}
