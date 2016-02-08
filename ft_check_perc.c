/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_perc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 03:43:40 by syusof            #+#    #+#             */
/*   Updated: 2016/02/08 12:58:09 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

//char	*ft_check_perc(int first,char *str)
char	*ft_check_perc8(char *str)
{	
	char	*begi0;
	char	*begi;
	int		cnt;

	cnt = 0;
	begi0 = 0;
	while (*str != 0)
	{
		if (*str == '%')
		{
			cnt++;
			begi = str;
			if (cnt == 1)
				begi0 = str;
			while (*str != 0)
			{
				if(ft_checkletter(str))
					return (begi);
				else if (ft_checkletter(str) == 0 && ((*str >= 'a' && *str <= 'z')||(*str >= 'A' && *str <= 'Z')))
					return (0);
				str++;
			}
			str = begi;
		}
		str++;
	}
//	if (begi0 != 0)
//		return (begi0);
	return (0);
}

char	*ft_check_perc0(char *str)
{	
	char	*begi0;
	char	*begi;
	int		cnt;

//	cnt = 0;
//	begi0 = 0;
	while (*str != 0)
	{
		if (*str == '%')
		{
//			cnt++;
			begi = str;
			str++;
//			if (cnt == 1)
//				begi0 = str;
			while (*str != 0)
			{
				if (*str == '%')
					begi = str;
				if(ft_checkletter(str))
					return (begi);
				str++;
			}
//			str = begi;
		}
		str++;
	}
//	if (begi0 != 0)
//		return (begi0);
	return (0);
}
