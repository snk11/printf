/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case12.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 10:19:16 by syusof            #+#    #+#             */
/*   Updated: 2016/04/06 12:02:53 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "ft_printf.h"


int		ft_case12(char **str,t_numb *e,va_list ap)
{
	int		cnt;

	cnt = 0;
	if ((**str == 'j' || **str == 'z') && (*str)[1] == 'x')
		cnt = cnt + ft_case12a(&str,e,ap);
	else if (**str == 'l' && (*str)[1] == 'l')
		cnt = cnt + ft_case12b(&str,e,ap);
	else if (**str == 'h' && (*str)[1] == 'h' && (*str)[2] == 'x')
		cnt = cnt + ft_case12c(&str,e,ap);
	return (cnt);
}

int		ft_case12a(char ***str,t_numb *e,va_list ap)
{
	int	cnt;
	int	i;
	char	*s2;
	char	*s3;
	char	*s4;

	cnt = 0;
	e->ull = va_arg(ap, unsigned long long);
	s2 = ft_ltohex3(e->ull);
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
	cnt = cnt + ft_checks(**str,e);
	(**str)++;
	free(s2);
	s2 = NULL;
	ft_initialize(e);
	return (cnt);
}

int		ft_case12b(char ***str,t_numb *e,va_list ap)
{
	int	cnt;
	t_ll	*w;

	cnt = 0;
	w = (t_ll*)malloc(sizeof(t_ll));
	cnt = cnt + ft_checkll(**str,e,ap,w);
	while(w->k > 0)
	{
		(**str)++;
		w->k--;
	}
	free(w);
	w = NULL;
	return (cnt);
}

int		ft_case12c(char ***str,t_numb *e,va_list ap)
{
	int	cnt;
	char	*s2;

	cnt = 0;
	e->uc = va_arg(ap, unsigned char);
	s2 = ft_ltohex8(e->uc);
	ft_putstr(s2);
	cnt = cnt + ft_strlen(s2);
	(**str)++;
	(**str)++;
	free(s2);
	s2 = NULL;
	ft_initialize(e);
	return (cnt);
}

