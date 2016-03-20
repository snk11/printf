/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 02:42:08 by syusof            #+#    #+#             */
/*   Updated: 2016/03/20 22:16:26 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"


int		ft_checkx(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->u == 0 && e->pr == 0 & e->indpr == 1)
	{
	}
	else if(e->indminus == 1)
		cnt = cnt + ft_checkx0(str,e);
	else if(e->indminus == 0)
		cnt = cnt + ft_checkx1(str,e);
	return (cnt);
}



int		ft_checkx0(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;

	e->s = ft_ltohex(e->u);
	e->g = ft_strlen(e->s);
	if (e->indsharp == 1 && e->u != 0)
	{
		ft_putchar('0');
		ft_putchar('x');
		cnt++;
		cnt++;
	}
	if (e->indzero == 1 && e->pr == 0)
	{
		ft_putstr(e->s);
		while(e->w - e->g > 0)
		{
			ft_putchar('0');
			cnt++;
			(e->w)--;
		}
	}
	else
	{
		ft_putstr(e->s);
		cnt = cnt + ft_checkx1a(str,e);
	}
	cnt = cnt + e->g;
	return (cnt);
}


int		ft_checkx1(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;

	e->s = ft_ltohex(e->u);
	e->g = ft_strlen(e->s);
	if (e->indsharp == 1 && e->u != 0)
	{
		ft_putchar('0');
		ft_putchar('x');
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


int		ft_checkx1a(char *str,t_numb *e)
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
		cnt = cnt + ft_checkx1a1(str,e);
	return (cnt);
}

int		ft_checkx1a1(char *str,t_numb *e)
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
