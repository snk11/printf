/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elsif2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 14:21:18 by syusof            #+#    #+#             */
/*   Updated: 2016/05/04 13:03:13 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_elsif2(char ***str, t_numb *e, va_list ap)
{
	int	cnt;

	cnt = 0;
	if (e->indelsif == 0)
		cnt = ft_case8(&str, e, ap);
	if (e->indelsif == 0)
		cnt = ft_case9(&str, e, ap);
	if (e->indelsif == 0)
		cnt = ft_case10(&str, e, ap);
	if (e->indelsif == 0)
		cnt = ft_case11(&str, e, ap);
	if (e->indelsif == 0)
		cnt = ft_case12(&str, e, ap);
	if (e->indelsif == 0)
		cnt = ft_case13(&str, e, ap);
	if (e->indelsif == 0)
		cnt = ft_case14(&str, e, ap);
	return (cnt);
}
