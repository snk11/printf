/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:37:22 by syusof            #+#    #+#             */
/*   Updated: 2016/03/09 16:04:42 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strlen(const char *str)
{
	size_t		i;

	if (str)
	{
		i = 0;
		while (str[i])
			i++;
		return (i);
	}
	return (0);
}

size_t		ft_strlen2(wchar_t *s)
{
	t_elem	*e;
	int		c1;

	e = (t_elem*)malloc(sizeof(t_elem));
	e->ret = 0;
	while (*s)
	{
		c1 = *s;
		e->c2 = (int)c1;
		if (e->c2 == 32)
		{
			e->ret++;
		}
		else
			e->ret = e->ret + (ft_strlen1(e));
		s++;
	}
	return (e->ret);
}

int	ft_strlen1(t_elem *e)
{
	e->c3 = e->c2;
	e->n = 0;
	e->ret1 = 0;
	while(e->c2 > 0)
		ft_strlen1a(&e);
	if (e->n <=7)
		ft_strlen1b(&e);
	else if (e->n > 7 && e->n <= 11)
		ft_strlen1c(&e);
	else if (e->n > 11 && e->n <= 16)
		ft_strlen1d(&e);
	else
		ft_strlen1e(&e);
	ft_strlen1f(&e);
	ft_strlen1g(&e);
	ft_strlen1h(&e);
	ft_strlen1i(&e);
	ft_strlen1j(&e);
	return (e->ret1);
}


void	ft_strlen1a(t_elem **e)
{
	(*e)->c2 = (*e)->c2 / 2;
	(*e)->n++;
}

void	ft_strlen1b(t_elem **e)
{
	(*e)->str2 = (char*)malloc(sizeof(char)* 8 + 1);
	(*e)->str2[7] = '0';
	(*e)->str2[8] = 0;
	(*e)->n2 = 7;
}

void	ft_strlen1c(t_elem **e)
{
	(*e)->str2 = (char*)malloc(sizeof(char)* 16 + 1);
	(*e)->str2[15] = '1';
	(*e)->str2[14] = '1';
	(*e)->str2[13] = '0';
	(*e)->str2[12] = 0;
	(*e)->str2[11] = 0;
	(*e)->str2[10] = 0;
	(*e)->str2[9] = 0;
	(*e)->str2[8] = 0;
	(*e)->str2[7] = '1';
	(*e)->str2[6] = '0';
	(*e)->str2[5] = 0;
	(*e)->str2[4] = 0;
	(*e)->str2[3] = 0;
	(*e)->str2[2] = 0;
	(*e)->str2[1] = 0;
	(*e)->str2[0] = 0;
	(*e)->str2[16] = 0;
	(*e)->n2 = 15;
}


void	ft_strlen1d(t_elem **e)
{
	(*e)->str2 = (char*)malloc(sizeof(char)* 24 + 1);
	ft_putwchar1d1(&e);
	(*e)->str2[9] = 0;
	(*e)->str2[8] = 0;
	(*e)->str2[7] = '1';
	(*e)->str2[6] = '0';
	(*e)->str2[5] = 0;
	(*e)->str2[4] = 0;
	(*e)->str2[3] = 0;
	(*e)->str2[2] = 0;
	(*e)->str2[1] = 0;
	(*e)->str2[0] = 0;
	(*e)->str2[24] = 0;
	(*e)->n2 = 23;
}

void	ft_strlen1d1(t_elem ***e)
{
	(**e)->str2[23] = '1';
	(**e)->str2[22] = '1';
	(**e)->str2[21] = '1';
	(**e)->str2[20] = '0';
	(**e)->str2[19] = 0;
	(**e)->str2[18] = 0;
	(**e)->str2[17] = 0;
	(**e)->str2[16] = 0;
	(**e)->str2[15] = '1';
	(**e)->str2[14] = '0';
	(**e)->str2[13] = 0;
	(**e)->str2[12] = 0;
	(**e)->str2[11] = 0;
	(**e)->str2[10] = 0;
}

void	ft_strlen1e(t_elem **e)
{
	(*e)->str2 = (char*)malloc(sizeof(char)* 32 + 1);
	ft_putwchar1e1(&e);
	(*e)->str2[11] = 0;
	(*e)->str2[10] = 0;
	(*e)->str2[9] = 0;
	(*e)->str2[8] = 0;
	(*e)->str2[7] = '1';
	(*e)->str2[6] = '0';
	(*e)->str2[5] = 0;
	(*e)->str2[4] = 0;
	(*e)->str2[3] = 0;
	(*e)->str2[2] = 0;
	(*e)->str2[1] = 0;
	(*e)->str2[0] = 0;
	(*e)->str2[32] = 0;
	(*e)->n2 = 31;
}

void	ft_strlen1e1(t_elem ***e)
{
	(**e)->str2[31] = '1';
	(**e)->str2[30] = '1';
	(**e)->str2[29] = '1';
	(**e)->str2[28] = '1';
	(**e)->str2[27] = '0';
	(**e)->str2[26] = 0;
	(**e)->str2[25] = 0;
	(**e)->str2[24] = 0;
	(**e)->str2[23] = '1';
	(**e)->str2[22] = '0';
	(**e)->str2[21] = 0;
	(**e)->str2[20] = 0;
	(**e)->str2[19] = 0;
	(**e)->str2[18] = 0;
	(**e)->str2[17] = 0;
	(**e)->str2[16] = 0;
	(**e)->str2[15] = '1';
	(**e)->str2[14] = '0';
	(**e)->str2[13] = 0;
	(**e)->str2[12] = 0;
}


void	ft_strlen1f(t_elem **e)
{
	(*e)->str = (char*)malloc(sizeof(char)* (*e)->n + 1);
	(*e)->begi = (*e)->str;
	(*e)->c2 = (*e)->c3;
	(*e)->begi2 = (*e)->str2;
	while((*e)->c2 > 0)
	{
		*((*e)->str) = '0' + (*e)->c2 % 2;
		(*e)->c2 = (*e)->c2 / 2;
		(*e)->str++;
	}
	*((*e)->str) = 0;
	(*e)->str = (*e)->begi;
	(*e)->i = 0;
	(*e)->str2 = (*e)->begi2;
}

void	ft_strlen1g(t_elem **e)
{
	while ((*e)->i < ((*e)->n2 + 1))
	{
		if (*((*e)->str2) == 0 && *((*e)->str))
		{
			*((*e)->str2) = *((*e)->str);
			(*e)->str2++;
			(*e)->str++;
		}
		else if (*((*e)->str2) == 0 && *((*e)->str) == 0)
		{
			*((*e)->str2) = '0';
			(*e)->str2++;
		}
		else if (*((*e)->str2) == '1' || *((*e)->str2) == '0')
		{
			(*e)->str2++;
		}
		(*e)->i++;
	}
	(*e)->str = (*e)->begi;
	(*e)->str2 = (*e)->begi2;
	(*e)->i = 0;
}


void	ft_strlen1h(t_elem **e)
{
	while ((*e)->i <= (*e)->n2)
	{
		if (*((*e)->str2) == 0)
			*((*e)->str2) = '0';
		(*e)->str2++;
		(*e)->i++;
	}
	(*e)->i = 0;
	(*e)->str2--;
	(*e)->r = (int*)malloc(sizeof(int)*((*e)->n2+1)/8 + 1);
	(*e)->i = 0;
	while ((*e)->i <= ((*e)->n2 + 1)/8)
	{
		(*e)->r[(*e)->i] = 0;
		(*e)->i++;
	}
	(*e)->i = 0;
}

void	ft_strlen1i(t_elem **e)
{
	while ((*e)->i < ((*e)->n2 + 1) / 8)
	{
		(*e)->j = 7;
		while ( (*e)->j >= 0 )
		{
			(*e)->r[(*e)->i] = (*e)->r[(*e)->i] + (*((*e)->str2) - '0') * pow(2,(*e)->j);
			(*e)->j--;
			(*e)->str2--;
		}
		(*e)->i++;
	}
	(*e)->str2 = (*e)->begi2;
	(*e)->str = (*e)->begi;
	(*e)->i = 0;
}

void	ft_strlen1j(t_elem **e)
{
	while((*e)->i < ((*e)->n2 + 1)/8)
	{
		(*e)->i++;
	}
	(*e)->ret1 = (*e)->ret1 + ((*e)->n2 + 1) / 8;
	free((*e)->str2);
	(*e)->str2 = NULL;
	(*e)->begi2 = NULL;
	free((*e)->str);
	(*e)->str = NULL;
	(*e)->begi = NULL;
	free((*e)->r);
	(*e)->r = NULL;
}

