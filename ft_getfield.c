/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfield.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 08:16:18 by syusof            #+#    #+#             */
/*   Updated: 2016/02/10 09:25:54 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

char *ft_getfield(int indpr,int ind2,char *str)
{
	int	i;
	char *s3;
				if ((*str >= '0' && *str <= '9') || *str == '-' || *str == '.' || *str == ' ' || *str == '#')
				{
					if (*str == '.')
						indpr = 1;
					if (ind2 == 0)
					{
						i = 0;
						while (ft_checkletter(str) == 0)
						{
							i++;
							str++;
						}
						str--;
						s3 = (char*)malloc(sizeof(char)*i + 1);
						s3[i] = 0;
						while(i > 0)
						{
							s3[i - 1] = *str;
							i--;
							str--;
						}
//											printf("s3 =%s\n",s3);
					}

//									printf("w = %d\n",w);
//									printf("pr = %d\n",pr);
					ind2 = 1;
				}
	return (s3);

}

