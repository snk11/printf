/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_perc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 03:43:40 by syusof            #+#    #+#             */
/*   Updated: 2016/02/02 19:01:44 by syusof           ###   ########.fr       */
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




//char	*ft_check_perc(int first,char *str)
char	*ft_check_perc(char *str)
{	
	char	*begi;

	while (*str != 0)
	{
		if (*str == '%')
		{
			begi = str;
			while (*str != 0)
			{
				if(ft_checkletter(str))
					return (begi);
				str++;
			}
			str = begi;
		}
		str++;
	}
	return (0);
}
