/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkbx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 03:10:21 by syusof            #+#    #+#             */
/*   Updated: 2016/03/22 03:12:29 by syusof           ###   ########.fr       */
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
	int	i;

	cnt = 0;

	e->s = ft_ltohex2(e->u);
	e->g = ft_strlen(e->s);
	if (e->indsharp == 1 && e->u != 0)
	{
		if (e->indzero == 0)
		{
			while(e->w - (e->g + 2) > 0)
			{
				ft_putchar(' ');
				cnt++;
				(e->w)--;
			}
		}
		ft_putchar('0');
		ft_putchar('X');
		cnt++;
		cnt++;
		i = 0;
		while( i < e->pr - e->g)
		{
			ft_putchar('0');
			cnt++;
			i++;
		}
	}
	if (e->indzero == 1 && e->pr == 0)
	{
		if (e->indsharp == 1)
		{
			while(e->w - (e->g + 2) > 0)
			{
				ft_putchar('0');
				cnt++;
				(e->w)--;
			}
		}
		else
		{
			while(e->w - e->g  > 0)
			{
				ft_putchar('0');
				cnt++;
				(e->w)--;
			}
		}
	}
	else if (e->indsharp == 0)
		cnt = cnt + ft_checkx1a(str,e);
	ft_putstr(e->s);
	cnt = cnt + e->g;
	return (cnt);
}
