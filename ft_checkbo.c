/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkbo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 03:41:10 by syusof            #+#    #+#             */
/*   Updated: 2016/03/23 01:05:11 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"


int		ft_checkbo(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indminus == 0)
		cnt = cnt + ft_checkbo42(str,e);
	else if (e->indminus == 1)
	{
		if (e->ul == 0 && e->pr == 0 && e->indpr == 1 && e->indsharp == 0)
		{
		}
		else
			cnt = cnt + ft_checkbo21(str,e);
	}
	if (e->s)
	{
		if (ft_strcmp(e->s,"1000000000000000000000") != 0)
		{
			free(e->s);
			e->s = NULL;
		}
	}
	return (cnt);
}

int		ft_checkbo42(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
		if (e->ul == 0 && e->pr == 0 && e->indpr == 1 && e->indsharp == 0)
		{
			while(e->w)
			{
				ft_putchar(' ');
				e->w--;
				cnt++;
			}
		}
		else
			cnt = cnt + ft_checkbo1(str,e);
	return (cnt);
}



int		ft_checkbo1(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	e->s = ft_ltooct2(e->ul);
	e->g = ft_strlen(e->s);
	if (e->indzero == 1 && e->pr == 0)
	{
		while(e->w - e->g > 0)
		{
			ft_putchar('0');
			cnt++;
			e->w--;
		}
	}
	else
		cnt = cnt + ft_checkbo1a(str,e);
	if (e->indsharp == 1 && e->ul != 0 && e->pr == 0)
	{
		ft_putchar('0');
		cnt++;
	}
	ft_putstr(e->s);
	cnt = cnt + e->g;
	return (cnt);
}


int		ft_checkbo1a(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->pr >= e->g)
	{
		while(e->w - e->pr > 0)
		{
			ft_putchar(' ');
			cnt++;
			(e->w)--;
		}

		while((e->pr - e->g) > 0)
		{
			ft_putchar('0');
			cnt++;
			(e->pr)--;
		}
	}
	else
		cnt = cnt + ft_checkbo1a1(str,e);
	return (cnt);
}

int		ft_checkbo1a1(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indsharp == 0)
	{
		while(e->w - e->g > 0)
		{
			ft_putchar(' ');
			cnt++;
			(e->w)--;
		}
	}
	else if (e->indsharp == 1)
	{
		while(e->w - e->g - 1 > 0)
		{
			ft_putchar(' ');
			cnt++;
			(e->w)--;
		}
	}
	return (cnt);
}





int		ft_checkbo21(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	e->s = ft_ltooct2(e->ul);
	e->g = ft_strlen(e->s);
	if (e->indsharp == 1 && e->ul != 0 && e->pr == 0)
	{
		ft_putchar('0');
		cnt++;
	}
	if (e->indsharp == 1)
	{
		ft_putstr(e->s);
		cnt = cnt + ft_checkbo21a(str,e);
	}
	if (e->indsharp == 0)
	{
		cnt = cnt + ft_checkbo21a(str,e);
	}
	cnt = cnt + e->g;
	return (cnt);
}

int		ft_checkbo21a(char *str,t_numb *e)
{
	int	cnt;
	int	i;

	cnt = 0;
	if (e->w >= e->g && e->indsharp == 0)
		cnt = cnt + ft_checkbo21a42a(str,e);
	else if (e->pr >= e->g && e->indsharp == 0)
		cnt = cnt + ft_checkbo21a42b(str,e);
	else if(e->indsharp == 0)
	{
		ft_putstr(e->s);
		cnt = cnt + ft_checkbo21a1(str,e);
	}
	else if (e->indsharp == 1)
		cnt = cnt + ft_checkbo21a1(str,e);
	return (cnt);
}


int		ft_checkbo21a42a(char *str,t_numb *e)
{
	int	cnt;
	int	i;

	cnt = 0;
		i = 0;
		cnt = cnt + ft_checkbo21a42a1(str,e);
		if (e->pr >= e->g)
		{
			while(e->w - e->pr > 0)
			{
				ft_putchar(' ');
				cnt++;
				(e->w)--;
			}
		}
		else
		{
			while(e->w - e->g > 0)
			{
				ft_putchar(' ');
				cnt++;
				(e->w)--;
			}
		}
	return (cnt);
}


int		ft_checkbo21a42a1(char *str,t_numb *e)
{
	int	cnt;
	int	i;

	cnt = 0;
		i = 0;

		while(i < e->pr - e->g)
		{
			ft_putchar('0');
			cnt++;
			i++;
		}
		ft_putstr(e->s);
	return (cnt);
}

int		ft_checkbo21a42b(char *str,t_numb *e)
{
	int	cnt;
	int	i;

	cnt = 0;
		i = 0;

	while(e->w - e->pr > 0)
		{
			ft_putchar(' ');
			cnt++;
			(e->w)--;
		}

		while((e->pr - e->g) > 0)
		{
			ft_putchar('0');
			cnt++;
			(e->pr)--;
		}
		ft_putstr(e->s);
	return (cnt);
}

int		ft_checkbo21a1(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indsharp == 0)
	{
		while(e->w - e->g > 0)
		{
			ft_putchar(' ');
			cnt++;
			(e->w)--;
		}
	}
	else if (e->indsharp == 1)
	{
		while(e->w - e->g - 1 > 0)
		{
			ft_putchar(' ');
			cnt++;
			(e->w)--;
		}
	}
	return (cnt);
}
