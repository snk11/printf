/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwstr_p3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:57:57 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 14:58:25 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_countwstr1g(t_elem *e)
{
	while (e->i < (e->n2 + 1))
	{
		if (*(e->str2) == 0 && *(e->str))
		{
			*(e->str2) = *(e->str);
			e->str2++;
			e->str++;
		}
		else if (*(e->str2) == 0 && *(e->str) == 0)
		{
			*(e->str2) = '0';
			e->str2++;
		}
		else if (*(e->str2) == '1' || *(e->str2) == '0')
		{
			e->str2++;
		}
		e->i++;
	}
	e->str = e->begi;
	e->str2 = e->begi2;
	e->i = 0;
}

void	ft_countwstr1h(t_elem *e)
{
	while (e->i <= e->n2)
	{
		if (*(e->str2) == 0)
			*(e->str2) = '0';
		e->str2++;
		e->i++;
	}
	e->i = 0;
	e->str2--;
	e->r = (int*)malloc(sizeof(int) * (e->n2 + 1) / 8 + 1);
	e->i = 0;
	while (e->i <= (e->n2 + 1) / 8)
	{
		e->r[e->i] = 0;
		e->i++;
	}
	e->i = 0;
}

void	ft_countwstr1i(t_elem *e)
{
	while (e->i < (e->n2 + 1) / 8)
	{
		e->j = 7;
		while (e->j >= 0)
		{
			e->r[e->i] = e->r[e->i] + (*(e->str2) - '0') * ft_pow(2, e->j);
			e->j--;
			e->str2--;
		}
		e->i++;
	}
	e->str2 = e->begi2;
	e->str = e->begi;
	e->i = 0;
}

void	ft_countwstr1j(t_elem *e)
{
	if ((e->n2 + 1) / 8 <= e->pr1)
	{
		while (e->i < (e->n2 + 1) / 8)
		{
			e->i++;
		}
		e->pr1 = e->pr1 - (e->n2 + 1) / 8;
	}
	e->ret = e->prbegi - e->pr1;
	free(e->str2);
	e->str2 = NULL;
	free(e->str);
	e->str = NULL;
	free(e->r);
	e->r = NULL;
}
