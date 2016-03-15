/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfield.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 08:16:18 by syusof            #+#    #+#             */
/*   Updated: 2016/03/15 12:04:48 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"


char *ft_getfield(char *str)
{
	int	i;
	char *s3;

	s3 = NULL;
				if ((*str >= '0' && *str <= '9') || *str == '-'
						|| *str == '+'|| *str == '.' || *str == ' '
						|| *str == '#')
				{
						i = 0;
				while((*str >= '0' && *str <= '9') || *str == '-'
						|| *str == '+'|| *str == '.' || *str == ' '
						|| *str == '#')
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

//									printf("w = %d\n",w);
//									printf("pr = %d\n",pr);
				}
	return (s3);

}
