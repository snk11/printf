/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 15:47:29 by syusof            #+#    #+#             */
/*   Updated: 2016/05/05 15:57:23 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF2_H
# define FT_PRINTF2_H

# include <stdlib.h>

typedef struct			s_numb
{
	int					indelsif;
	int					indplus;
	int					indspace;
	int					indsharp;
	int					indzero;
	int					indminus;
	int					indpr;
	int					indll;
	int					indperc;
	int					w;
	int					cnt1;
	int					ret1;
	int					pr;
	int					prbegi;
	int					d;
	int					g;
	char				c;
	size_t				z;
	intmax_t			j;
	short int			sd;
	long				l;
	long long			ll;
	unsigned int		u;
	unsigned char		uc;
	unsigned short		us;
	unsigned long		ul;
	unsigned long long	ull;
	char				*s;
	wchar_t				wc;
	wchar_t				*ss;
	int					ind1;
	int					ind2;
	int					ind6;
	int					indletter;
	int					indlast;
	char				*begi;
	int					valzero;
}						t_numb;

typedef struct			s_elem
{
	int					n;
	int					n2;
	char				*str;
	char				*str2;
	char				*begi;
	char				*begi2;
	int					c2;
	int					c3;
	int					ret;
	int					ret1;
	int					i;
	int					j;
	int					prbegi;
	int					*r;
	int					pr1;
}						t_elem;

typedef struct			s_count
{
	int					i;
	int					neg;
	int					minus;
}						t_count;

typedef struct			s_flag
{
	int					i;
	char				*begi;
	char				*s;
	char				*s2;
	int					indend1;
	int					indend2;
	int					num;
	int					ret;
}						t_flag;

typedef struct			s_field
{
	int					i;
	char				*s3;
}						t_field;

typedef struct			s_ll
{
	int					k;
	int					k2;
}						t_ll;

typedef struct			s_width
{
	int					k;
	int					i;
	int					j;
	char				*begi;
	char				*s;
	char				*s2;
}						t_width;

typedef struct			s_lst
{
	void				*content;
	struct s_lst		*next;
}						t_lst;

#endif
