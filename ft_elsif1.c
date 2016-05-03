/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elsif1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 14:07:26 by syusof            #+#    #+#             */
/*   Updated: 2016/04/18 11:43:09 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		ft_elsif1(char ***str,t_numb *e,va_list ap)
{
	int	cnt;

	cnt = 0;
	if (e->indelsif == 0)
		cnt = ft_case1(&str,e,ap);
	if (e->indelsif == 0)
		cnt = ft_case2(&str,e,ap);
	if (e->indelsif == 0)
		cnt = ft_case3(&str,e,ap);
	if (e->indelsif == 0)
		cnt = ft_case4(&str,e,ap);
	if (e->indelsif == 0)
		cnt = ft_case5(&str,e,ap);
	if (e->indelsif == 0)
		cnt = ft_case6(&str,e,ap);
	if (e->indelsif == 0)
		cnt = ft_case7(&str,e,ap);
	return (cnt);
}
