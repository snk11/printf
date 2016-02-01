/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:37:22 by syusof            #+#    #+#             */
/*   Updated: 2016/02/01 14:35:39 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strlen(const char *str)
{
	size_t		i;

	if (str)
	{
		i = 0;
		while (str[i])
			i++;
		return (i);
	}
	return (0);
}

size_t		ft_strlen2(wchar_t *s)
{
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
	int i;
	int j;
	int *r;
	
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
		if (c2 == 32)
		{
//			write(1," ",1);
			ret++;
		}
		else
		{



		c3 = c2;
//		printf("c3 = %d\n",c3);
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
		else if (n > 7 && n <= 11)
		{
			str2 = (char*)malloc(sizeof(char)* 16 + 1);
			str2[15] = '1';
			str2[14] = '1';
			str2[13] = '0';
			str2[12] = 0;
			str2[11] = 0;
			str2[10] = 0;
			str2[9] = 0;
			str2[8] = 0;
			str2[7] = '1';
			str2[6] = '0';
			str2[5] = 0;
			str2[4] = 0;
			str2[3] = 0;
			str2[2] = 0;
			str2[1] = 0;
			str2[0] = 0;
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
			str2[19] = 0;
			str2[18] = 0;
			str2[17] = 0;
			str2[16] = 0;
			str2[15] = '1';
			str2[14] = '0';
			str2[13] = 0;
			str2[12] = 0;
			str2[11] = 0;
			str2[10] = 0;
			str2[9] = 0;
			str2[8] = 0;
			str2[7] = '1';
			str2[6] = '0';
			str2[5] = 0;
			str2[4] = 0;
			str2[3] = 0;
			str2[2] = 0;
			str2[1] = 0;
			str2[0] = 0;
			str2[24] = 0;
			n2 = 23;
//			printf("str2[19]= %c\n",str2[19]);
		}
		else
		{
			str2 = (char*)malloc(sizeof(char)* 32 + 1);
			str2[31] = '1';
			str2[30] = '1';
			str2[29] = '1';
			str2[28] = '1';
			str2[27] = '0';
			str2[26] = 0;
			str2[25] = 0;
			str2[24] = 0;
			str2[23] = '1';
			str2[22] = '0';
			str2[21] = 0;
			str2[20] = 0;
			str2[19] = 0;
			str2[18] = 0;
			str2[17] = 0;
			str2[16] = 0;
			str2[15] = '1';
			str2[14] = '0';
			str2[13] = 0;
			str2[12] = 0;
			str2[11] = 0;
			str2[10] = 0;
			str2[9] = 0;
			str2[8] = 0;
			str2[7] = '1';
			str2[6] = '0';
			str2[5] = 0;
			str2[4] = 0;
			str2[3] = 0;
			str2[2] = 0;
			str2[1] = 0;
			str2[0] = 0;
			str2[32] = 0;
			n2 = 31;
		}
		str = (char*)malloc(sizeof(char)* n + 1);
		bigi = str;
		c2 = c3;
		bigi2 = str2;
		while(c2 > 0)
		{
			*str = '0' + c2 % 2;
			c2 = c2 / 2;
			str++;
		}
		*str = 0;
		str = bigi;
//		printf ("str = %s\n",str);
		
//		printf("str2o len = %d\n",ft_strlen(str2) );
		i = 0;

//		printf("n2 = %d\n",n2);
/*
		while (i < (n2 + 1))
		{
				printf("str2[%d]=%c\n",i,*str2);
				str2++;
			i++;
		}*/
//		i = 0;
		str2 = bigi2;
//		printf("after------\n");
		while (i < (n2 + 1))
		{
//			printf("condition: *str2 = %c et *str =%c\n",*str2,*str);
			if (*str2 == 0 && *str)
			{
				*str2 = *str;

//			printf("str2[%d]=%c\n",i,*str2);
				str2++;
				str++;
			}
			else if (*str2 == 0 && *str == 0)
			{
				*str2 = '0';
//			printf("str2[%d]=%c\n",i,*str2);
				str2++;
			}
			else if (*str2 == '1' || *str2 == '0')
			{
//				printf("str2[%d]=%c\n",i,*str2);
				str2++;
			}
			i++;
		}
		str = bigi;
		str2 = bigi2;
//		printf("str2p len = %d\n",ft_strlen(str2) );
//		printf("str2 = %s\n",str2);
		i = 0;
		while (i <= n2)
		{
			if (*str2 == 0)
				*str2 = '0';
			str2++;
			i++;
		}
		i = 0;
		str2--;
		r = (int*)malloc(sizeof(int)*(n2+1)/8 + 1);
		i = 0;
		while (i <= (n2 + 1)/8)
		{
			r[i] = 0;
			i++;
		}
		
//		r[(n2+1)/8] = 0;
		i = 0;
//		printf("str2 len = %d\n",ft_strlen(str2) );
		while (i < (n2 + 1) / 8)
		{
			j = 7;
	//		r = 0;
			while ( j >= 0 )
			{
				r[i] = r[i] + (*str2 - '0') * pow(2,j);
				j--;
				str2--;
			}
			i++;
		}
		str2 = bigi2;
		str = bigi;
//		printf("str2 len = %d\n",ft_strlen(str2) );
//		printf("n2= %d,\n",n2);
		i = 0;
		while(i < (n2 + 1)/8)
		{
//			printf("r = %d\n",r[i]);
//			write(1,&r[i],1);
			i++;
		}
//			printf("str2 = %s\n",bigi2);
		//	printf("%d\n",L'米');
		//	printf("%d\n",'a');

		//	if (s <= 0x7F)
		//		printf("UU");
		ret = ret + (n2 + 1) / 8;
		free(str2);
		str2 = NULL;
		bigi2 = NULL;
		free(str);
		str = NULL;
		bigi = NULL;
		free(r);
		r = NULL;
		}

	s++;

	}
/*
	int h = 230;
	int t = 152;
	int u =175;

			write(1,&h,1);
			write(1,&t,1);
			write(1,&u,1);
			*/
	return ret;
}
