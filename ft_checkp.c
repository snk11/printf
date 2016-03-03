/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 23:58:27 by syusof            #+#    #+#             */
/*   Updated: 2016/03/03 01:40:14 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		ft_checkp(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
	e->g = (ft_strlen(ft_ltohex(e->l)));
	if (e->indpr == 1)
		cnt = cnt + ft_checkp1(str,e);
	else if (e->indpr == 0)
		cnt = cnt + ft_checkp2(str,e);
	return (cnt);
}




int		ft_checkp1(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;

	if (e->pr == 0 && e->w == 0)
	{
		ft_putstr("0x");
		cnt = cnt + 2;
	}
	else if(e->w == 0)
		cnt = cnt + ft_checkp1a(str,e);
	else
		cnt = cnt + ft_checkp1b(str,e);
	return (cnt);


}



int		ft_checkp1a(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
		if (e->indzero == 1)
		{
			ft_putstr("0x");
			ft_putstrad2(e->pr,ft_ltohex(e->l));
			while((e->w - (e->g + 2)) > 0)
			{
				cnt++;
				ft_putchar('0');
				(e->w)--;
			}
		}
		else
			cnt = cnt + ft_checkp1a1(str,&e);
		if (e->pr > ft_strlen(ft_ltohex(e->l)))
			cnt = cnt + e->pr + 2;
		else
			cnt = cnt + ft_strlen(ft_ltohex(e->l)) + 2;
	return (cnt);
}

int		ft_checkp1a1(char *str,t_numb **e)
{
	int	cnt;

	cnt = 0;
			if ((*e)->w < 0)
				(*e)->w = -((*e)->w);
			(*e)->g = ft_strlen(ft_ltohex((*e)->l));
			if ((*e)->pr > ft_strlen(ft_ltohex((*e)->l)))
			{
				while(((*e)->w - ((*e)->pr + 2)) > 0)
				{
					cnt++;
					ft_putchar(' ');
					((*e)->w)--;
				}
			}
			else
				cnt = cnt + ft_checkp1a1a(str,(*e));
			ft_putstr("0x");
			ft_putstrad3((*e)->pr,ft_ltohex((*e)->l));
	return (cnt);
}

int		ft_checkp1a1a(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
				while((e->w - (e->g + 2)) > 0)
				{
					cnt++;
					ft_putchar('p');
					(e->w)--;
				}
	return (cnt);

}
int		ft_checkp1b(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
		if (e->indzero == 1)
		{
			ft_putstr("0x");
			ft_putstrad2(e->pr,ft_ltohex(e->l));
			while((e->w - (e->g + 2)) > 0)
			{
				cnt++;
				ft_putchar('0');
				(e->w)--;
			}
		}
		else
			cnt = cnt + ft_checkp1b1(str,&e);
		if (e->pr > ft_strlen(ft_ltohex(e->l)))
			cnt = cnt + e->pr + 2;
		else
			cnt = cnt + ft_strlen(ft_ltohex(e->l)) + 2;
	return (cnt);
}


int		ft_checkp1b1(char *str,t_numb **e)
{
	int	cnt;

	cnt = 0;
			if ((*e)->w < 0)
				(*e)->w = -((*e)->w);
			(*e)->g = ft_strlen(ft_ltohex((*e)->l));
			if ((*e)->pr > ft_strlen(ft_ltohex((*e)->l)))
			{
				while(((*e)->w - ((*e)->pr + 2)) > 0)
				{
					cnt++;
					ft_putchar(' ');
					((*e)->w)--;
				}
			}
			else
				cnt = cnt + ft_checkp1b1a(str,(*e));
			ft_putstr("0x");
			ft_putstrad2((*e)->pr,ft_ltohex((*e)->l));
	return (cnt);
}

int		ft_checkp1b1a(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;

			while((e->w - (e->g + 2)) > 0)
				{
					cnt++;
					ft_putchar(' ');
					(e->w)--;
				}
	return (cnt);

}

int		ft_checkp2(char *str,t_numb *e)
{
	int	cnt;

	cnt = 0;
		cnt = cnt + ft_checkp2a(str,&e);
		cnt = cnt + e->g + 2;
		int o = 0;
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

int		ft_checkp2a(char *str,t_numb **e)
{
	int	cnt;

	cnt = 0;
		if ((*e)->indzero == 1)
		{
			ft_putstr("0x");
			ft_putstrad(ft_ltohex((*e)->l));
			while(((*e)->w - ((*e)->g + 2)) > 0)
			{
				cnt++;
				ft_putchar('0');
				((*e)->w)--;
			}
		}
		else
			cnt = cnt + ft_checkp2a1(str,&e);
	return (cnt);
}


int		ft_checkp2a1(char *str,t_numb ***e)
{
	int	cnt;

	cnt = 0;
			if ((**e)->indminus == 1)
			{
				ft_putstr("0x");
				ft_putstrad(ft_ltohex((**e)->l));
				while(((**e)->w - ((**e)->g + 2)) > 0)
				{
					cnt++;
					ft_putchar(' ');
					((**e)->w)--;
				}
			}
			else
				cnt = cnt + ft_checkp2a1a(str,&e);
	return (cnt);
}




int		ft_checkp2a1a(char *str,t_numb ****e)
{
	int	cnt;

	cnt = 0;
				if ((***e)->indspace == 1 || (***e)->indplus == 1)
				{
					while(((***e)->w - ((***e)->g + 2)) > 0)
					{
						cnt++;
						ft_putchar(' ');
						((***e)->w)--;
					}
					ft_putstr("0x");
					ft_putstr(ft_ltohex((***e)->l));
				}
				else
					cnt = cnt + ft_checkp2a1a1(str,&e);
	return (cnt);
}



int		ft_checkp2a1a1(char *str,t_numb *****e)
{
	int	cnt;

	cnt = 0;
			while(((****e)->w - ((****e)->g + 2)) > 0)
					{
						cnt++;
						ft_putchar(' ');
						((****e)->w)--;
					}
					ft_putstr("0x");
					ft_putstrad(ft_ltohex((****e)->l));
	return (cnt);
}
