/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:22:50 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 15:19:20 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putwstr2(int pr, wchar_t *s)
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
			write(1, &(e->c2), 1);
			e->ret++;
			e->pr1--;
		}
		else
			ft_putwstr1(e);
		s++;
	}
	r1 = e->ret;
	ft_putwstr2a(e);
	return (r1);
}

void	ft_putwstr2a(t_elem *e)
{
	free(e);
	e = NULL;
}

void	ft_putwstr1(t_elem *e)
{
	e->c3 = e->c2;
	e->n = 0;
	while (e->c2 > 0)
		ft_putwstr1a(e);
	if (e->n <= 7)
		ft_putwstr1b(e);
	else if (e->n > 7 && e->n <= 11)
		ft_putwstr1c(e);
	else if (e->n > 11 && e->n <= 16)
		ft_putwstr1d(e);
	else
		ft_putwstr1e(e);
	ft_putwstr1f(e);
	ft_putwstr1g(e);
	ft_putwstr1h(e);
	ft_putwstr1i(e);
	ft_putwstr1j(e);
}

void	ft_putwstr1a(t_elem *e)
{
	e->c2 = e->c2 / 2;
	e->n++;
}

void	ft_putwstr1b(t_elem *e)
{
	e->str2 = (char*)malloc(sizeof(char) * 8 + 1);
	e->str2[7] = '0';
	e->str2[8] = 0;
	e->n2 = 7;
}
