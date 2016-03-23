/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checko.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 03:28:36 by syusof            #+#    #+#             */
/*   Updated: 2016/03/23 01:17:23 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		ft_checko(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->indminus == 0)
		cnt = cnt + ft_checko42(str,e);
	else if (e->indminus == 1)
	{
		if (e->u == 0 && e->pr == 0 && e->indpr == 1 && e->indsharp == 0)
		{
		}
		else
			cnt = cnt + ft_checko21(str,e);
	}
	free(e->s);
	e->s = NULL;
	return (cnt);
}

int		ft_checko42(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
		if (e->u == 0 && e->pr == 0 && e->indpr == 1 && e->indsharp == 0)
		{
			while(e->w)
			{
				ft_putchar(' ');
				e->w--;
				cnt++;
			}
		}
		else
			cnt = cnt + ft_checko1(str,e);
	return (cnt);
}



int		ft_checko1(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	e->s = ft_ltooct(e->u);
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
		cnt = cnt + ft_checko1a(str,e);
	if (e->indsharp == 1 && e->u != 0 && e->pr == 0)
	{
		ft_putchar('0');
		cnt++;
	}
	ft_putstr(e->s);
	cnt = cnt + e->g;
	return (cnt);
}


int		ft_checko1a(char *str,t_numb *e)
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
		cnt = cnt + ft_checko1a1(str,e);
	return (cnt);
}

int		ft_checko1a1(char *str,t_numb *e)
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





int		ft_checko21(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	e->s = ft_ltooct(e->u);
	e->g = ft_strlen(e->s);
	if (e->indsharp == 1 && e->u != 0 && e->pr == 0)
	{
		ft_putchar('0');
		cnt++;
	}
	if (e->indsharp == 1)
	{
		ft_putstr(e->s);
		cnt = cnt + ft_checko21a(str,e);
	}
	if (e->indsharp == 0)
	{
		cnt = cnt + ft_checko21a(str,e);
	}
	cnt = cnt + e->g;
	return (cnt);
}

int		ft_checko21a(char *str,t_numb *e)
{
	int	cnt;
	int	i;

	cnt = 0;
	if (e->w >= e->g && e->indsharp == 0)
		cnt = cnt + ft_checko21a42a(str,e);
	else if (e->pr >= e->g && e->indsharp == 0)
		cnt = cnt + ft_checko21a42b(str,e);
	else if(e->indsharp == 0)
	{
		ft_putstr(e->s);
		cnt = cnt + ft_checko21a1(str,e);
	}
	else if (e->indsharp == 1)
		cnt = cnt + ft_checko21a1(str,e);
	return (cnt);
}


int		ft_checko21a42a(char *str,t_numb *e)
{
	int	cnt;
	int	i;

	cnt = 0;
		i = 0;
		cnt = cnt + ft_checko21a42a1(str,e);
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


int		ft_checko21a42a1(char *str,t_numb *e)
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

int		ft_checko21a42b(char *str,t_numb *e)
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

int		ft_checko21a1(char *str,t_numb *e)
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
