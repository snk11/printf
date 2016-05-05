/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltohex_p2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 15:00:52 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 15:03:39 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ltohex15(char **res, unsigned long long *l)
{
	if (*l % 16 < 10)
		**res = '0' + *l % 16;
	else if (*l % 16 == 10)
		**res = 'A';
	else if (*l % 16 == 11)
		**res = 'B';
	else if (*l % 16 == 12)
		**res = 'C';
	else if (*l % 16 == 13)
		**res = 'D';
	else if (*l % 16 == 14)
		**res = 'E';
	else if (*l % 16 == 15)
		**res = 'F';
	*l = *l / 16;
	(*res)--;
}

void	ft_ltohex16(char **res, unsigned short *l)
{
	if (*l % 16 < 10)
		**res = '0' + *l % 16;
	else if (*l % 16 == 10)
		**res = 'a';
	else if (*l % 16 == 11)
		**res = 'b';
	else if (*l % 16 == 12)
		**res = 'c';
	else if (*l % 16 == 13)
		**res = 'd';
	else if (*l % 16 == 14)
		**res = 'e';
	else if (*l % 16 == 15)
		**res = 'f';
	*l = *l / 16;
	(*res)--;
}

void	ft_ltohex17(char **res, unsigned short *l)
{
	if (*l % 16 < 10)
		**res = '0' + *l % 16;
	else if (*l % 16 == 10)
		**res = 'A';
	else if (*l % 16 == 11)
		**res = 'B';
	else if (*l % 16 == 12)
		**res = 'C';
	else if (*l % 16 == 13)
		**res = 'D';
	else if (*l % 16 == 14)
		**res = 'E';
	else if (*l % 16 == 15)
		**res = 'F';
	*l = *l / 16;
	(*res)--;
}

void	ft_ltohex18(char **res, unsigned char *l)
{
	if (*l % 16 < 10)
		**res = '0' + *l % 16;
	else if (*l % 16 == 10)
		**res = 'a';
	else if (*l % 16 == 11)
		**res = 'b';
	else if (*l % 16 == 12)
		**res = 'c';
	else if (*l % 16 == 13)
		**res = 'd';
	else if (*l % 16 == 14)
		**res = 'e';
	else if (*l % 16 == 15)
		**res = 'f';
	*l = *l / 16;
	(*res)--;
}

void	ft_ltohex19(char **res, unsigned char *l)
{
	if (*l % 16 < 10)
		**res = '0' + *l % 16;
	else if (*l % 16 == 10)
		**res = 'A';
	else if (*l % 16 == 11)
		**res = 'B';
	else if (*l % 16 == 12)
		**res = 'C';
	else if (*l % 16 == 13)
		**res = 'D';
	else if (*l % 16 == 14)
		**res = 'E';
	else if (*l % 16 == 15)
		**res = 'F';
	*l = *l / 16;
	(*res)--;
}
