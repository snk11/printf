/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkbs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 20:30:16 by syusof            #+#    #+#             */
/*   Updated: 2016/04/26 16:06:37 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkbs(char *str, t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->ss)
		e->g = ft_strlen2(e->ss);
	if (!(e->ss))
		e->g = 6;
	if (e->indpr == 1)
		cnt = cnt + ft_checkbs1(str, e);
	else
		cnt = cnt + ft_checkbs2(str, e);
	return (cnt);
}

int		ft_checkbs1(char *str, t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indminus == 1 && e->pr > 0 && e->w == 0)
		return (0);
	else if (e->indminus == 1 && e->w > 0)
	{
		while (e->w)
		{
			ft_putchar(' ');
			e->w--;
			cnt++;
		}
	}
	else if (e->pr > e->w)
		cnt = cnt + ft_checkbs1a(str, e);
	else if (e->w > e->pr)
		cnt = cnt + ft_checkbs1b(str, e);
	return (cnt);
}

int		ft_checkbs1a(char *str, t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indzero == 0)
		cnt = cnt + ft_checkbs1a1(str, e);
	else
		cnt = cnt + ft_checkbs1a2(str, e);
	return (cnt);
}

int		ft_checkbs1a1(char *str, t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indminus == 1)
		cnt = cnt + ft_checkbs1a1a(str, e);
	else
		cnt = cnt + ft_checkbs1a1b(str, e);
	return (cnt);
}

int		ft_checkbs1a1a(char *str, t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->ss)
	{
		cnt = cnt + ft_putwstr(e->ss);
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	while ((e->w - e->g) > 0)
	{
		cnt++;
		ft_putchar(' ');
		(e->w)--;
	}
	return (cnt);
}

int		ft_checkbs1a1b(char *str, t_numb *e)
{
	int	cnt;

	cnt = 0;
	while ((e->w - e->g) > 0)
	{
		cnt++;
		ft_putchar(' ');
		(e->w)--;
	}
	if (e->ss)
	{
		cnt = cnt + ft_putwstr2(e->pr, e->ss);
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	return (cnt);
}

int		ft_checkbs1a2(char *str, t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indminus == 1)
		cnt = cnt + ft_checkbs1a2a(str, e);
	else
		cnt = cnt + ft_checkbs1a2b(str, e);
	return (cnt);
}

int		ft_checkbs1a2a(char *str, t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->ss)
	{
		cnt = cnt + ft_putwstr(e->ss);
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	while ((e->w - e->g) > 0)
	{
		cnt++;
		ft_putchar('0');
		(e->w)--;
	}
	return (cnt);
}

int		ft_checkbs1a2b(char *str, t_numb *e)
{
	int	cnt;

	cnt = 0;
	while ((e->w - e->g) > 0)
	{
		cnt++;
		ft_putchar('0');
		(e->w)--;
	}
	if (e->ss)
	{
		cnt = cnt + ft_putwstr(e->ss);
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	return (cnt);
}

int		ft_checkbs1b(char *str, t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indzero == 0)
		cnt = cnt + ft_checkbs1b1(str, e);
	else
		cnt = cnt + ft_checkbs1b2(str, e);
	return (cnt);
}

int		ft_checkbs1b1(char *str, t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indminus == 1)
		cnt = cnt + ft_checkbs1b1a(str, e);
	else
		cnt = cnt + ft_checkbs1b1b(str, e);
	return (cnt);
}

int		ft_checkbs1b1a(char *str, t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->ss)
	{
		cnt = cnt + ft_putwstr(e->ss);
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	while ((e->w - e->g) > 0)
	{
		cnt++;
		ft_putchar('0');
		(e->w)--;
	}
	return (cnt);
}

int		ft_checkbs1b1b(char *str, t_numb *e)
{
	int	cnt;

	cnt = 0;
	while ((e->w - ft_countwstr(e->pr, e->ss)) > 0)
	{
		cnt++;
		ft_putchar(' ');
		(e->w)--;
	}
	if (e->ss)
	{
		cnt = cnt + ft_putwstr2(e->pr, e->ss);
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	return (cnt);
}

int		ft_checkbs1b2(char *str, t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indminus == 1)
		cnt = cnt + ft_checkbs1b2a(str, e);
	else
		cnt = cnt + ft_checkbs1b2b(str, e);
	return (cnt);
}

int		ft_checkbs1b2a(char *str, t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->ss)
	{
		cnt = cnt + ft_putwstr(e->ss);
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	while ((e->w - e->g) > 0)
	{
		cnt++;
		ft_putchar('0');
		(e->w)--;
	}
	return (cnt);
}

int		ft_checkbs1b2b(char *str, t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->w > e->g)
		cnt = cnt + ft_checkbs1b2b1(str, e);
	else
	{
		while (e->w > 0)
		{
			cnt++;
			ft_putchar('0');
			(e->w)--;
		}
	}
	return (cnt);
}

int		ft_checkbs1b2b1(char *str, t_numb *e)
{
	int	cnt;

	cnt = 0;
	while (e->w - e->g > 0)
	{
		cnt++;
		ft_putchar('0');
		(e->w)--;
	}
	if (e->ss)
	{
		cnt = cnt + ft_putwstr(e->ss);
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	return (cnt);
}

int		ft_checkbs2(char *str, t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indzero == 0)
		cnt = cnt + ft_checkbs2a(str, e);
	else
		cnt = cnt + ft_checkbs2b(str, e);
	return (cnt);
}

int		ft_checkbs2a(char *str, t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indminus == 1)
		cnt = cnt + ft_checkbs2a1(str, e);
	else
		cnt = cnt + ft_checkbs2a2(str, e);
	return (cnt);
}

int		ft_checkbs2a1(char *str, t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->ss)
	{
		cnt = cnt + ft_putwstr(e->ss);
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	while ((e->w - e->g) > 0)
	{
		cnt++;
		ft_putchar(' ');
		(e->w)--;
	}
	return (cnt);
}

int		ft_checkbs2a2(char *str, t_numb *e)
{
	int	cnt;

	cnt = 0;
	while ((e->w - e->g) > 0)
	{
		cnt++;
		ft_putchar(' ');
		(e->w)--;
	}
	if (e->ss)
	{
		cnt = cnt + ft_putwstr(e->ss);
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	return (cnt);
}

int		ft_checkbs2b(char *str, t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indminus == 1)
		cnt = cnt + ft_checkbs2b1(str, e);
	else
		cnt = cnt + ft_checkbs2b2(str, e);
	return (cnt);
}

int		ft_checkbs2b1(char *str, t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->ss)
	{
		cnt = cnt + ft_putwstr(e->ss);
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	while ((e->w - e->g) > 0)
	{
		cnt++;
		ft_putchar(' ');
		(e->w)--;
	}
	return (cnt);
}

int		ft_checkbs2b2(char *str, t_numb *e)
{
	int	cnt;

	cnt = 0;
	while ((e->w - e->g) > 0)
	{
		cnt++;
		ft_putchar('0');
		(e->w)--;
	}
	if (e->ss)
	{
		cnt = cnt + ft_putwstr(e->ss);
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	return (cnt);
}
