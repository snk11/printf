/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_altprime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 12:09:43 by syusof            #+#    #+#             */
/*   Updated: 2016/03/23 03:38:30 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"


int		ft_altprime(char *str,t_numb *e)
{
	int	cnt;
	char *begi;
	int	i;
	cnt = 0;
	while (*str != 0)
	{
		e->g = 0;
		e->ret1 = 0;
		if (*str == '%')
			ft_altprime1(&str,e);
		if (e->cnt1 % 2 == 0 && *str == '%' && e->indlast == 0 && e->ind6 != 1)
		{
			ft_putchar('%');
			cnt++;
		}
		else if (e->indlast == 0)
			cnt = cnt + ft_altprime2(str,e);
		if (*str)
			str++;
	}
	return (cnt);
}

void		ft_altprime1(char **str,t_numb *e)
{
	int	i;
	char	*begi;

	if (**str && (*str)[1])
		(*str)++;
	else
		e->indlast = 1;
	i = 0;
	begi = NULL;
	begi = ft_getfield(*str);
	if (begi)
	{
		e->ind6++;
		e->g = ft_strlen(begi);
	}
	while (i < e->g)
	{
		(*str)++;
		i++;
	}
	e->ret1 = ft_checkflag(e,begi);
	if (e->w == 0 && begi)
		e->w = ft_checkwidth(begi);
	if (e->pr == 0 && begi)
		e->pr = ft_checkprec(begi);
	if(**str == 'h')
		(*str)++;
}


int		ft_altprime2(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	cnt = cnt + ft_altprime2a(str,e);
	if (*str == '%')
		e->cnt1++;
//	if ((*e)->cnt1 % 2 == 1 && (*e)->indlast == 1)
//		(*e)->cnt1++;
	return (cnt);
}


int		ft_altprime2a(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indzero == 0)
		cnt = cnt + ft_altprime2a1(str,e);
	else if (e->indzero == 1)
		cnt = cnt + ft_altprime2a2(str,e);
	e->w = 0;
	e->pr = 0;
	e->indzero = 0;
	return (cnt);
}



int		ft_altprime2a1(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	if(e->indminus == 1)
		cnt = cnt +ft_altprime2a1a(str,e);
	else
	{
		while((e->w - 1) > 0)
		{
			cnt++;
			ft_putchar(' ');
			(e->w)--;
		}
		if (*str)
		{
			ft_putchar(*str);
			cnt++;
		}
	}
	return (cnt);
}


int		ft_altprime2a1a(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (*str)
	{
		ft_putchar(*str);
		cnt++;
	}
	while((e->w - 1) > 0)
	{
		cnt++;
		ft_putchar(' ');
		(e->w)--;
	}
	return (cnt);
}


int		ft_altprime2a2(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	if(e->indminus == 1)
		cnt =cnt +ft_altprime2a2a(str,e);
	else
	{
		while((e->w - 1) > 0)
		{
			cnt++;
			ft_putchar('0');
			(e->w)--;
		}
		if (*str)
		{
			ft_putchar(*str);
			cnt++;
		}
	}
	return (cnt);
}


int		ft_altprime2a2a(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (*str)
	{
		ft_putchar(*str);
		cnt++;
	}
	while((e->w - 1) > 0)
	{
		cnt++;
		ft_putchar(' ');
		(e->w)--;
	}
	return (cnt);
}
