/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 00:41:43 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 15:16:29 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putwchar(wchar_t c)
{
	t_elem	*e;
	int		ret;

	e = (t_elem*)malloc(sizeof(t_elem));
	e->ret = 0;
	e->c2 = (int)c;
	if (e->c2 <= 127)
	{
		ft_putchar(e->c2);
		e->ret++;
		ret = e->ret;
	}
	else
		ret = (ft_putwchar1(e));
	free(e);
	e = NULL;
	return (ret);
}

int		ft_putwchar1(t_elem *e)
{
	e->c3 = e->c2;
	e->n = 0;
	e->ret1 = 0;
	while (e->c2 > 0)
		ft_putwchar1a(e);
	if (e->n <= 7)
		ft_putwchar1b(e);
	else if (e->n > 7 && e->n <= 11)
		ft_putwchar1c(e);
	else if (e->n > 11 && e->n <= 16)
		ft_putwchar1d(e);
	else
		ft_putwchar1e(e);
	ft_putwchar1f(e);
	ft_putwchar1g(e);
	ft_putwchar1h(e);
	ft_putwchar1i(e);
	ft_putwchar1j(e);
	return (e->ret1);
}

void	ft_putwchar1a(t_elem *e)
{
	e->c2 = e->c2 / 2;
	e->n++;
}

void	ft_putwchar1b(t_elem *e)
{
	e->str2 = (char*)malloc(sizeof(char) * 8 + 1);
	e->str2[7] = '0';
	e->str2[8] = 0;
	e->n2 = 7;
}

void	ft_putwchar1c(t_elem *e)
{
	e->str2 = (char*)malloc(sizeof(char) * 16 + 1);
	e->str2[15] = '1';
	e->str2[14] = '1';
	e->str2[13] = '0';
	e->str2[12] = 0;
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
	e->str2[16] = 0;
	e->n2 = 15;
}
