/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case18.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 13:41:57 by syusof            #+#    #+#             */
/*   Updated: 2016/05/04 15:35:57 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_case18(char ****str, t_numb *e)
{
	int		cnt;

	cnt = 0;
	if ((****str >= '0' && ****str <= '9') || ****str == '-' || ****str == '+'
			|| ****str == '.' || ****str == ' ' || ****str == '#')
	{
		cnt = 0;
		if (e->indperc == 0)
		{
			e->begi = NULL;
			e->begi = ft_getfield(***str);
			if (e->w == 0 && e->begi)
				e->w = ft_checkwidth(e, e->begi);
			if (e->pr == 0 && e->begi)
				e->pr = ft_checkprec(e, e->begi);
			free(e->begi);
			e->begi = NULL;
		}
		e->indperc = 1;
		e->indelsif = 1;
	}
	return (cnt);
}
