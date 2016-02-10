/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 20:57:54 by syusof            #+#    #+#             */
/*   Updated: 2016/02/10 09:44:43 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int ft_checkflag(t_numb *e,char *str)
{
	
	int	i;
	char *begi;
	char *s;
	char *s2;
	int		indend1;
	int		indend2;
	int		indend3;
	int		num;
	int		ret = 0;
	indend1 = 0;
	indend2 = 0;
	indend3 = 0;
	ret = 0;
	s = (char*)malloc(sizeof(char)*(ft_strlen(str)) + 1);
	i = 0;
	while (i < ft_strlen(str))
	{
		s[i] = str[i];
		i++;
	}
	s[i] = 0;
//		printf("i= %d,s = %s\n",i,s);
	i = 0;
	begi = s;
//	if ((s[0] >= '0' && s[0] <= '9') || s[0] == ' ' || s[0] == '+' || s[0] == '-')
	{
		while((s[0] >= '0' && s[0] <= '9') || s[0] == ' ' || s[0] == '+' || s[0] == '-' || s[0] == '.' || s[0] == '#')
		{
			s++;
			i++;
		}
		s = begi;
		s2 = (char*)malloc(sizeof(char) * i + 1);
		s2[i] = 0;
		i--;
		while (i >= 0)
		{
			s2[i] = s[i];
			i--;
		}
		if (i < 0)
			i++;
		if ((i >= 0 && s[i] == '-') || (i>= 0 && s[i] == '+') || (i>= 0 && s[i] == ' ') || (i>= 0 && s[i] == '#'))
		{
			s2[i] = s[i];
//			printf("s[i]= %c\n",s[i]);
			if (begi)
				free(begi);
//		printf("i= %d,s2 = %s\n",i,&s2[i]);
			indend1 = 1;
			num = i;
		}
		indend2 = 1;
	}
//	if (ft_checkprec(s) == 0)
	{
		while(*s)
		{
			s++;
			i++;
		}
		s--;
		while ((*s == ' ' || *s == '-' || *s == ' '|| *s == '#' || (*s >= '0' && *s <= '9')) && i > 0)
		{
			s--;
			i--;
		}
		s++;
//		if (*s == ' ' || (*s >= '0' && *s <= '9'))
			indend3 = 1;
	}

//	printf("end1 = %d,end2 = %d, end3 = %d\n",indend1,indend2,indend3);

	if(indend1 == 1)
	{
		i = num;
		while(s2[i] && ( s2[i]!=' ' || s2[i]!= '#' || s2[i] != '+'))
		{
			if (s2[i]== ' ' && ret == 0)
			{
				e->indspace = 1;
				ret++;
			}
			if (s2[i]== '#')
			{
				e->indsharp = 1;
				ret++;
			}
			if (s2[i] == '+')
			{
				e->indplus = 1;
				ret++;
			}
			if (s2[i] == '-')
			{
				e->indminus = 1;
			}
			i++;
		}
		if (s2[i] && s2[i] == '0')
			e->indzero = 1;
	}
	else if(indend2 == 1)
	{
		while (( *s2 == ' ' || *s2 == '#' || *s2 == '+'))
		{
			if ( *s2== ' ' && ret == 0)
			{
				e->indspace = 1;
				ret++;
			}
			if (*s2 == '#')
			{
				e->indsharp = 1;
				ret++;
			}
			if (*s2 == '+')
			{
				e->indplus = 1;
				ret++;
			}
			if (*s2 == '-')
			{
				e->indminus = 1;
			}
			s2++;
		}
		if (*s2 && *s2 == '0')
			e->indzero = 1;
	}
	else if(indend3 == 1)
	{
		while (( *s == ' ' || *s == '#' || *s == '+'))
		{
			if (*s == ' ' && ret == 0)
			{
				e->indspace = 1;
				ret++;
			}
			if (*s == '#')
			{
				e->indsharp = 1;
				ret++;
			}
			if (*s == '+')
			{
				e->indplus = 1;
				ret++;
			}
			if (*s == '-')
			{
				e->indminus = 1;
			}
			s++;
		}
		if (*s && *s == '0')
			e->indzero = 1;
	}
//	printf("ret = %d\n",ret);
	return (ret);
}
