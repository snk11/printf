/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 12:32:13 by syusof            #+#    #+#             */
/*   Updated: 2016/04/18 12:34:54 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

void	ft_p3(char *str,t_numb *e)
{
	char		*p;
	
	p = NULL;
	ft_initialize(e);
	e->indll = 0;
	e->indelsif = 0;
	p = ft_check_perc0(str);
	if (p == NULL)
		e->ind1++;
}