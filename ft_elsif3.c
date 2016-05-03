/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elsif3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 14:22:33 by syusof            #+#    #+#             */
/*   Updated: 2016/04/18 11:22:29 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



# include "ft_printf.h"

int		ft_elsif3(char ***str,t_numb *e,va_list ap)
{
	int	cnt;

	cnt = 0;
	if (e->indelsif == 0)
		cnt = ft_case15(&str,e,ap);
	if (e->indelsif == 0)
		cnt = ft_case16(&str,e,ap);
	if (e->indelsif == 0)
		cnt = ft_case17(&str,e,ap);
	if (e->indelsif == 0)
		cnt = ft_case18(&str,e,ap);
	return (cnt);
}
