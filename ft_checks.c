/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 01:26:49 by syusof            #+#    #+#             */
/*   Updated: 2016/03/02 06:02:22 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checks(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	e->prbegi = e->pr;
	if (e->indpr == 1)
		cnt = cnt + ft_checks1(str,e);
	else
		cnt = cnt + ft_checks2(str,e);
	e->ind2 = 0;
	e->w = 0;
	e->pr = 0;
	e->indzero = 0;
	e->indpr = 0;
	e->indminus = 0;

}

int		ft_checks1(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->pr > abs(e->w))
		cnt = cnt + ft_checks1a(str,e);
	else if(abs(e->w) > e->pr)
		cnt = cnt + ft_checks1b(str,e);
	return (cnt);
}


int		ft_checks1a(char *str,t_numb *e)
{
	int cnt;
	int	i;

	i = 0;
	cnt = 0;
	cnt = cnt + ft_checks1a1(str,&e);
		if (e->s)
		{
			ft_putstr2(e->pr,e->s);
			i = 0;
			e->pr =e->prbegi;
			while (i < ft_strlen(e->s) && e->pr > 0)
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


int		ft_checks1a1a(char *str,t_numb **e)
{
	int cnt;

	cnt = 0;
	if ((*e)->indzero == 0)
	{
		while(((*e)->w - ft_strlen((*e)->s)) > 0 && (*e)->pr > 0)
		{
			cnt++;
			ft_putchar(' ');
			((*e)->w)--;
			((*e)->pr)--;
		}
	}
	else
	{
		while(((*e)->w - ft_strlen((*e)->s)) > 0 && (*e)->pr > 0)
		{
			cnt++;
			ft_putchar('0');
			((*e)->w)--;
			((*e)->pr)--;
		}
	}
	return (cnt);
}

int		ft_checks1b(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (ft_strlen(e->s) > e->pr)
		cnt = cnt + ft_checks1b1(str,e);
	else if (ft_strlen(e->s) < e->pr)
		cnt = cnt + ft_checks1b2(str,e);
	return (cnt);
}

int		ft_checks1b1(char *str,t_numb *e)
{
	int	cnt;
	int	i;

	cnt = 0;
	cnt = cnt + ft_checks1b1a(str,&e);
		if (e->s)
		{
			ft_putstr2(e->pr,e->s);
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

}

int		ft_checks1b1a(char *str,t_numb **e)
{
	int	cnt;

	cnt = 0;
	if ((*e)->indzero == 0)
	{
		while(((*e)->w - (*e)->pr) > 0)
		{
			cnt++;
			ft_putchar(' ');
			((*e)->w)--;
		}
	}
	else
	{
		while(((*e)->w - (*e)->pr) > 0)
		{
			cnt++;
			ft_putchar('0');
			((*e)->w)--;
		}
	}

}

int		ft_checks1b2(char *str,t_numb *e)
{
	int	cnt;
	int	i;

	cnt = 0;
	cnt = cnt + ft_checks1b2a(str,&e);
	if (e->s)
	{
		ft_putstr(e->s);
		i = 0;
		while (i < ft_strlen(e->s))
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
}


int		ft_checks1b2a(char *str,t_numb **e)
{
	int	cnt;

	cnt = 0;
	if ((*e)->indzero == 0)
	{
		while(((*e)->w - ft_strlen((*e)->s)) > 0)
		{
			cnt++;
			ft_putchar(' ');
			((*e)->w)--;
		}
	}
	else
	{
		while(((*e)->w - ft_strlen((*e)->s)) > 0)
		{
			cnt++;
			ft_putchar('0');
			((*e)->w)--;
		}
	}
}







int		ft_checks2(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	if (e->pr > 6)
		e->pr = 6;
	if (e->w < 0)
	{
		e->w = -(e->w);
		e->indminus = 1;
	}
	if (e->w == 0 && e->pr == 0 && e->indpr == 0)
		cnt = cnt + ft_checks2a(str,e);
	else if (e->indpr == 1)
		cnt = cnt + ft_checks2b(str,e);
	else if (e->indpr == 0)
		cnt = cnt + ft_checks2c(str,e);
}


int		ft_checks2a(char *str,t_numb *e)
{
	int	cnt;
	int i;
	char	sn[]="(null)";

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



int		ft_checks2b(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
		if (e->indminus == 1)
			cnt = cnt + ft_checks2b1(str,e);
		else if (e->indminus == 0)
			cnt = cnt + ft_checks2b2(str,e);
}

int		ft_checks2b1(char *str,t_numb *e)
{
			int	cnt;
			int	i;
			char	sn[]="(null)";
			
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
			cnt = cnt + ft_checks2b1a(str,e);
		return (cnt);
}

int		ft_checks2b1a(char *str,t_numb *e)
{
			int	cnt;

			cnt = 0;
			if (e->w > 6)
			{
				if (e->indzero == 1)
				{
					while((e->w - e->pr) > 0)
					{
						cnt++;
						ft_putchar('0');
						(e->w)--;
					}
				}
				else
				{
					while((e->w - e->pr) > 0)
					{
						cnt++;
						ft_putchar(' ');
						(e->w)--;
					}
				}
			}
			return (cnt);
}


int		ft_checks2b2(char *str,t_numb *e)
{
			int	cnt;

			cnt = 0;
			if (e->indzero == 1)
				cnt = cnt + ft_checks2b2a(str,e);
			else
				cnt = cnt + ft_checks2b2b(str,e);
}


int		ft_checks2b2a(char *str,t_numb *e)
{
			int	cnt;
			int	i;
			char	sn[]="(null)";
			
			cnt = 0;
				while((e->w - e->pr) > 0)
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
}


int		ft_checks2b2b(char *str,t_numb *e)
{
			int	cnt;
			int	i;
			char	sn[]="(null)";
			
			cnt = 0;
				while((e->w - e->pr) > 0)
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

}


int		ft_checks2c(char *str,t_numb *e)
{
			int	cnt;
			
			cnt = 0;
		if (e->indminus == 1)
			cnt = cnt + ft_checks2c1(str,e);
		else if (e->indminus == 0)
			cnt = cnt + ft_checks2c2(str,e);
}

int		ft_checks2c1(char *str,t_numb *e)
{
			int	cnt;
			int	i;
			char	sn[]="(null)";
			
			cnt = 0;
			i = 0;
			while (i < 6)
			{
				ft_putchar(sn[i]);
				cnt++;
				i++;
			}
			if (e->w > 6)
				cnt = cnt + ft_checks2c1a(str,e);
}


int		ft_checks2c1a(char *str,t_numb *e)
{
			int	cnt;
			
			cnt = 0;
				if (e->indzero == 1)
				{
					while((e->w - e->pr) > 0)
					{
						cnt++;
						ft_putchar('0');
						(e->w)--;
					}
				}
				else
				{
					while((e->w - e->pr) > 0)
					{
						cnt++;
						ft_putchar(' ');
						(e->w)--;
					}
				}
}


int		ft_checks2c2(char *str,t_numb *e)
{
			int	cnt;
			
			cnt = 0;
			if (e->indzero == 1)
				cnt =cnt + ft_checks2c2a(str,e);
			else
				cnt =cnt + ft_checks2c2b(str,e);
}


int		ft_checks2c2a(char *str,t_numb *e)
{
			int	cnt;
			int	i;
			char	sn[]="(null)";
			
			cnt = 0;
				while((e->w - e->pr) > 0)
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
}


int		ft_checks2c2b(char *str,t_numb *e)
{
			int	cnt;
			int	i;
			char	sn[]="(null)";
			
			cnt = 0;
				while((e->w - e->pr) > 0)
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
}

