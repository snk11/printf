/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 01:53:43 by syusof            #+#    #+#             */
/*   Updated: 2016/04/06 13:27:28 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

# include <stdio.h>
//+3.3-06 d
int	ft_printf(char *str, ...)
{
	va_list		ap;
	char		*p;
	t_numb	*e;
	int	cnt;

	e = (t_numb*)malloc(sizeof(t_numb));
	p = NULL;
	cnt = 0;
	ft_initialize(e);
	e->indll = 0;
	va_start(ap, str);
	//	begi = &(str[0]);
	p = ft_check_perc0(str);
	if (p == NULL)
	{
		e->ind1++;
	}

	if (e->ind1 % 2 == 0)
	{
		while (*str != 0)
		{
			if ( *str == '%' || e->indperc == 1)
			{
				if (*str)
					str++;
				if (e->indperc == 1)
				{
					str--;
				}
				if (*str == 0)
				{
				}
				else if (*str == 'c' || *str == 'C' || *str == 's')
					cnt = cnt + ft_case1(&str,e,ap);
				else if (*str == 'S' || *str == 'p' || *str == 'u')
					cnt = cnt + ft_case2(&str,e,ap);
				else if (*str == 'U' || *str == 'd' || *str == 'i' || *str == 'D')
					cnt = cnt + ft_case3(&str,e,ap);
				else if (*str == 'x' || *str == 'X' || *str == 'o' || *str == 'O')
					cnt = cnt + ft_case4(&str,e,ap);
				else if ((*str == 'z' && (str[1] == 'h' || str[1] == 'i') && str[2] == 'd') || (*str == 'j' && (str[1] == 'z' || str[1] == 'h') && str[2] == 'd') || (*str == 'l' && (str[1] == 'd' || str[1] == 'i')) )
					cnt = cnt + ft_case5(&str,e,ap);
				else if ((*str == 'h' && (str[1] == 'd' || str[1] == 'i')) || ((*str == 'j' || *str == 'z') && (str[1] == 'd' || str[1] == 'i')) || (*str == 'l' && str[1] == 'l' && (str[2] == 'd' || str[2] == 'i')) )
					cnt = cnt + ft_case6(&str,e,ap);
				else if ((*str == 'h' && str[1] == 'h' && (str[2] == 'd' || str[2] == 'i')) || (*str == 'h' && str[1] == 'h' && str[2] == 'l' && (str[3] == 'd' || str[3] == 'i')) || (*str == 'l' && str[1] == 'u') )
					cnt = cnt + ft_case7(&str,e,ap);
				else if ((*str == 'h' && str[1] == 'u') || (*str == 'h' && str[1] == 'U') || ((*str == 'j' || *str == 'z') && str[1] == 'u'))
					cnt = cnt + ft_case8(&str,e,ap);
				else if ((*str == 'l' && str[1] == 'l' && str[2] == 'u') || (*str == 'h' && str[1] == 'h' && str[2] == 'u') || (*str == 'l' && str[1] == 'o'))
					cnt = cnt + ft_case9(&str,e,ap);
				else if ((*str == 'h' && str[1] == 'o') || ((*str == 'j' || *str == 'z') && str[1] == 'o') || (*str == 'l' && str[1] == 'l' && str[2] == 'o'))
					cnt = cnt + ft_case10(&str,e,ap);
				else if ((*str == 'h' && str[1] == 'h' && str[2] == 'o') || (*str == 'l' && str[1] == 'x') || (*str == 'h' && str[1] == 'x'))
					cnt = cnt + ft_case11(&str,e,ap);
				else if (((*str == 'j' || *str == 'z') && str[1] == 'x') || (*str == 'l' && str[1] == 'l') || (*str == 'h' && str[1] == 'h' && str[2] == 'x'))
					cnt = cnt + ft_case12(&str,e,ap);
				else if ((*str == 'l' && str[1] == 'X') || (*str == 'h' && str[1] == 'X') || ((*str == 'j' || *str == 'z') && str[1] == 'X'))
					cnt = cnt + ft_case13(&str,e,ap);
				else if ((*str == 'h' && str[1] == 'h' && str[2] == 'X') || (*str == 'l' && str[1] == 'c') || (*str == 'h' && str[1] == 'h' && str[2] == 'C'))
					cnt = cnt + ft_case14(&str,e,ap);
				else if ((*str == 'l' && str[1] == 's') || (*str == 'h' && str[1] == 'h' && str[2] == 'S') || ((*str == 'l' || *str == 'h' || *str == 'j' || *str == 'z') && str[1] == 'O'))
					cnt = cnt + ft_case15(&str,e,ap);
				else if ((*str == 'h' && str[1] == 'h' && str[2] == 'O') || ((*str == 'l' || *str == 'h' || *str == 'j' || *str == 'z') && (str[1] == 'U' || str[1] == 'D')) || (*str == 'h' && str[1] == 'h' && (str[2] == 'U' || str[2] == 'D')))
					cnt = cnt + ft_case16(&str,e,ap);
				else if ((*str == 'l' && str[1] == 'p') || ((*str == 'z' || *str == 'j') && (str[1] != 'd' && str[1] != 'i') ) || ((*str == 'h') && (str[1] != 'd' && str[1] != 'i' && str[1] != 'h' && (str[2] != 'd' && str[2] != 'i')) ) || ((*str == 'l') && (str[1] != 'd' && str[1] != 'i' && str[1] != 'l' && (str[2] != 'd' && str[2] != 'i')) ))
					cnt = cnt + ft_case17(&str,e,ap);
				else if ((*str >= '0' && *str <= '9') || *str == '-' ||*str == '+' || *str == '.' || *str == ' ' || *str == '#')
				{
					if (e->indperc == 0)
					{
						e->begi = NULL;
						e->begi = ft_getfield(str);
//						if (e->begi)
//							e->ret1 = ft_checkflag(e,e->begi);
						if (e->w == 0 && e->begi)
							e->w = ft_checkwidth(e,e->begi);
						if (e->pr == 0 && e->begi)
							e->pr = ft_checkprec(e,e->begi);
						free(e->begi);
						e->begi = NULL;
					}
					e->indperc = 1;
				}
				else
				{
					cnt = cnt + ft_elseend(str,e);
					cnt++;
					ft_initialize(e);
				}
			}
			else
			{
				ft_putchar(*str);
				cnt++;
			}
			if (*str != 0)
			{
				if (e->indll == 1)
				{
					str++;
					str++;
					e->indll = 0;
				}
				else
					str++;
			}
		}
	}


	else if (e->ind1 % 2 == 1)
	{
		e->ind6 = 0;
		e->cnt1 = 0;
		//		cnt2 = 0;
		//		c2 = 0;
		e->indlast = 0;
		e->ind2 = 0;

		cnt = cnt + ft_altprime(str,e);
	}

	va_end(ap);
	free(e);
	e = NULL;
	return (cnt);
}
