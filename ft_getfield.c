/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfield.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 08:16:18 by syusof            #+#    #+#             */
/*   Updated: 2016/03/16 19:39:09 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

char *ft_getfield(char *str)
{
	t_field		*f;

	f = (t_field*)malloc(sizeof(t_field));
	f->s3 = NULL;
	f->s4 = NULL;
	if ((*str >= '0' && *str <= '9') || *str == '-'
			|| *str == '+'|| *str == '.' || *str == ' '
			|| *str == '#')
		ft_getfield1(str,f);
	f->s4 = f->s3;
	free(f->s3);
	f->s3 = NULL;
	return (f->s4);
}

void		*ft_getfield1(char *str,t_field *f)
{
		f->i = 0;
		while((*str >= '0' && *str <= '9') || *str == '-'
				|| *str == '+'|| *str == '.' || *str == ' '
				|| *str == '#')
		{
			f->i++;
			str++;
		}
		str--;
		f->s3 = (char*)malloc(sizeof(char)*f->i + 1);
		f->s3[f->i] = 0;
		while(f->i > 0)
		{
			f->s3[f->i - 1] = *str;
			f->i--;
			str--;
		}

}
