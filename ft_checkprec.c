/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkprec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:19:17 by syusof            #+#    #+#             */
/*   Updated: 2016/01/28 13:23:40 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		ft_checkprec(char *s)
{
	int	i;
	char *begi;
	

	i = 0;
	while(*s)
	{
		s++;
		i++;
	}
	s--;
	while((*s == ' ' || (*s >= '0' && *s <= '9')) && i > 0)
	{
		i--;
		s--;
	}
	begi = &s[1];
	if (*s == '.')
	{
//		while (*s == ' ' || (*s >= '0' && *s <= '9') || *s != 0)
//		{
//			s++;
//		}
//		if (*s == 0)
		while(i > 0 && (*s == '.' || *s == ' ' || (*s >= '0' && *s <= '9')))
		{
			s--;
			i--;
		}
		if (i > 0)
			return (0);
		return ft_atoi(begi);
	}
	return 0;
}
