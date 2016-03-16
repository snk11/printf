/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkwidth.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:55:14 by syusof            #+#    #+#             */
/*   Updated: 2016/03/16 19:40:24 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		ft_checkwidth(char *str)
{
	t_width		*w;

	w = (t_width*)malloc(sizeof(t_width));
	w->s = (char*)malloc(sizeof(char)*(ft_strlen(str)) + 1);
	ft_checkwidth1(str,w);
	w->s2 = (char*)malloc(sizeof(char) * w->i + 1);
	ft_checkwidth2(str,w);
	if (w->i < 0)
	{
		free(w->begi);
		return (ft_atoi(w->s2));
	}
	else
	{
		w->i++;
		free(w->begi);
		return (ft_atoi(&(w->s2[w->i])));
	}
	ft_checkwidth3(str,w);
	return ft_atoi(w->s);
}


void		ft_checkwidth1(char *str,t_width *w)
{
	w->i = 0;
	while (w->i < ft_strlen(str))
	{
		w->s[w->i] = str[w->i];
		w->i++;
	}
	w->s[w->i] = 0;
	w->i = 0;
	w->begi = w->s;
	while((w->s[0] >= '0' && w->s[0] <= '9') || w->s[0] == ' ' || w->s[0] == '+' || w->s[0] == '-' || w->s[0] == '.')
	{
		w->s++;
		w->i++;
	}
	w->s = w->begi;
}

void		ft_checkwidth2(char *str,t_width *w)
{
	w->s2[w->i] = 0;
	w->i--;
	while (w->i >= 0 && w->s[w->i] != '-' && w->s[w->i] != '+' && w->s[w->i] != ' ' && w->s[w->i] != '#')
	{
		w->s2[w->i] = w->s[w->i];
		w->i--;
	}
}


void		ft_checkwidth3(char *str,t_width *w)
{
	while(*(w->s))
	{
		w->s++;
		w->i++;
	}
	w->s--;
	while ((*(w->s) == ' ' || *(w->s) == '-' || (*(w->s) >= '0' && *(w->s) <= '9')) && w->i > 0)
	{
		w->s--;
		w->i--;
	}
	w->s++;
}
