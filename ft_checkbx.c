/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkbx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 03:10:21 by syusof            #+#    #+#             */
/*   Updated: 2016/03/03 03:26:19 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		ft_checkbx(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->u == 0 && e->pr == 0 & e->indpr == 1)
	{
	}
	else
		cnt = cnt + ft_checkbx1(str,e);
	return (cnt);
}

int		ft_checkbx1(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;

	e->s = ft_ltohex2(e->u);
	e->g = ft_strlen(e->s);
	if (e->indsharp == 1 && e->u != 0)
	{
		ft_putchar('0');
		ft_putchar('X');
		cnt++;
		cnt++;
	}
	if (e->indzero == 1 && e->pr == 0)
	{
		while(e->w - e->g > 0)
		{
			ft_putchar('0');
			cnt++;
			(e->w)--;
		}
	}
	else
		cnt = cnt + ft_checkx1a(str,e);
	ft_putstr(e->s);
	cnt = cnt + e->g;
	return (cnt);
}

