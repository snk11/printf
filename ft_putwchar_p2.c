/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_p2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 15:14:56 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 15:16:16 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwchar1d(t_elem *e)
{
	e->str2 = (char*)malloc(sizeof(char) * 24 + 1);
	ft_putwchar1d1(e);
	e->str2[9] = 0;
	e->str2[8] = 0;
	e->str2[7] = '1';
	e->str2[6] = '0';
	e->str2[5] = 0;
	e->str2[4] = 0;
	e->str2[3] = 0;
	e->str2[2] = 0;
	e->str2[1] = 0;
	e->str2[0] = 0;
	e->str2[24] = 0;
	e->n2 = 23;
}

void	ft_putwchar1d1(t_elem *e)
{
	e->str2[23] = '1';
	e->str2[22] = '1';
	e->str2[21] = '1';
	e->str2[20] = '0';
	e->str2[19] = 0;
	e->str2[18] = 0;
	e->str2[17] = 0;
	e->str2[16] = 0;
	e->str2[15] = '1';
	e->str2[14] = '0';
	e->str2[13] = 0;
	e->str2[12] = 0;
	e->str2[11] = 0;
	e->str2[10] = 0;
}

void	ft_putwchar1e(t_elem *e)
{
	e->str2 = (char*)malloc(sizeof(char) * 32 + 1);
	ft_putwchar1e1(e);
	e->str2[11] = 0;
	e->str2[10] = 0;
	e->str2[9] = 0;
	e->str2[8] = 0;
	e->str2[7] = '1';
	e->str2[6] = '0';
	e->str2[5] = 0;
	e->str2[4] = 0;
	e->str2[3] = 0;
	e->str2[2] = 0;
	e->str2[1] = 0;
	e->str2[0] = 0;
	e->str2[32] = 0;
	e->n2 = 31;
}

void	ft_putwchar1e1(t_elem *e)
{
	e->str2[31] = '1';
	e->str2[30] = '1';
	e->str2[29] = '1';
	e->str2[28] = '1';
	e->str2[27] = '0';
	e->str2[26] = 0;
	e->str2[25] = 0;
	e->str2[24] = 0;
	e->str2[23] = '1';
	e->str2[22] = '0';
	e->str2[21] = 0;
	e->str2[20] = 0;
	e->str2[19] = 0;
	e->str2[18] = 0;
	e->str2[17] = 0;
	e->str2[16] = 0;
	e->str2[15] = '1';
	e->str2[14] = '0';
	e->str2[13] = 0;
	e->str2[12] = 0;
}

void	ft_putwchar1f(t_elem *e)
{
	e->str = (char*)malloc(sizeof(char) * e->n + 1);
	e->begi = e->str;
	e->c2 = e->c3;
	e->begi2 = e->str2;
	while (e->c2 > 0)
	{
		*(e->str) = '0' + e->c2 % 2;
		e->c2 = e->c2 / 2;
		e->str++;
	}
	*(e->str) = 0;
	e->str = e->begi;
	e->i = 0;
	e->str2 = e->begi2;
}
