/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkwidth.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:55:14 by syusof            #+#    #+#             */
/*   Updated: 2016/01/28 12:51:50 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		ft_checkwidth(char *str)
{
	int	i;
	char *begi;
	char *s;
	char *s2;

	s = (char*)malloc(sizeof(char)*(ft_strlen(str)) + 1);
	i = 0;
	while (i < ft_strlen(str))
	{
		s[i] = str[i];
		i++;
	}
	s[i] = 0;
	i = 0;
	begi = s;
	if ((s[0] >= '0' && s[0] <= '9') || s[0] == ' ' || s[0] == '+' || s[0] == '-')
	{
		while((s[0] >= '0' && s[0] <= '9') || s[0] == ' ' || s[0] == '+' || s[0] == '-')
		{
			s++;
			i++;
		}
		s = begi;
		s2 = (char*)malloc(sizeof(char) * i + 1);
		s2[i] = 0;
		i--;
		while (i >= 0)
		{
			s2[i] = s[i];
			i--;
		}
		free(begi);
		return (ft_atoi(s2));
	}
	if (ft_checkprec(s) == 0)
	{
		while(*s)
		{
			s++;
			i++;
		}
		s--;
		while ((*s == ' ' || *s == '-' || (*s >= '0' && *s <= '9')) && i > 0)
		{
			s--;
			i--;
		}
		s++;
//		if (*s == ' ' || (*s >= '0' && *s <= '9'))
			return ft_atoi(s);
	}
	else
	{
		
	}
	return 0;
}

