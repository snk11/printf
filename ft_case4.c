/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 03:57:38 by syusof            #+#    #+#             */
/*   Updated: 2016/04/05 04:03:05 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"


int		ft_case4(char **str,t_numb *e,va_list ap)
{
	int		cnt;

	cnt = 0;
	if (**str == 'x')
		cnt = cnt + ft_case4a(&str,e,ap);
	else if (**str == 'X')
		cnt = cnt + ft_case4b(&str,e,ap);
	else if (**str == 'o')
		cnt = cnt + ft_case4c(&str,e,ap);
	return (cnt);
}

int		ft_case4a(char ***str,t_numb *e,va_list ap)
{
	int	cnt;

	cnt = 0;
	e->u = va_arg(ap, unsigned int);
	cnt = cnt + ft_checkx(**str,e);
	ft_initialize(e);
	return (cnt);
}

int		ft_case4b(char ***str,t_numb *e,va_list ap)
{
	int	cnt;

	cnt = 0;
	e->u = va_arg(ap, unsigned int);
	cnt = cnt + ft_checkbx(**str,e);
	ft_initialize(e);
	return (cnt);
}

int		ft_case4c(char ***str,t_numb *e,va_list ap)
{
	int	cnt;

	cnt = 0;
	e->u = va_arg(ap, unsigned int);
	cnt = cnt + ft_checko(**str,e);
	ft_initialize(e);
	return (cnt);
}

