/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_perc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 03:43:40 by syusof            #+#    #+#             */
/*   Updated: 2016/04/26 15:41:56 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_perc0(char *str)
{
	char	*begi;
	int		ind;

	ind = 0;
	while (*str != 0)
	{
		if (*str == '%')
		{
			ind = 1;
			begi = str;
			str++;
			while (*str != 0)
			{
				if (*str == '%')
					begi = str;
				if (ft_checkletter(*str))
					return (begi);
				str++;
			}
		}
		if (ind == 0)
			str++;
	}
	return (0);
}
