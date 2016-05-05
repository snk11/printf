/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checku_p3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:41:05 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 14:42:46 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_countu342a1(t_numb *e, t_count *f)
{
	int		j;
	int		r1;

	r1 = 0;
	r1 = r1 + ft_countu342a1a(e, f);
	if (e->indzero == 1 && e->indpr == 0)
	{
		j = 0;
		while (j < e->w - f->i)
		{
			ft_putchar('0');
			r1++;
			j++;
		}
	}
	return (r1);
}

int		ft_countu342a1a(void)
{
	int		r1;

	r1 = 0;
	ft_putchar('-');
	r1++;
	return (r1);
}

int		ft_countu342b(void)
{
	int		r1;

	r1 = 0;
	return (r1);
}

int		ft_countu3a(t_numb *e, t_count *f)
{
	int r1;

	r1 = 0;
	r1 = r1 + ft_countu3a1(e, f);
	return (r1);
}

int		ft_countu3a1(t_numb *e, t_count *f)
{
	int	r1;

	r1 = 0;
	if (e->indminus == 1)
		r1 = r1 + ft_countu3a1a(e, f);
	else
	{
		r1 = r1 + ft_countu3a142(e, f);
	}
	return (r1);
}
