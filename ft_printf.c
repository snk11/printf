/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 01:53:43 by syusof            #+#    #+#             */
/*   Updated: 2016/04/18 11:40:09 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

# include <stdio.h>

int	ft_printf(char *str, ...)
{
	va_list		ap;
	char		*p;
	t_numb	*e;
	int	cnt;

	e = (t_numb*)malloc(sizeof(t_numb));
	p = NULL;
	cnt = 0;
	ft_initialize(e);
	e->indll = 0;
	e->indelsif = 0;
	va_start(ap, str);
	p = ft_check_perc0(str);
	if (p == NULL)
	{
		e->ind1++;
	}

	if (e->ind1 % 2 == 0)
	{
		while (*str != 0)
		{
			cnt = cnt + ft_p1(&str,e,ap);
			if (*str != 0)
			{
				if (e->indll == 1)
				{
					str++;
					str++;
					e->indll = 0;
				}
				else
					str++;
			}
		}
	}


	else if (e->ind1 % 2 == 1)
	{
		e->ind6 = 0;
		e->cnt1 = 0;
		e->indlast = 0;
		e->ind2 = 0;

		cnt = cnt + ft_altprime(str,e);
	}

	va_end(ap);
	free(e);
	e = NULL;
	return (cnt);
}
