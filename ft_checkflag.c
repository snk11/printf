/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 20:57:54 by syusof            #+#    #+#             */
/*   Updated: 2016/03/17 16:46:41 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int ft_checkflag(t_numb *e,char *str)
{
	t_flag		*f;
	int			r1;
	char		*st1;
	char		*st2;


	f = (t_flag*)malloc(sizeof(t_flag));
	f->ret = 0;
	f->indend1 = 0;
	f->indend2 = 0;
	f->ret = 0;
	f->s = (char*)malloc(sizeof(char)*(ft_strlen(str)) + 1);
	st1 = f->s;
	f->i = 0;
	ft_checkflag1(e,str,f);
	f->s2 = (char*)malloc(sizeof(char) * f->i + 1);
	st2 = f->s2;
	ft_checkflag2(e,f);
	if(f->indend1 == 1)
		ft_checkflag3(e,f);
	else if(f->indend2 == 1)
		ft_checkflag4(e,f);
	r1 = f->ret;
	f->s = st1;
	f->s2 = st2;
	free(f->s);
	f->s = NULL;
	free(f->s2);
	f->s2 = NULL;
	free(f);
	f = NULL;
	return (r1);
}

void	ft_checkflag1(t_numb *e,char *str,t_flag *f)
{
	while (f->i < ft_strlen(str))
	{
		f->s[f->i] = str[f->i];
		f->i++;
	}
	f->s[f->i] = 0;
	f->i = 0;
	f->begi = f->s;
	while((f->s[0] >= '0' && f->s[0] <= '9') || f->s[0] == ' ' || f->s[0] == '+'
			|| f->s[0] == '-' || f->s[0] == '.' || f->s[0] == '#')
	{
		if (f->s[0] == '.')
			e->indpr = 1;
		f->s++;
		f->i++;
	}
}


void	ft_checkflag2(t_numb *e,t_flag *f)
{
	f->s = f->begi;
	f->s2[f->i] = 0;
	f->i--;
	while (f->i >= 0 && f->s[f->i] != '-' && f->s[f->i] != '+'
			&& f->s[f->i] != ' ' && f->s[f->i] != '#' )
	{
		f->s2[f->i] = f->s[f->i];
		f->i--;
	}
	if (f->i < 0)
		f->i++;
	if ((f->i >= 0 && f->s[f->i] == '-') || (f->i>= 0 && f->s[f->i] == '+')
			|| (f->i>= 0 && f->s[f->i] == ' ') || (f->i>= 0 && f->s[f->i] == '#'))
	{
		f->indend1 = 1;
		f->num = f->i;
	}
	f->indend2 = 1;
}

void	ft_checkflag3(t_numb *e,t_flag *f)
{
	f->i = f->num;
	f->s = f->begi;
	if (f->s[f->i+1] && f->s[f->i+1] == '0')
	{
		e->indzero = 1;
		f->ret++;
	}
	while (f->i >= 0 && (f->s[f->i] == '-' || f->s[f->i] == '+' || f->s[f->i] == ' '
				|| f->s[f->i] == '#' || f->s[f->i] == '0' ))
		ft_checkflag3a(e,f);
}

void	ft_checkflag3a(t_numb *e,t_flag *f)
{
	ft_checkflag3a1(e,f);
	if (f->s2[f->i] == '-')
	{
		e->indminus = 1;
		f->ret++;
	}
	if (f->s2[f->i] == '0')
	{
		e->indzero = 1;
		f->ret++;
	}
	f->i--;
}


void	ft_checkflag3a1(t_numb *e,t_flag *f)
{
	f->s2[f->i] = f->s[f->i];
	if (f->s2[f->i]== ' ')
	{
		e->indspace = 1;
		f->ret++;
	}
	if (f->s2[f->i]== '#')
	{
		e->indsharp = 1;
		f->ret++;
	}
	if (f->s2[f->i] == '+')
	{
		e->indplus = 1;
		f->ret++;
	}
}


void	ft_checkflag4(t_numb *e,t_flag *f)
{
	while (( *(f->s2) == ' ' || *(f->s2) == '#' || *(f->s2) == '+' || *(f->s2) == '-'))
	{
		ft_checkflag4a(e,f);
		if (*(f->s2) == '-')
		{
			e->indminus = 1;
		}
		f->s2++;
	}
	if (*(f->s2) && *(f->s2) == '0')
		e->indzero = 1;
}


void	ft_checkflag4a(t_numb *e,t_flag *f)
{
	if ( *(f->s2) == ' ' && f->ret == 0)
	{
		e->indspace = 1;
		f->ret++;
	}
	if (*(f->s2) == '#')
	{
		e->indsharp = 1;
		f->ret++;
	}
	if (*(f->s2) == '+')
	{
		e->indplus = 1;
		f->ret++;
	}
}
