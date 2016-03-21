/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkwidth.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:55:14 by syusof            #+#    #+#             */
/*   Updated: 2016/03/21 02:08:11 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		ft_checkwidth(char *str)
{
	t_width		*w;
	int			r1;

	w = (t_width*)malloc(sizeof(t_width));
	w->s = (char*)malloc(sizeof(char)*(ft_strlen(str)) + 1);
	ft_checkwidth1(str,w);
	w->s2 = (char*)malloc(sizeof(char) * w->i + 1);
	ft_checkwidth2(str,w);
	if (w->i < 0)
	{
		r1 = ft_atoi(w->s2);
		free(w->s);
		w->s = NULL;
		free(w->s2);
		w->s2 = NULL;
		free(w);
		w = NULL;
		return (r1);
	}
	else
	{
		w->i++;
		r1 = ft_atoi(&(w->s2[w->i]));
		free(w->s);
		w->s = NULL;
		free(w->s2);
		w->s2 = NULL;
		free(w);
		w = NULL;
		return (r1);
	}
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
	while((w->s[0] >= '0' && w->s[0] <= '9') || w->s[0] == ' ' || w->s[0] == '+' || w->s[0] == '-' || w->s[0] == '.' || w->s[0] == '#')
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
