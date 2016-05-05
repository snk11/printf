/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr2_p3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 15:17:48 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 15:18:50 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwstr1f(t_elem *e)
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

void	ft_putwstr1g(t_elem *e)
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

void	ft_putwstr1h(t_elem *e)
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

void	ft_putwstr1i(t_elem *e)
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

void	ft_putwstr1j(t_elem *e)
{
	if ((e->n2 + 1) / 8 <= e->pr1)
	{
		while (e->i < (e->n2 + 1) / 8)
		{
			write(1, &(e->r[e->i]), 1);
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
