/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 01:26:49 by syusof            #+#    #+#             */
/*   Updated: 2016/05/04 18:05:01 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checks(t_numb *e)
{
	int	cnt;

	cnt = 0;
	e->prbegi = e->pr;
	if (e->indminus == 0)
	{
		if (e->s)
			cnt = cnt + ft_checks52a(e);
		else
			cnt = cnt + ft_checks2(e);
		return (cnt);
	}
	else if (e->indminus == 1)
	{
		if (e->s)
			cnt = cnt + ft_checks52b(e);
		else
			cnt = cnt + ft_checks22(e);
		return (cnt);
	}
	return (0);
}

int		ft_checks52a(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indpr == 1)
		cnt = cnt + ft_checks1(e);
	else
		cnt = cnt + ft_checks42(e);
	return (cnt);
}

int		ft_checks52b(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indpr == 1)
		cnt = cnt + ft_checks21(e);
	else
		cnt = cnt + ft_checks242(e);
	return (cnt);
}

int		ft_checks242(t_numb *e)
{
	int	cnt;

	cnt = 0;
	cnt = cnt + ft_checks242a(e);
	cnt = cnt + ft_checks242b(e);
	return (cnt);
}

int		ft_checks242a(t_numb *e)
{
	int	cnt;
	int	i;

	cnt = 0;
	e->g = ft_strlen(e->s);
	if (e->s)
	{
		ft_putstr(e->s);
		i = 0;
		while (i < e->g)
		{
			cnt++;
			i++;
		}
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	return (cnt);
}

int		ft_checks242b(t_numb *e)
{
	int	cnt;

	cnt = 0;
	e->g = ft_strlen(e->s);
	while (e->w - e->g > 0)
	{
		cnt++;
		ft_putchar(' ');
		(e->w)--;
	}
	return (cnt);
}

int		ft_checks42(t_numb *e)
{
	int	cnt;

	cnt = 0;
	cnt = cnt + ft_checks42a(e);
	cnt = cnt + ft_checks42b(e);
	return (cnt);
}

int		ft_checks42a(t_numb *e)
{
	int	cnt;

	cnt = 0;
	e->g = ft_strlen(e->s);
	if (e->indzero == 0)
	{
		while (e->w - e->g > 0)
		{
			cnt++;
			ft_putchar(' ');
			(e->w)--;
		}
	}
	else
	{
		while (e->w - e->g > 0)
		{
			cnt++;
			ft_putchar('0');
			(e->w)--;
		}
	}
	return (cnt);
}

int		ft_checks42b(t_numb *e)
{
	int	cnt;
	int	i;

	cnt = 0;
	e->g = ft_strlen(e->s);
	if (e->s)
	{
		ft_putstr(e->s);
		i = 0;
		while (i < e->g)
		{
			cnt++;
			i++;
		}
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	return (cnt);
}

int		ft_checks1(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->pr > e->w)
		cnt = cnt + ft_checks1a(e);
	else if (e->w > e->pr)
		cnt = cnt + ft_checks1b(e);
	return (cnt);
}

int		ft_checks1a(t_numb *e)
{
	int cnt;
	int	i;

	e->g = ft_strlen(e->s);
	cnt = 0;
	cnt = cnt + ft_checks1a1(e);
	if (e->s)
	{
		ft_putstr2(e->pr, e->s);
		i = 0;
		e->pr = e->prbegi;
		while (i < e->g && e->pr > 0)
		{
			cnt++;
			i++;
			(e->pr)--;
		}
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	return (cnt);
}

int		ft_checks1a1(t_numb *e)
{
	int cnt;

	cnt = 0;
	e->g = ft_strlen(e->s);
	if (e->indzero == 0)
	{
		while (e->w - e->g > 0 && e->pr > 0)
		{
			cnt++;
			ft_putchar(' ');
			ft_decr(e);
		}
	}
	else
	{
		while (e->w - e->g > 0 && e->pr > 0)
		{
			cnt++;
			ft_putchar('0');
			ft_decr(e);
		}
	}
	return (cnt);
}

void	ft_decr(t_numb *e)
{
	(e->w)--;
	(e->pr)--;
}

int		ft_checks1b(t_numb *e)
{
	int	cnt;

	cnt = 0;
	e->g = ft_strlen(e->s);
	if (e->g > e->pr)
		cnt = cnt + ft_checks1b1(e);
	else if (e->g < e->pr)
		cnt = cnt + ft_checks1b2(e);
	return (cnt);
}

int		ft_checks1b1(t_numb *e)
{
	int	cnt;
	int	i;

	cnt = 0;
	cnt = cnt + ft_checks1b1a(e);
	if (e->s)
	{
		ft_putstr2(e->pr, e->s);
		i = 0;
		while (e->pr > 0)
		{
			cnt++;
			(e->pr)--;
		}
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	return (cnt);
}

int		ft_checks1b1a(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indzero == 0)
	{
		while ((e->w - e->pr) > 0)
		{
			cnt++;
			ft_putchar(' ');
			(e->w)--;
		}
	}
	else
	{
		while ((e->w - e->pr) > 0)
		{
			cnt++;
			ft_putchar('0');
			(e->w)--;
		}
	}
	return (cnt);
}

int		ft_checks1b2(t_numb *e)
{
	int	cnt;
	int	i;

	cnt = 0;
	e->g = ft_strlen(e->s);
	cnt = cnt + ft_checks1b2a(e);
	if (e->s)
	{
		ft_putstr(e->s);
		i = 0;
		while (i < e->g)
		{
			cnt++;
			i++;
		}
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	return (cnt);
}

int		ft_checks1b2a(t_numb *e)
{
	int	cnt;

	cnt = 0;
	e->g = ft_strlen(e->s);
	if (e->indzero == 0)
	{
		while (e->w - e->g > 0)
		{
			cnt++;
			ft_putchar(' ');
			(e->w)--;
		}
	}
	else
	{
		while (e->w - e->g > 0)
		{
			cnt++;
			ft_putchar('0');
			(e->w)--;
		}
	}
	return (cnt);
}

int		ft_checks2(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->pr > 6)
		e->pr = 6;
	if (e->w == 0 && e->pr == 0 && e->indpr == 0)
		cnt = cnt + ft_checks2a(e);
	else if (e->indpr == 1)
		cnt = cnt + ft_checks2b(e);
	else if (e->indpr == 0)
		cnt = cnt + ft_checks2c(e);
	return (cnt);
}

int		ft_checks2a(void)
{
	int		cnt;
	int		i;
	char	sn[7];

	ft_fullsn(sn);
	cnt = 0;
	i = 0;
	while (i < 6)
	{
		ft_putchar(sn[i]);
		cnt++;
		i++;
	}
	return (cnt);
}

void	ft_fullsn(char *sn)
{
	sn[0] = '(';
	sn[1] = 'n';
	sn[2] = 'u';
	sn[3] = 'l';
	sn[4] = 'l';
	sn[5] = ')';
	sn[6] = 0;
}

int		ft_checks2b(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indminus == 1)
		cnt = cnt + ft_checks2b1(e);
	else if (e->indminus == 0)
		cnt = cnt + ft_checks2b2(e);
	return (cnt);
}

int		ft_checks2b1(t_numb *e)
{
	int		cnt;
	int		i;
	char	sn[7];

	ft_fullsn(sn);
	cnt = 0;
	if (e->pr > 0)
	{
		e->prbegi = e->pr;
		i = 0;
		while (i < 6 && e->pr > 0)
		{
			ft_putchar(sn[i]);
			cnt++;
			i++;
			(e->pr)--;
		}
		e->pr = e->prbegi;
	}
	cnt = cnt + ft_checks2b1a(e);
	return (cnt);
}

int		ft_checks2b1a(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->w > 6)
	{
		if (e->indzero == 1)
		{
			while ((e->w - e->pr) > 0)
			{
				cnt++;
				ft_putchar('0');
				(e->w)--;
			}
		}
		else
		{
			while ((e->w - e->pr) > 0)
			{
				cnt++;
				ft_putchar(' ');
				(e->w)--;
			}
		}
	}
	return (cnt);
}

int		ft_checks2b2(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indzero == 1)
		cnt = cnt + ft_checks2b2a(e);
	else
		cnt = cnt + ft_checks2b2b(e);
	return (cnt);
}

int		ft_checks2b2a(t_numb *e)
{
	int		cnt;
	int		i;
	char	sn[7];

	ft_fullsn(sn);
	cnt = 0;
	while ((e->w - e->pr) > 0)
	{
		cnt++;
		ft_putchar('0');
		(e->w)--;
	}
	i = 0;
	while (e->pr > 0)
	{
		ft_putchar(sn[i]);
		cnt++;
		i++;
		(e->pr)--;
	}
	return (cnt);
}

int		ft_checks2b2b(t_numb *e)
{
	int		cnt;
	int		i;
	char	sn[7];

	ft_fullsn(sn);
	cnt = 0;
	while ((e->w - e->pr) > 0)
	{
		cnt++;
		ft_putchar(' ');
		(e->w)--;
	}
	i = 0;
	while (e->pr > 0)
	{
		ft_putchar(sn[i]);
		cnt++;
		i++;
		(e->pr)--;
	}
	return (cnt);
}

int		ft_checks2c(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indminus == 1)
		cnt = cnt + ft_checks2c1(e);
	else if (e->indminus == 0)
		cnt = cnt + ft_checks2c2(e);
	return (cnt);
}

int		ft_checks2c1(t_numb *e)
{
	int		cnt;
	int		i;
	char	sn[7];

	ft_fullsn(sn);
	cnt = 0;
	i = 0;
	while (i < 6)
	{
		ft_putchar(sn[i]);
		cnt++;
		i++;
	}
	if (e->w > 6)
		cnt = cnt + ft_checks2c1a(e);
	return (cnt);
}

int		ft_checks2c1a(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indzero == 1)
	{
		while ((e->w - e->pr) > 0)
		{
			cnt++;
			ft_putchar('0');
			(e->w)--;
		}
	}
	else
	{
		while ((e->w - e->pr) > 0)
		{
			cnt++;
			ft_putchar(' ');
			(e->w)--;
		}
	}
	return (cnt);
}

int		ft_checks2c2(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indzero == 1)
		cnt = cnt + ft_checks2c2a(e);
	else
		cnt = cnt + ft_checks2c2b(e);
	return (cnt);
}

int		ft_checks2c2a(t_numb *e)
{
	int		cnt;
	int		i;
	char	sn[7];

	ft_fullsn(sn);
	cnt = 0;
	while ((e->w - e->pr) > 0)
	{
		cnt++;
		ft_putchar('0');
		(e->w)--;
	}
	i = 0;
	while (e->pr > 0)
	{
		ft_putchar(sn[i]);
		cnt++;
		i++;
		(e->pr)--;
	}
	return (cnt);
}

int		ft_checks2c2b(t_numb *e)
{
	int		cnt;
	int		i;
	char	sn[7];

	ft_fullsn(sn);
	cnt = 0;
	while ((e->w - e->pr) > 0)
	{
		cnt++;
		ft_putchar(' ');
		(e->w)--;
	}
	i = 0;
	while (e->pr > 0)
	{
		ft_putchar(sn[i]);
		cnt++;
		i++;
		(e->pr)--;
	}
	return (cnt);
}

int		ft_checks21(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->pr > e->w)
		cnt = cnt + ft_checks21a(e);
	else if (e->w > e->pr)
		cnt = cnt + ft_checks21b(e);
	return (cnt);
}

int		ft_checks21a(t_numb *e)
{
	int cnt;
	int	i;

	e->g = ft_strlen(e->s);
	cnt = 0;
	if (e->s)
	{
		ft_putstr2(e->pr, e->s);
		i = 0;
		e->pr = e->prbegi;
		while (i < e->g && e->pr > 0)
		{
			cnt++;
			i++;
			(e->pr)--;
		}
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	cnt = cnt + ft_checks21a1(e);
	return (cnt);
}

int		ft_checks21a1(t_numb *e)
{
	int cnt;

	cnt = 0;
	e->g = ft_strlen(e->s);
	if (e->indzero == 0)
	{
		while (e->w - e->g > 0 && e->pr > 0)
		{
			cnt++;
			ft_putchar(' ');
			ft_decr(e);
		}
	}
	else
	{
		while (e->w - e->g > 0 && e->pr > 0)
		{
			cnt++;
			ft_putchar('0');
			ft_decr(e);
		}
	}
	return (cnt);
}

int		ft_checks21b(t_numb *e)
{
	int	cnt;

	cnt = 0;
	e->g = ft_strlen(e->s);
	if (e->g > e->pr)
		cnt = cnt + ft_checks21b1(e);
	else if (e->g < e->pr)
		cnt = cnt + ft_checks21b2(e);
	return (cnt);
}

int		ft_checks21b1(t_numb *e)
{
	int	cnt;
	int	i;

	cnt = 0;
	if (e->s)
	{
		ft_putstr2(e->pr, e->s);
		i = 0;
		while (i < e->pr)
		{
			cnt++;
			i++;
		}
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	cnt = cnt + ft_checks21b1a(e);
	return (cnt);
}

int		ft_checks21b1a(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indzero == 0)
	{
		while ((e->w - e->pr) > 0)
		{
			cnt++;
			ft_putchar(' ');
			(e->w)--;
		}
	}
	else
	{
		while ((e->w - e->pr) > 0)
		{
			cnt++;
			ft_putchar('0');
			(e->w)--;
		}
	}
	return (cnt);
}

int		ft_checks21b2(t_numb *e)
{
	int	cnt;
	int	i;

	cnt = 0;
	e->g = ft_strlen(e->s);
	if (e->s)
	{
		ft_putstr(e->s);
		i = 0;
		while (i < e->g)
		{
			cnt++;
			i++;
		}
	}
	else
	{
		ft_putstr("(null)");
		cnt = cnt + 6;
	}
	cnt = cnt + ft_checks21b2a(e);
	return (cnt);
}

int		ft_checks21b2a(t_numb *e)
{
	int	cnt;

	cnt = 0;
	e->g = ft_strlen(e->s);
	if (e->indzero == 0)
	{
		while (e->w - e->g > 0)
		{
			cnt++;
			ft_putchar(' ');
			(e->w)--;
		}
	}
	else
	{
		while (e->w - e->g > 0)
		{
			cnt++;
			ft_putchar('0');
			(e->w)--;
		}
	}
	return (cnt);
}

int		ft_checks22(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->pr > 6)
		e->pr = 6;
	if (e->w == 0 && e->pr == 0 && e->indpr == 0)
		cnt = cnt + ft_checks22a(e);
	else if (e->indpr == 1)
		cnt = cnt + ft_checks22b(e);
	else if (e->indpr == 0)
		cnt = cnt + ft_checks22c(e);
	return (cnt);
}

int		ft_checks22a(void)
{
	int		cnt;
	int		i;
	char	sn[7];

	ft_fullsn(sn);
	cnt = 0;
	i = 0;
	while (i < 6)
	{
		ft_putchar(sn[i]);
		cnt++;
		i++;
	}
	return (cnt);
}

int		ft_checks22b(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indminus == 1)
		cnt = cnt + ft_checks22b1(e);
	else if (e->indminus == 0)
		cnt = cnt + ft_checks22b2(e);
	return (cnt);
}

int		ft_checks22b1(t_numb *e)
{
	int		cnt;
	int		i;
	char	sn[7];

	ft_fullsn(sn);
	cnt = 0;
	if (e->pr > 0)
	{
		e->prbegi = e->pr;
		i = 0;
		while (i < 6 && e->pr > 0)
		{
			ft_putchar(sn[i]);
			cnt++;
			i++;
			(e->pr)--;
		}
		e->pr = e->prbegi;
	}
	cnt = cnt + ft_checks22b1a(e);
	return (cnt);
}

int		ft_checks22b1a(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->w > 6)
	{
		if (e->indzero == 1)
		{
			while ((e->w - e->pr) > 0)
			{
				cnt++;
				ft_putchar('0');
				(e->w)--;
			}
		}
		else
		{
			while ((e->w - e->pr) > 0)
			{
				cnt++;
				ft_putchar(' ');
				(e->w)--;
			}
		}
	}
	return (cnt);
}

int		ft_checks22b2(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indzero == 1)
		cnt = cnt + ft_checks22b2a(e);
	else
		cnt = cnt + ft_checks22b2b(e);
	return (cnt);
}

int		ft_checks22b2a(t_numb *e)
{
	int		cnt;
	int		i;
	char	sn[7];

	ft_fullsn(sn);
	cnt = 0;
	while ((e->w - e->pr) > 0)
	{
		cnt++;
		ft_putchar('0');
		(e->w)--;
	}
	i = 0;
	while (e->pr > 0)
	{
		ft_putchar(sn[i]);
		cnt++;
		i++;
		(e->pr)--;
	}
	return (cnt);
}

int		ft_checks22b2b(t_numb *e)
{
	int		cnt;
	int		i;
	char	sn[7];

	ft_fullsn(sn);
	cnt = 0;
	while ((e->w - e->pr) > 0)
	{
		cnt++;
		ft_putchar(' ');
		(e->w)--;
	}
	i = 0;
	while (e->pr > 0)
	{
		ft_putchar(sn[i]);
		cnt++;
		i++;
		(e->pr)--;
	}
	return (cnt);
}

int		ft_checks22c(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indminus == 1)
		cnt = cnt + ft_checks22c1(e);
	else if (e->indminus == 0)
		cnt = cnt + ft_checks22c2(e);
	return (cnt);
}

int		ft_checks22c1(t_numb *e)
{
	int		cnt;
	int		i;
	char	sn[7];

	ft_fullsn(sn);
	cnt = 0;
	i = 0;
	while (i < 6)
	{
		ft_putchar(sn[i]);
		cnt++;
		i++;
	}
	if (e->w > 6)
		cnt = cnt + ft_checks2c1a(e);
	return (cnt);
}

int		ft_checks22c1a(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indzero == 1)
	{
		while ((e->w - e->pr) > 0)
		{
			cnt++;
			ft_putchar('0');
			(e->w)--;
		}
	}
	else
	{
		while ((e->w - e->pr) > 0)
		{
			cnt++;
			ft_putchar(' ');
			(e->w)--;
		}
	}
	return (cnt);
}

int		ft_checks22c2(t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indzero == 1)
		cnt = cnt + ft_checks22c2a(e);
	else
		cnt = cnt + ft_checks22c2b(e);
	return (cnt);
}

int		ft_checks22c2a(t_numb *e)
{
	int		cnt;
	int		i;
	char	sn[7];

	ft_fullsn(sn);
	cnt = 0;
	while ((e->w - e->pr) > 0)
	{
		cnt++;
		ft_putchar('0');
		(e->w)--;
	}
	i = 0;
	while (e->pr > 0)
	{
		ft_putchar(sn[i]);
		cnt++;
		i++;
		(e->pr)--;
	}
	return (cnt);
}

int		ft_checks22c2b(t_numb *e)
{
	int		cnt;
	int		i;
	char	sn[7];

	ft_fullsn(sn);
	cnt = 0;
	while ((e->w - e->pr) > 0)
	{
		cnt++;
		ft_putchar(' ');
		(e->w)--;
	}
	i = 0;
	while (e->pr > 0)
	{
		ft_putchar(sn[i]);
		cnt++;
		i++;
		(e->pr)--;
	}
	return (cnt);
}
