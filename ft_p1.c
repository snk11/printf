/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 11:15:53 by syusof            #+#    #+#             */
/*   Updated: 2016/04/18 12:54:24 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"


int	ft_p1(char **str,t_numb *e,va_list ap)
{
	int cnt;

	cnt = 0;
	if ( **str == '%' || e->indperc == 1)
	{
		ft_p1a(&str,e);
		cnt = cnt + ft_elsif1(&str,e,ap);
		cnt = cnt + ft_elsif2(&str,e,ap);
		cnt = cnt + ft_elsif3(&str,e,ap);
		if (e->indelsif == 0)
		{
			cnt = cnt + ft_elseend(*str,e);
			cnt++;
			ft_initialize(e);
		}
		e->indelsif = 0;
	}
	else
	{
		ft_putchar(**str);
		cnt++;
	}
	return (cnt);
}

void	ft_p1a(char ***str,t_numb *e)
{
	if (***str)
		(**str)++;
	if (e->indperc == 1)
	{
		(**str)--;
	}
	if (***str == 0)
		e->indelsif = 1;
}

