/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 01:53:43 by syusof            #+#    #+#             */
/*   Updated: 2016/04/06 10:12:32 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

# include <stdio.h>
//+3.3-06 d
int	ft_printf(char *str, ...)
{

	va_list		ap;
	int			d;
	short int		sd;
	unsigned int	u;
	unsigned short	us;
	long		l;
	long int	ld;
	long long	ll;
	unsigned long long	ull;
	unsigned long		ul;
	char		*s2;
	char		*s3;
	char		*s4;
	char		c;
	unsigned char		uc;
	int			cnt;
	int			i;
	char		*p;
	wchar_t		*ss;
	wchar_t		wc;
	int		cnt1;
	int		g;
	char	sn[]="(null)";
	t_numb	*e;
	t_ll *w;

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
				else if (*str == 'h' && str[1] == 'o')
				{
					us = va_arg(ap, unsigned short);
					s2 = ft_ltooct5(us);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
					ft_initialize(e);
				}
				else if ((*str == 'j' || *str == 'z') && str[1] == 'o')
				{
					ull = va_arg(ap, unsigned long long);
					s2 = ft_ltooct4(ull);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
					ft_initialize(e);
				}
				else if (*str == 'l' && str[1] == 'l' && str[2] == 'o')
				{
					ull = va_arg(ap, unsigned long long);
					s2 = ft_ltooct4(ull);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
					str++;
					ft_initialize(e);
				}
				else if (*str == 'h' && str[1] == 'h' && str[2] == 'o')
				{
					uc = va_arg(ap, unsigned char);
					s2 = ft_ltooct6(uc);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
					str++;
					ft_initialize(e);
				}
				else if (*str == 'l' && str[1] == 'x')
				{
					ul = va_arg(ap, unsigned long);
					s2 = ft_ltohex3(ul);
					if (e->indsharp == 1 && ul != 0)
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
					if (ul >= 4294967296 && ul <= 4563402751)
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
					str++;
					ft_initialize(e);
				}
				else if (*str == 'h' && str[1] == 'x')
				{
					us = va_arg(ap, unsigned short);
					s2 = ft_ltohex6(us);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
					ft_initialize(e);
				}
				else if ((*str == 'j' || *str == 'z') && str[1] == 'x')
				{
					ull = va_arg(ap, unsigned long long);
					s2 = ft_ltohex3(ull);
					if (e->indsharp == 1 && ull != 0)
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
					if (ull >= 4294967296 && ull <= 4563402751)
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
						str++;
					ft_initialize(e);
				}
				else if (*str == 'l' && str[1] == 'l')
				{
					w = (t_ll*)malloc(sizeof(t_ll));
					cnt = cnt + ft_checkll(str,e,ap,w);
					while(w->k > 0)
					{
						str++;
						w->k--;
					}
					free(w);
					w = NULL;
				}
				else if (*str == 'h' && str[1] == 'h' && str[2] == 'x')
				{
					uc = va_arg(ap, unsigned char);
					s2 = ft_ltohex8(uc);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
					str++;
					ft_initialize(e);
				}
				else if (*str == 'l' && str[1] == 'X')
				{
					ul = va_arg(ap, unsigned long);
					s2 = ft_ltohex2(ul);
					if (e->indsharp == 1 && ul != 0)
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
					if (ul >= 4294967296 && ul <= 4563402751)
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
					str++;
					ft_initialize(e);
				}
				else if (*str == 'h' && str[1] == 'X')
				{
					us = va_arg(ap, unsigned short);
					s2 = ft_ltohex7(us);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
					ft_initialize(e);
				}
				else if ((*str == 'j' || *str == 'z') && str[1] == 'X')
				{
					ull = va_arg(ap, unsigned long long);
					s2 = ft_ltohex5(ull);
					if (e->indsharp == 1 && ull != 0)
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
					if (ull >= 4294967296 && ull <= 4563402751)
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
					str++;
					ft_initialize(e);
				}
				else if (*str == 'h' && str[1] == 'h' && str[2] == 'X')
				{
					uc = va_arg(ap, unsigned char);
					s2 = ft_ltohex9(uc);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
					str++;
					ft_initialize(e);
				}
				else if (*str == 'l' && str[1] == 'c')
				{
					wc = va_arg(ap, wchar_t);
					cnt = cnt + ft_putwchar(wc);
					str++;
					ft_initialize(e);
				}
				else if (*str == 'h' && str[1] == 'h' && str[2] == 'C')
				{
					wc = va_arg(ap, wchar_t);
					cnt = cnt + ft_putwchar(wc);
					str++;
					str++;
					ft_initialize(e);
				}
				else if (*str == 'l' && str[1] == 's')
				{
					ss = va_arg(ap, wchar_t*);
					if (ss)
					{
						cnt = cnt + ft_putwstr(ss);
					}
					else
					{
						ft_putstr("(null)");
						cnt = cnt + 6;
					}
					str++;
					ft_initialize(e);
				}
				else if (*str == 'h' && str[1] == 'h' && str[2] == 'S')
				{
					ss = va_arg(ap, wchar_t*);
					if (ss)
					{
						cnt = cnt + ft_putwstr(ss);
					}
					else
					{
						ft_putstr("(null)");
						cnt = cnt + 6;
					}
					str++;
					str++;
					ft_initialize(e);
				}
				else if ((*str == 'l' || *str == 'h' || *str == 'j' || *str == 'z') && str[1] == 'O')
				{
					us = va_arg(ap, unsigned short);
					s2 = ft_ltooct3(us);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
					ft_initialize(e);
				}
				else if (*str == 'h' && str[1] == 'h' && str[2] == 'O')
				{
					us = va_arg(ap, unsigned short);
					s2 = ft_ltooct3(us);
					ft_putstr(s2);
					cnt = cnt + ft_strlen(s2);
					str++;
					str++;
					ft_initialize(e);
				}
				else if ((*str == 'l' || *str == 'h' || *str == 'j' || *str == 'z') && (str[1] == 'U' || str[1] == 'D'))
				{
					us = va_arg(ap, unsigned short);
					ft_putushortnbr(us);
					cnt = cnt + ft_countus(us);
					str++;
					ft_initialize(e);
				}
				else if (*str == 'h' && str[1] == 'h' && (str[2] == 'U' || str[2] == 'D'))
				{
					us = va_arg(ap, unsigned short);
					ft_putushortnbr(us);
					cnt = cnt + ft_countus(us);
					str++;
					str++;
					ft_initialize(e);
				}
				else if (*str == 'l' && str[1] == 'p')
				{
					l = va_arg(ap, long);
					ft_putstr("0x");
					ft_putstr(ft_ltohex(l));
					cnt = cnt + ft_strlen(ft_ltohex(l)) + 2;
					str++;
					ft_initialize(e);
				}
				else if ((*str == 'z' || *str == 'j') && (str[1] != 'd' && str[1] != 'i') )
				{
					e->indperc = 1;
				}
				else if ((*str == 'h') && (str[1] != 'd' && str[1] != 'i' && str[1] != 'h' && (str[2] != 'd' && str[2] != 'i')) )
				{
					e->indperc = 1;
				}
				else if ((*str == 'l') && (str[1] != 'd' && str[1] != 'i' && str[1] != 'l' && (str[2] != 'd' && str[2] != 'i')) )
				{
					e->indperc = 1;
				}
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
