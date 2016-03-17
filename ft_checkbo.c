/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkbo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 03:41:10 by syusof            #+#    #+#             */
/*   Updated: 2016/03/17 18:00:51 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		ft_checkbo(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->ul == 0 && e->pr == 0 && e->indpr == 1 && e->indsharp == 0)
	{
	}
	else
	{
		cnt = cnt + ft_checkbo1(str,e);
		if (ft_strcmp(e->s,"1000000000000000000000") != 0)
		{
			free(e->s);
			e->s = NULL;
		}
	}
	return (cnt);
}





int		ft_checkbo1(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	e->s = ft_ltooct2(e->ul);
	e->g = ft_strlen(e->s);
	if (e->indsharp == 1 && e->ul != 0 && e->pr == 0)
	{
		ft_putchar('0');
		cnt++;
	}
	if (e->indzero == 1 && e->pr == 0)
	{
		while(e->w - e->g > 0)
		{
			ft_putchar('0');
			cnt++;
			e->w--;
		}
	}
	else
	{
		cnt = cnt + ft_checko1a(str,e);
		ft_putstr(e->s);
	}
	cnt = cnt + e->g;
	return (cnt);
}

