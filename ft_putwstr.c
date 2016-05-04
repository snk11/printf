/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:55:06 by syusof            #+#    #+#             */
/*   Updated: 2016/05/04 14:23:05 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putwstr(wchar_t *s)
{
	t_elem	*e;
	int		c1;
	int		r1;

	e = (t_elem*)malloc(sizeof(t_elem));
	e->ret = 0;
	while (*s)
	{
		c1 = *s;
		e->c2 = (int)c1;
		if (e->c2 <= 127)
		{
			write(1, &(e->c2), 1);
			e->ret++;
		}
		else
			e->ret = e->ret + (ft_putwchar1(e));
		s++;
	}
	r1 = e->ret;
	free(e);
	e = NULL;
	return (r1);
}
