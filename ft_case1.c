/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:10:46 by syusof            #+#    #+#             */
/*   Updated: 2016/03/08 16:53:46 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		ft_case1(char **str,t_numb **e,...)
{
	int		cnt;

	cnt = 0;
	if (**str == 'c')
		cnt = cnt + ft_case1a(&str,&e);
	else if (**str == 'C')
	{
		wc = va_arg(ap, wchar_t);
		e->cursorap++;
		cnt = cnt + ft_putwchar(wc);
	}
	else if (**str == 's')
	{
		e->prbegi = e->pr;
		e->s = va_arg(ap, char*);
		e->cursorap++;
		cnt = cnt + ft_checks(*str,*e);
		ft_initialize(e);
	}
}

int		ft_case1a(char ***str,t_numb ***e)
{
	int		cnt;
	int		i;
	va_list		ap;

	cnt = 0;
	i = (**e)->cursorap;
	va_start(ap,(**e)->strini);
	while (i > 0)
	{
		(**e)->d = va_arg(ap, int);
		i--;
	}
	va_end(ap);
	(**e)->cursorap++;
	cnt = cnt + ft_checkc(**str,(**e));
	ft_initialize(*e);
}
