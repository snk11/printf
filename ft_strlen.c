/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:37:22 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 15:22:38 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strlen(const char *str)
{
	size_t		i;

	if (str)
	{
		i = 0;
		while (str[i])
			i++;
		return (i);
	}
	return (0);
}

size_t		ft_strlen2(wchar_t *s)
{
	t_elem	*e;
	int		c1;
	int		r1;

	e = (t_elem*)malloc(sizeof(t_elem));
	e->ret = 0;
	while (*s)
	{
		c1 = *s;
		e->c2 = c1;
		if (e->c2 == 32)
		{
			e->ret++;
		}
		else
			e->ret = e->ret + (ft_strlen1(e));
		s++;
	}
	r1 = e->ret;
	free(e);
	e = NULL;
	return (r1);
}

int			ft_strlen1(t_elem *e)
{
	e->c3 = e->c2;
	e->n = 0;
	e->ret1 = 0;
	while (e->c2 > 0)
		ft_strlen1a(e);
	if (e->n <= 7)
		ft_strlen1b(e);
	else if (e->n > 7 && e->n <= 11)
		ft_strlen1c(e);
	else if (e->n > 11 && e->n <= 16)
		ft_strlen1d(e);
	else
		ft_strlen1e(e);
	ft_strlen1f(e);
	ft_strlen1g(e);
	ft_strlen1h(e);
	ft_strlen1i(e);
	ft_strlen1j(e);
	return (e->ret1);
}

void		ft_strlen1a(t_elem *e)
{
	e->c2 = e->c2 / 2;
	e->n++;
}

void		ft_strlen1b(t_elem *e)
{
	e->str2 = (char*)malloc(sizeof(char) * 8 + 1);
	e->str2[7] = '0';
	e->str2[8] = 0;
	e->n2 = 7;
}
