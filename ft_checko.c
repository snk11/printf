/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checko.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 03:28:36 by syusof            #+#    #+#             */
/*   Updated: 2016/03/17 17:40:45 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		ft_checko(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->u == 0 && e->pr == 0 && e->indpr == 1 && e->indsharp == 0)
	{
	}
	else
		cnt = cnt + ft_checko1(str,e);
	free(e->s);
	e->s = NULL;
	return (cnt);
}





int		ft_checko1(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	e->s = ft_ltooct(e->u);
	e->g = ft_strlen(e->s);
	if (e->indsharp == 1 && e->u != 0 && e->pr == 0)
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
		cnt = cnt + ft_checko1a(str,e);
	ft_putstr(e->s);
	cnt = cnt + e->g;
	return (cnt);
}


int		ft_checko1a(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->pr >= e->g)
	{
		while(e->w - e->pr > 0)
		{
			ft_putchar(' ');
			cnt++;
			(e->w)--;
		}

		while((e->pr - e->g) > 0)
		{
			ft_putchar('0');
			cnt++;
			(e->pr)--;
		}
	}
	else
		cnt = cnt + ft_checko1a1(str,e);
	return (cnt);
}

int		ft_checko1a1(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	while(e->w - e->g > 0)
	{
		ft_putchar(' ');
		cnt++;
		(e->w)--;
	}
	return (cnt);
}
