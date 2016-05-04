/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkwidth.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:55:14 by syusof            #+#    #+#             */
/*   Updated: 2016/05/04 17:42:05 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkwidth(t_numb *e, char *str)
{
	t_width		*w;
	int			r1;

	w = (t_width*)malloc(sizeof(t_width));
	w->s = (char*)malloc(sizeof(char) * (ft_strlen(str)) + 1);
	ft_checkwidth1(str, w, e);
	w->s2 = (char*)malloc(sizeof(char) * w->j + 1);
	ft_checkwidth2(w);
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
}

void	ft_checkwidth1(char *str, t_width *w, t_numb *e)
{
	w->k = 0;
	w->i = 0;
	w->j = 0;
	while (w->i < (int)ft_strlen(str))
	{
		w->s[w->i] = str[w->i];
		w->i++;
	}
	w->s[w->i] = 0;
	w->begi = w->s;
	while ((*w->s) && ((w->s[0] >= '0' && w->s[0] <= '9') || w->s[0] == ' '
				|| w->s[0] == '+' || w->s[0] == '-' || w->s[0] == '.'
				|| w->s[0] == '#'))
	{
		ft_checkwidth1a(w, e);
		w->s++;
	}
	w->s = w->begi;
}

void	ft_checkwidth1a(t_width *w, t_numb *e)
{
	if (w->s[0] >= '1' && w->s[0] <= '9')
		w->k = 1;
	if (w->s[0] != '-' && w->s[0] != '+' && w->s[0] != ' ' && w->s[0] != '#')
	{
		w->j++;
	}
	if (w->s[0] == '.')
		e->indpr = 1;
	if (w->s[0] == '-')
		e->indminus = 1;
	if (w->s[0] == '+')
		e->indplus = 1;
	if (w->s[0] == ' ')
		e->indspace = 1;
	if (w->s[0] == '#')
		e->indsharp = 1;
	if (w->s[0] == '0' && w->k == 0)
	{
		e->indzero = 1;
		w->j++;
	}
}

void	ft_checkwidth2(t_width *w)
{
	w->s2[w->j] = 0;
	w->j = 0;
	while ((*w->s) && ((w->s[0] >= '0' && w->s[0] <= '9') || w->s[0] == ' '
				|| w->s[0] == '+' || w->s[0] == '-' || w->s[0] == '.'
				|| w->s[0] == '#'))
	{
		if (w->s[0] != '-' && w->s[0] != '+' && w->s[0] != ' '
				&& w->s[0] != '#')
		{
			w->s2[w->j] = w->s[0];
			w->j++;
		}
		w->s++;
	}
	w->s = w->begi;
}
