/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkwidth.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:55:14 by syusof            #+#    #+#             */
/*   Updated: 2016/02/10 09:35:05 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		ft_checkwidth(char *str)
{
	int	i;
	char *begi;
	char *s;
	char *s2;

//	printf ("str = %s\n",str);
	
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
		while((s[0] >= '0' && s[0] <= '9') || s[0] == ' ' || s[0] == '+' || s[0] == '-' || s[0] == '.')
		{
			s++;
			i++;
		}
		s = begi;
		s2 = (char*)malloc(sizeof(char) * i + 1);
		s2[i] = 0;
		i--;
		while (i >= 0 && s[i] != '-' && s[i] != '+' && s[i] != ' ' && s[i] != '#')
		{
			s2[i] = s[i];
//		printf("i= %d,s2 = %c\n",i,s2[i]);
			i--;
		}
		if (i < 0)
		{
			free(begi);
			return (ft_atoi(s2));
		}
//		if ((i >= 0 && s[i] == '-') || (i>= 0 && s[i] == '+') || (i>=))
		else
		{
//			s2[i] = s[i];
			i++;
			free(begi);
//		printf("i= %d,s2 = %s\n",i,&s2[i]);
			return (ft_atoi(&s2[i]));
		}
	}
//	if (ft_checkprec(s) == 0)
	{
		while(*s)
		{
			s++;
			i++;
		}
		s--;
		while ((*s == ' ' || *s == '-' || (*s >= '0' && *s <= '9')) && i > 0)
		{
			s--;
			i--;
		}
		s++;
//		if (*s == ' ' || (*s >= '0' && *s <= '9'))
			return ft_atoi(s);
	}
	return 0;
}

