/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_perc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 03:43:40 by syusof            #+#    #+#             */
/*   Updated: 2016/01/06 05:16:05 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		ft_check_perc(char *str)
{
	int		cnt;
	char	*bigi;

	cnt = 1;
	bigi = str;

	while(*str == '%' || *str == ' ')
	{
		if (*str == '%')
			cnt++;
		str++;
	}
	str = bigi;
	return cnt;
}
