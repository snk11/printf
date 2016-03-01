/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_onelettercase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 21:41:15 by syusof            #+#    #+#             */
/*   Updated: 2016/03/02 00:42:08 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int ft_onelettercase(char *str,t_numb *e)
{
	return (ft_checkc(str,e));
}

int ft_checkc(char *str,t_numb *e)
{

	if (e->indzero == 0)
		return (ft_checkc1(str,e));
	else
	{
		return (ft_checkc2(str,e));
	}
}

int		ft_checkc1(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	if(e->w < 0)
		return (ft_checkc1a(str,e));
	else
		return (ft_checkc1b(str,e));
}

int		ft_checkc1a(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	e->w = -(e->w);
	ft_putchar(e->d);
	cnt++;
	while((e->w - 1) > 0)
	{
		cnt++;
		ft_putchar(' ');
		(e->w)--;
	}
	return (cnt);
}

int		ft_checkc1b(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	while((e->w - 1) > 0)
	{
		cnt++;
		ft_putchar(' ');
		(e->w)--;
	}
	ft_putchar(e->d);
	cnt++;
	return (cnt);
}
int		ft_checkc2(char *str,t_numb *e)
{
	int		cnt;

	cnt = 0;
	if(e->w < 0)
		return (ft_checkc2a(str,e));
	else
		return (ft_checkc2b(str,e));
}

int		ft_checkc2a(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
		e->w = -(e->w);
		ft_putchar(e->d);
		cnt++;
		while((e->w - 1) > 0)
		{
			cnt++;
			ft_putchar('0');
			(e->w)--;
		}
		return (cnt);

}

int		ft_checkc2b(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
		while((e->w - 1) > 0)
		{
			cnt++;
			ft_putchar('0');
			(e->w)--;
		}
		ft_putchar(e->d);
		cnt++;
		return (cnt);
}
