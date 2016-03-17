/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 15:13:21 by syusof            #+#    #+#             */
/*   Updated: 2016/03/17 18:50:27 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_countwstr(int pr,wchar_t *s)
{
	t_elem	*e;
	int		c1;
	int		r1;

	e = (t_elem*)malloc(sizeof(t_elem));
	e->prbegi = pr;
	e->ret = 0;
	e->pr1 = pr;
	while (*s)
	{
		c1 = *s;
		e->c2 = (int)c1;
		if (e->c2 <= 127 && e->pr1 > 0)
		{
			e->ret++;
			e->pr1--;
		}
		else
			ft_countwstr1(e);
		s++;
	}
	r1 = e->ret;
	free(e);
	e = NULL;
	return (r1);
}

void	ft_countwstr1(t_elem *e)
{
	e->c3 = e->c2;
	e->n = 0;
	while(e->c2 > 0)
		ft_countwstr1a(e);
	if (e->n <=7)
		ft_countwstr1b(e);
	else if (e->n > 7 && e->n <= 11)
		ft_countwstr1c(e);
	else if (e->n > 11 && e->n <= 16)
		ft_countwstr1d(e);
	else
		ft_countwstr1e(e);
	ft_countwstr1f(e);
	ft_countwstr1g(e);
	ft_countwstr1h(e);
	ft_countwstr1i(e);
	ft_countwstr1j(e);
}


void	ft_countwstr1a(t_elem *e)
{
	e->c2 = e->c2 / 2;
	e->n++;
}

void	ft_countwstr1b(t_elem *e)
{
	e->str2 = (char*)malloc(sizeof(char)* 8 + 1);
	e->str2[7] = '0';
	e->str2[8] = 0;
	e->n2 = 7;
}

void	ft_countwstr1c(t_elem *e)
{
	e->str2 = (char*)malloc(sizeof(char)* 16 + 1);
	e->str2[15] = '1';
	e->str2[14] = '1';
	e->str2[13] = '0';
	e->str2[12] = 0;
	e->str2[11] = 0;
	e->str2[10] = 0;
	e->str2[9] = 0;
	e->str2[8] = 0;
	e->str2[7] = '1';
	e->str2[6] = '0';
	e->str2[5] = 0;
	e->str2[4] = 0;
	e->str2[3] = 0;
	e->str2[2] = 0;
	e->str2[1] = 0;
	e->str2[0] = 0;
	e->str2[16] = 0;
	e->n2 = 15;
}


void	ft_countwstr1d(t_elem *e)
{
	e->str2 = (char*)malloc(sizeof(char)* 24 + 1);
	ft_putwstr1d1(e);
	e->str2[9] = 0;
	e->str2[8] = 0;
	e->str2[7] = '1';
	e->str2[6] = '0';
	e->str2[5] = 0;
	e->str2[4] = 0;
	e->str2[3] = 0;
	e->str2[2] = 0;
	e->str2[1] = 0;
	e->str2[0] = 0;
	e->str2[24] = 0;
	e->n2 = 23;
}

void	ft_countwstr1d1(t_elem *e)
{
	e->str2[23] = '1';
	e->str2[22] = '1';
	e->str2[21] = '1';
	e->str2[20] = '0';
	e->str2[19] = 0;
	e->str2[18] = 0;
	e->str2[17] = 0;
	e->str2[16] = 0;
	e->str2[15] = '1';
	e->str2[14] = '0';
	e->str2[13] = 0;
	e->str2[12] = 0;
	e->str2[11] = 0;
	e->str2[10] = 0;
}

void	ft_countwstr1e(t_elem *e)
{
	e->str2 = (char*)malloc(sizeof(char)* 32 + 1);
	ft_putwstr1e1(e);
	e->str2[11] = 0;
	e->str2[10] = 0;
	e->str2[9] = 0;
	e->str2[8] = 0;
	e->str2[7] = '1';
	e->str2[6] = '0';
	e->str2[5] = 0;
	e->str2[4] = 0;
	e->str2[3] = 0;
	e->str2[2] = 0;
	e->str2[1] = 0;
	e->str2[0] = 0;
	e->str2[32] = 0;
	e->n2 = 31;
}

void	ft_countwstr1e1(t_elem *e)
{
	e->str2[31] = '1';
	e->str2[30] = '1';
	e->str2[29] = '1';
	e->str2[28] = '1';
	e->str2[27] = '0';
	e->str2[26] = 0;
	e->str2[25] = 0;
	e->str2[24] = 0;
	e->str2[23] = '1';
	e->str2[22] = '0';
	e->str2[21] = 0;
	e->str2[20] = 0;
	e->str2[19] = 0;
	e->str2[18] = 0;
	e->str2[17] = 0;
	e->str2[16] = 0;
	e->str2[15] = '1';
	e->str2[14] = '0';
	e->str2[13] = 0;
	e->str2[12] = 0;
}


void	ft_countwstr1f(t_elem *e)
{
	e->str = (char*)malloc(sizeof(char)* e->n + 1);
	e->begi = e->str;
	e->c2 = e->c3;
	e->begi2 = e->str2;
	while(e->c2 > 0)
	{
		*(e->str) = '0' + e->c2 % 2;
		e->c2 = e->c2 / 2;
		e->str++;
	}
	*(e->str) = 0;
	e->str = e->begi;
	e->i = 0;
	e->str2 = e->begi2;
}

void	ft_countwstr1g(t_elem *e)
{
	while (e->i < (e->n2 + 1))
	{
		if (*(e->str2) == 0 && *(e->str))
		{
			*(e->str2) = *(e->str);
			e->str2++;
			e->str++;
		}
		else if (*(e->str2) == 0 && *(e->str) == 0)
		{
			*(e->str2) = '0';
			e->str2++;
		}
		else if (*(e->str2) == '1' || *(e->str2) == '0')
		{
			e->str2++;
		}
		e->i++;
	}
	e->str = e->begi;
	e->str2 = e->begi2;
	e->i = 0;
}


void	ft_countwstr1h(t_elem *e)
{
	while (e->i <= e->n2)
	{
		if (*(e->str2) == 0)
			*(e->str2) = '0';
		e->str2++;
		e->i++;
	}
	e->i = 0;
	e->str2--;
	e->r = (int*)malloc(sizeof(int)*(e->n2+1)/8 + 1);
	e->i = 0;
	while (e->i <= (e->n2 + 1)/8)
	{
		e->r[e->i] = 0;
		e->i++;
	}
	e->i = 0;
}

void	ft_countwstr1i(t_elem *e)
{
	while (e->i < (e->n2 + 1) / 8)
	{
		e->j = 7;
		while ( e->j >= 0 )
		{
			e->r[e->i] = e->r[e->i] + (*(e->str2) - '0') * pow(2,e->j);
			e->j--;
			e->str2--;
		}
		e->i++;
	}
	e->str2 = e->begi2;
	e->str = e->begi;
	e->i = 0;
}

void	ft_countwstr1j(t_elem *e)
{
	if ((e->n2 + 1) / 8 <= e->pr1)
	{
		while(e->i < (e->n2 + 1)/8)
		{
			e->i++;
		}
		e->pr1 = e->pr1 - (e->n2 + 1) / 8;
	}
	e->ret = e->prbegi - e->pr1;
	free(e->str2);
	e->str2 = NULL;
	free(e->str);
	e->str = NULL;
	free(e->r);
	e->r = NULL;
}

