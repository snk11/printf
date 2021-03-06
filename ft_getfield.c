/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfield.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 08:16:18 by syusof            #+#    #+#             */
/*   Updated: 2016/05/04 13:06:26 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_getfield(char *str)
{
	t_field		*f;
	char		*st;

	f = (t_field*)malloc(sizeof(t_field));
	f->s3 = NULL;
	if ((*str >= '0' && *str <= '9') || *str == '-'
			|| *str == '+' || *str == '.' || *str == ' '
			|| *str == '#')
		ft_getfield1(str, f);
	st = f->s3;
	free(f);
	f = NULL;
	return (st);
}

void	ft_getfield1(char *str, t_field *f)
{
	f->i = 0;
	while ((*str >= '0' && *str <= '9') || *str == '-'
			|| *str == '+' || *str == '.' || *str == ' '
			|| *str == '#')
	{
		f->i++;
		str++;
	}
	str--;
	f->s3 = (char*)malloc(sizeof(char) * f->i + 1);
	f->s3[f->i] = 0;
	while (f->i > 0)
	{
		f->s3[f->i - 1] = *str;
		f->i--;
		str--;
	}
}
