/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 03:37:09 by syusof            #+#    #+#             */
/*   Updated: 2016/04/05 03:47:17 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		ft_case3(char **str,t_numb *e,va_list ap)
{
	int		cnt;

	cnt = 0;
	if (**str == 'U')
		cnt = cnt + ft_case3a(&str,e,ap);
	else if (**str == 'd' || **str == 'i')
		cnt = cnt + ft_case3b(&str,e,ap);
	else if (**str == 'D')
		cnt = cnt + ft_case3c(&str,e,ap);
	return (cnt);
}

int		ft_case3a(char ***str,t_numb *e,va_list ap)
{
	int	cnt;

	cnt = 0;
	e->ul = va_arg(ap, unsigned long);
	ft_putulongnbr(e->ul);
	cnt = cnt + ft_countul(e->ul);
	ft_initialize(e);
	return (cnt);
}

int		ft_case3b(char ***str,t_numb *e,va_list ap)
{
	int	cnt;

	cnt = 0;
	e->d = va_arg(ap, int);
	cnt = cnt + ft_checkd(**str,e);
	ft_initialize(e);
	return (cnt);
}

int		ft_case3c(char ***str,t_numb *e,va_list ap)
{
	int	cnt;
	
	cnt = 0;
	e->l = va_arg(ap, long);
	ft_putlongnbr(e->l);
	cnt = cnt + ft_countl(e->l);
	ft_initialize(e);
	return (cnt);
}

