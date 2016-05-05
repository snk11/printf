/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_p3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 15:15:24 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 15:15:55 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwchar1g(t_elem *e)
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

void	ft_putwchar1h(t_elem *e)
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

void	ft_putwchar1i(t_elem *e)
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

void	ft_putwchar1j(t_elem *e)
{
	while (e->i < (e->n2 + 1) / 8)
	{
		write(1, &(e->r[e->i]), 1);
		e->i++;
	}
	e->ret1 = e->ret1 + (e->n2 + 1) / 8;
	free(e->str2);
	e->str2 = NULL;
	e->begi2 = NULL;
	free(e->str);
	e->str = NULL;
	e->begi = NULL;
	free(e->r);
	e->r = NULL;
}
