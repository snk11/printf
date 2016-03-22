/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 02:42:08 by syusof            #+#    #+#             */
/*   Updated: 2016/03/22 07:48:08 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"


int		ft_checkx(char *str,t_numb *e)
{
	int	cnt;

	e->s = ft_ltohex(e->u);
	e->g = ft_strlen(e->s);
	cnt = 0;
	if (e->u == 0 && e->pr == 0 & e->indpr == 1)
	{
		while(e->w)
		{
			ft_putchar(' ');
			e->w--;
			cnt++;
		}
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

	if (e->indsharp == 1 && e->u != 0)
	{
		ft_putchar('0');
		ft_putchar('x');
		cnt++;
		cnt++;
	}
	if (e->indzero == 1 && e->pr == 0)
		cnt = cnt + ft_checkx0a(str,e);
	else if (e->indsharp == 0)
	{
		ft_putstr(e->s);
		cnt = cnt + ft_checkx1a(str,e);
	}
	cnt = cnt + e->g;
	return (cnt);
}

int		ft_checkx0a(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
		ft_putstr(e->s);
		if (e->indsharp == 1)
		{
			while(e->w - (e->g + 2) > 0)
			{
				ft_putchar(' ');
				cnt++;
				(e->w)--;
			}
		}
		else
		{
			while(e->w - e->g > 0)
			{
				ft_putchar(' ');
				cnt++;
				(e->w)--;
			}
		}
	return (cnt);
}


int		ft_checkx1(char *str,t_numb *e)
{
	int	cnt;
	int	i;

	cnt = 0;

	if (e->indsharp == 1 && e->u != 0)
		cnt = cnt + ft_checkx142a(str,e);
	if (e->indzero == 1 && e->pr == 0)
		cnt = cnt + ft_checkx142b(str,e);
	else if (e->indsharp == 0)
		cnt = cnt + ft_checkx1a(str,e);
	ft_putstr(e->s);
	cnt = cnt + e->g;
	return (cnt);
}

int		ft_checkx142a(char *str,t_numb *e)
{
	int	cnt;
	int	i;

	cnt = 0;
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
		ft_putchar('x');
		cnt++;
		cnt++;
		i = 0;
		while( i < e->pr - e->g)
		{
			ft_putchar('0');
			cnt++;
			i++;
		}
	return (cnt);
}

int		ft_checkx142b(char *str,t_numb *e)
{
	int	cnt;
	int	i;

	cnt = 0;

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
