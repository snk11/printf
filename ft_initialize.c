/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 22:32:07 by syusof            #+#    #+#             */
/*   Updated: 2016/03/21 21:17:00 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "ft_printf.h"

void	ft_initialize(t_numb *e)
{
	e->w = 0;
	e->pr = 0;
	e->indzero = 0;
	e->indpr = 0;
	e->indplus = 0;
	e->indspace = 0;
	e->indminus = 0;
	e->indletter = 1;
	e->indsharp = 0;
	e->ind1 = 0;
	e->ind2 = 0;
	e->ret1 = 0;
	e->prbegi = 0;
	e->begi = 0;
	e->cnt1 = 0;
}
