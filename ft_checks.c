/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 01:26:49 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 14:36:38 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checks(t_numb *e)
{
	int	cnt;

	cnt = 0;
	e->prbegi = e->pr;
	if (e->indminus == 0)
	{
		if (e->s)
			cnt = cnt + ft_checks52a(e);
		else
			cnt = cnt + ft_checks2(e);
		return (cnt);
	}
	else if (e->indminus == 1)
	{
		if (e->s)
			cnt = cnt + ft_checks52b(e);
		else
			cnt = cnt + ft_checks22(e);
		return (cnt);
	}
	return (0);
}

int		ft_checks52a(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indpr == 1)
		cnt = cnt + ft_checks1(e);
	else
		cnt = cnt + ft_checks42(e);
	return (cnt);
}

int		ft_checks52b(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indpr == 1)
		cnt = cnt + ft_checks21(e);
	else
		cnt = cnt + ft_checks242(e);
	return (cnt);
}

int		ft_checks242(t_numb *e)
{
	int	cnt;

	cnt = 0;
	cnt = cnt + ft_checks242a(e);
	cnt = cnt + ft_checks242b(e);
	return (cnt);
}

int		ft_checks242a(t_numb *e)
{
	int	cnt;
	int	i;

	cnt = 0;
	e->g = ft_strlen(e->s);
	if (e->s)
	{
		ft_putstr(e->s);
		i = 0;
		while (i < e->g)
		{
			cnt++;
			i++;
		}
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	return (cnt);
}
