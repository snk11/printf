/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 15:13:21 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 14:59:02 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_countwstr(int pr, wchar_t *s)
{
	t_elem	*e;
	int		c1;
	int		r1;

	e = (t_elem*)malloc(sizeof(t_elem));
	e->prbegi = pr;
	e->ret = 0;
	e->pr1 = pr;
	while (*s)
	{
		c1 = *s;
		e->c2 = (int)c1;
		if (e->c2 <= 127 && e->pr1 > 0)
		{
			e->ret++;
			e->pr1--;
		}
		else
			ft_countwstr1(e);
		s++;
	}
	r1 = e->ret;
	free(e);
	e = NULL;
	return (r1);
}

void	ft_countwstr1(t_elem *e)
{
	e->c3 = e->c2;
	e->n = 0;
	while (e->c2 > 0)
		ft_countwstr1a(e);
	if (e->n <= 7)
		ft_countwstr1b(e);
	else if (e->n > 7 && e->n <= 11)
		ft_countwstr1c(e);
	else if (e->n > 11 && e->n <= 16)
		ft_countwstr1d(e);
	else
		ft_countwstr1e(e);
	ft_countwstr1f(e);
	ft_countwstr1g(e);
	ft_countwstr1h(e);
	ft_countwstr1i(e);
	ft_countwstr1j(e);
}

void	ft_countwstr1a(t_elem *e)
{
	e->c2 = e->c2 / 2;
	e->n++;
}

void	ft_countwstr1b(t_elem *e)
{
	e->str2 = (char*)malloc(sizeof(char) * 8 + 1);
	e->str2[7] = '0';
	e->str2[8] = 0;
	e->n2 = 7;
}

void	ft_countwstr1c(t_elem *e)
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
