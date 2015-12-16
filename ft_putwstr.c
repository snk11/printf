/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:55:06 by syusof            #+#    #+#             */
/*   Updated: 2015/12/16 06:41:20 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putwstr(wchar_t *s)
{
//	int		i;

	wchar_t c1;
	
//	int i1 = 206;
//	int i2 = 177;
//	i = 0;
//	while (s[i])
	{
//		ft_putchar(s[i]);
//		write(1,&i1,1);
//		write(1,&i2,1);
//		i++;
	}
	c1 = *s;
	printf("%d",c1);
//	printf("%d\n",L'米');
//	printf("%d\n",'a');

//	if (s <= 0x7F)
//		printf("UU");
	return 0;
}
