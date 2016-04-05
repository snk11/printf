/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 04:22:52 by syusof            #+#    #+#             */
/*   Updated: 2016/04/05 05:29:44 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int	ft_checkll(char *str, t_numb *e,va_list ap, t_ll *w)
{

	int	 cnt;
	char *s2;
	char *s3;
	char *s4;
	int	i;

	w->k = 2;
	w->k2 = 0;

	cnt = 0;
	e->indll = 1;
	while (ft_checkletter(str[w->k]) != 1 && str[w->k])
	{
		(w->k)++;
	}
	if (str[w->k] && str[w->k] == 'x')
	{
		w->k = 2;
		while (ft_checkletter(str[w->k]) != 1 && str[w->k])
		{
			if (str[w->k] == '#')
				e->indsharp = 1;
			if( ((str[w->k] < '0' || str[w->k] > '9') && str[w->k] != ' ' && str[w->k] != '+' && str[w->k] != '-' && str[w->k] != '.' && str[w->k] != '#'))
			{
				ft_putchar(str[w->k]);
				cnt++;
				(w->k2)++;
			}
			(w->k)++;
		}
		if (w->k2 == 0)
		{
			e->ull = va_arg(ap, unsigned long long);
			s2 = ft_ltohex4(e->ull);
			if (e->indsharp == 1 && e->ull != 0)
			{
				s3 = (char*)malloc(sizeof(char)*ft_strlen(s2) + 1);
				s3[0] = '0';
				s3[1] = 'x';
				i = 2;
				while (i <= ft_strlen(s2) + 2)
				{
					s3[i] = s2[i - 2];
					i++;
				}
				free(s2);
				s2 = s3;
			}
			if (e->ull >= 4294967296 && e->ull <= 4563402751)
			{
				s4 = (char*)malloc(sizeof(char)*ft_strlen(s2) + 1);
				s4[0] = '1';
				i = 1;
				while (i <= ft_strlen(s2) + 2)
				{
					s4[i] = s2[i - 1];
					i++;
				}
				free(s2);
				s2 = s4;
			}
			e->s = s2;
			cnt = cnt + ft_checks(str,e);
		}
		else if (str[w->k] == 'x')
		{
			ft_putchar('x');
			cnt++;
		}
		//						k--;
//		while(w->k > 0)
//		{
//			str++;
//			w->k--;
//		}
		e->indll = 0;
	}
	else if (str[w->k] && str[w->k] == 'X')
	{
		w->k = 2;
		while (ft_checkletter(str[w->k]) != 1 && str[w->k])
		{
			if (str[w->k] == '#')
				e->indsharp = 1;
			if( ((str[w->k] < '0' || str[w->k] > '9') && str[w->k] != ' ' && str[w->k] != '+' && str[w->k] != '-' && str[w->k] != '.' && str[w->k] != '#'))
			{
				ft_putchar(str[w->k]);
				cnt++;
				(w->k2)++;
			}
			(w->k)++;
		}
		if (w->k2 == 0)
		{
			e->ull = va_arg(ap, unsigned long long);
			s2 = ft_ltohex5(e->ull);
			if (e->indsharp == 1 && e->ull != 0)
			{
				s3 = (char*)malloc(sizeof(char)*ft_strlen(s2) + 1);
				s3[0] = '0';
				s3[1] = 'X';
				i = 2;
				while (i <= ft_strlen(s2) + 2)
				{
					s3[i] = s2[i - 2];
					i++;
				}
				free(s2);
				s2 = s3;
			}
			if (e->ull >= 4294967296 && e->ull <= 4563402751)
			{
				s4 = (char*)malloc(sizeof(char)*ft_strlen(s2) + 1);
				s4[0] = '1';
				i = 1;
				while (i <= ft_strlen(s2) + 2)
				{
					s4[i] = s2[i - 1];
					i++;
				}
				free(s2);
				s2 = s4;
			}
			e->s = s2;
			cnt = cnt + ft_checks(str,e);
		}
		else if (str[w->k] == 'X')
		{
			ft_putchar('X');
			cnt++;
		}
		//						k--;
//		while(w->k > 0)
//		{
//			str++;
//			w->k--;
//		}
		e->indll = 0;
	}
	else if (str[w->k] && str[w->k] == 'O')
	{
		w->k = 2;
		while (ft_checkletter(str[w->k]) != 1 && str[w->k])
		{
			if (str[w->k] == '#')
				e->indsharp = 1;
			if( ((str[w->k] < '0' || str[w->k] > '9') && str[w->k] != ' ' && str[w->k] != '+' && str[w->k] != '-' && str[w->k] != '.' && str[w->k] != '#'))
			{
				ft_putchar(str[w->k]);
				cnt++;
				(w->k2)++;
			}
			(w->k)++;
		}
		if (w->k2 == 0)
		{
			e->us = va_arg(ap, unsigned short);
			s2 = ft_ltooct3(e->us);
			ft_putstr(s2);
			cnt = cnt + ft_strlen(s2);
		}
		else if (str[w->k] == 'O')
		{
			ft_putchar('O');
			cnt++;
		}
		//						k--;
//		while(w->k > 0)
//		{
//			str++;
//			w->k--;
//		}
		e->indll = 0;
	}
	else if ((str[w->k] && str[w->k] == 'U') || (str[w->k] && str[w->k] == 'D'))
	{
		w->k = 2;
		while (ft_checkletter(str[w->k]) != 1 && str[w->k])
		{
			if (str[w->k] == '#')
				e->indsharp = 1;
			if( ((str[w->k] < '0' || str[w->k] > '9') && str[w->k] != ' ' && str[w->k] != '+' && str[w->k] != '-' && str[w->k] != '.' && str[w->k] != '#'))
			{
				ft_putchar(str[w->k]);
				cnt++;
				(w->k2)++;
			}
			(w->k)++;
		}
		if (w->k2 == 0)
		{
			e->us = va_arg(ap, unsigned short);
			ft_putushortnbr(e->us);
			cnt = cnt + ft_countus(e->us);
		}
		else if (str[w->k] == 'U')
		{
			ft_putchar('U');
			cnt++;
		}
		else if (str[w->k] == 'D')
		{
			ft_putchar('D');
			cnt++;
		}
//		while(w->k > 0)
//		{
//			str++;
//			w->k--;
//		}
		e->indll = 0;
	}
	ft_initialize(e);
	return (cnt);
}
