/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 01:53:43 by syusof            #+#    #+#             */
/*   Updated: 2016/04/18 12:47:42 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"


int	ft_printf(char *str, ...)
{
	va_list		ap;
	t_numb	*e;
	int	cnt;

	va_start(ap, str);
	cnt = 0;
	e = (t_numb*)malloc(sizeof(t_numb));
	ft_p3(str,e);
	if (e->ind1 % 2 == 0)
	{
		while (*str != 0)
		{
			cnt = cnt + ft_p1(&str,e,ap);
			ft_p2(&str,e);
		}
	}
	else if (e->ind1 % 2 == 1)
		cnt = cnt + ft_p4(str,e);
	va_end(ap);
	free(e);
	e = NULL;
	return (cnt);
}
