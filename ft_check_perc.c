/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_perc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 03:43:40 by syusof            #+#    #+#             */
/*   Updated: 2016/01/12 12:55:34 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

char	*ft_check_perc0(char *str)
{
	int		cnt;
//	char	*bigi;

	cnt = 0;
//	bigi = str;
	while((*str != 0) && (*str == '%' || *str == ' '))
	{
//		printf("*str =%c\n",*str);
//		printf("*str =%c\n",str[1]);
		if (*str == '%')
			cnt++;
		if ((cnt % 2 == 1) && (str[1] == ' '))
		{
//			printf("IN\n");
			return str;
		}
		str++;
	}
//	str = bigi;
//	return cnt;
	return NULL;
}




char	*ft_check_perc(char *str)
{
	int		cnt;
//	char	*bigi;

	cnt = 0;
	str++;
//	bigi = str;
	while((*str != 0) && (*str == '%' || *str == ' '))
	{
//		printf("*str =%c\n",*str);
//		printf("*str =%c\n",str[1]);
		if (*str == '%')
			cnt++;
		if ((cnt % 2 == 1) && (str[1] == ' '))
		{
//			printf("IN\n");
			return str;
		}
		str++;
	}
//	str = bigi;
//	return cnt;
	return NULL;
}
