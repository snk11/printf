/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:55:06 by syusof            #+#    #+#             */
/*   Updated: 2016/01/04 13:15:47 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putwstr(wchar_t *s)
{
//	int		i;

	wchar_t c1;
	int		n;
	char	*str;
	char	*bigi;
	int c2;
	int c3;
	
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
	c1 = *s;
	c2 = (int)c1;
	c3 = c2;
	n = 0;
	while(c2 > 0)
	{
		c2 = c2 / 2;
		n++;
	}
	n++;
	str = (char*)malloc(sizeof(char)* n + 1);
	bigi = str;
	c2 = c3;
	while(c2 > 0)
	{
		c2 = c2 / 2;
		*str = '0' + c2 % 2;
		str++;
	}
	*str = 0;
	printf("%s",bigi);
//	printf("%d\n",L'米');
//	printf("%d\n",'a');

//	if (s <= 0x7F)
//		printf("UU");
	return 0;
}
