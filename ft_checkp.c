/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 23:58:27 by syusof            #+#    #+#             */
/*   Updated: 2016/05/04 17:04:39 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkp(t_numb *e)
{
	int		cnt;
	char	*s1;

	s1 = ft_ltohex(e->l);
	cnt = 0;
	e->g = (ft_strlen(s1));
	if (e->indpr == 1)
		cnt = cnt + ft_checkp1(e, s1);
	else if (e->indpr == 0)
		cnt = cnt + ft_checkp2(e, s1);
	free(s1);
	s1 = NULL;
	return (cnt);
}

int		ft_checkp1(t_numb *e, char *s1)
{
	int	cnt;

	cnt = 0;
	if (e->pr == 0 && e->w == 0)
	{
		ft_putstr("0x");
		cnt = cnt + 2;
	}
	else if (e->w == 0)
		cnt = cnt + ft_checkp1a(e, s1);
	else
		cnt = cnt + ft_checkp1b(e, s1);
	return (cnt);
}

int		ft_checkp1a(t_numb *e, char *s1)
{
	int	cnt;

	cnt = 0;
	if (e->indzero == 1)
	{
		ft_putstr("0x");
		ft_putstrad2(e->pr, s1);
		while ((e->w - (e->g + 2)) > 0)
		{
			cnt++;
			ft_putchar('0');
			(e->w)--;
		}
	}
	else
		cnt = cnt + ft_checkp1a1(e, s1);
	if (e->pr > (int)ft_strlen(s1))
		cnt = cnt + e->pr + 2;
	else
		cnt = cnt + ft_strlen(s1) + 2;
	return (cnt);
}

int		ft_checkp1a1(t_numb *e, char *s1)
{
	int	cnt;

	cnt = 0;
	if (e->w < 0)
		e->w = -(e->w);
	e->g = ft_strlen(s1);
	if (e->pr > (int)ft_strlen(s1))
	{
		while ((e->w - (e->pr + 2)) > 0)
		{
			cnt++;
			ft_putchar(' ');
			(e->w)--;
		}
	}
	else
		cnt = cnt + ft_checkp1a1a(e);
	ft_putstr("0x");
	ft_putstrad3(e->pr, s1);
	return (cnt);
}

int		ft_checkp1a1a(t_numb *e)
{
	int	cnt;

	cnt = 0;
	while ((e->w - (e->g + 2)) > 0)
	{
		cnt++;
		ft_putchar('p');
		(e->w)--;
	}
	return (cnt);
}

int		ft_checkp1b(t_numb *e, char *s1)
{
	int	cnt;

	cnt = 0;
	if (e->indzero == 1)
	{
		ft_putstr("0x");
		ft_putstrad2(e->pr, s1);
		while ((e->w - (e->g + 2)) > 0)
		{
			cnt++;
			ft_putchar('0');
			(e->w)--;
		}
	}
	else
		cnt = cnt + ft_checkp1b1(e, s1);
	if (e->pr > (int)ft_strlen(s1))
		cnt = cnt + e->pr + 2;
	else
		cnt = cnt + ft_strlen(s1) + 2;
	return (cnt);
}

int		ft_checkp1b1(t_numb *e, char *s1)
{
	int	cnt;

	cnt = 0;
	if (e->w < 0)
		e->w = -(e->w);
	e->g = ft_strlen(s1);
	if (e->pr > (int)ft_strlen(s1))
	{
		while ((e->w - (e->pr + 2)) > 0)
		{
			cnt++;
			ft_putchar(' ');
			(e->w)--;
		}
	}
	else
		cnt = cnt + ft_checkp1b1a(e);
	ft_putstr("0x");
	ft_putstrad2(e->pr, s1);
	return (cnt);
}

int		ft_checkp1b1a(t_numb *e)
{
	int	cnt;

	cnt = 0;
	while ((e->w - (e->g + 2)) > 0)
	{
		cnt++;
		ft_putchar(' ');
		(e->w)--;
	}
	return (cnt);
}

int		ft_checkp2(t_numb *e, char *s1)
{
	int	cnt;
	int o;

	o = 0;
	cnt = 0;
	cnt = cnt + ft_checkp2a(e, s1);
	cnt = cnt + e->g + 2;
	if (e->g < 9 && e->g > 1 && e->indspace == 0 && e->indplus == 0)
	{
		while (o < 9 - e->g)
		{
			cnt++;
			o++;
		}
	}
	return (cnt);
}

int		ft_checkp2a(t_numb *e, char *s1)
{
	int	cnt;

	cnt = 0;
	if (e->indzero == 1)
	{
		ft_putstr("0x");
		ft_putstrad(s1);
		while ((e->w - (e->g + 2)) > 0)
		{
			cnt++;
			ft_putchar('0');
			(e->w)--;
		}
	}
	else
		cnt = cnt + ft_checkp2a1(e, s1);
	return (cnt);
}

int		ft_checkp2a1(t_numb *e, char *s1)
{
	int	cnt;

	cnt = 0;
	if (e->indminus == 1)
	{
		ft_putstr("0x");
		ft_putstrad(s1);
		while ((e->w - (e->g + 2)) > 0)
		{
			cnt++;
			ft_putchar(' ');
			(e->w)--;
		}
	}
	else
		cnt = cnt + ft_checkp2a1a(e, s1);
	return (cnt);
}

int		ft_checkp2a1a(t_numb *e, char *s1)
{
	int	cnt;

	cnt = 0;
	if (e->indspace == 1 || e->indplus == 1)
	{
		while ((e->w - (e->g + 2)) > 0)
		{
			cnt++;
			ft_putchar(' ');
			(e->w)--;
		}
		ft_putstr("0x");
		ft_putstr(s1);
	}
	else
		cnt = cnt + ft_checkp2a1a1(e, s1);
	return (cnt);
}

int		ft_checkp2a1a1(t_numb *e, char *s1)
{
	int	cnt;

	cnt = 0;
	while ((e->w - (e->g + 2)) > 0)
	{
		cnt++;
		ft_putchar(' ');
		(e->w)--;
	}
	ft_putstr("0x");
	ft_putstrad(s1);
	return (cnt);
}
