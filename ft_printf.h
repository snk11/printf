/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 01:54:33 by syusof            #+#    #+#             */
/*   Updated: 2015/12/08 16:44:12 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include <limits.h>


int		ft_printf(char *str, ...);
void	ft_putnbr(int n);
void	ft_putstr(char const *s);
void	ft_putchar(char c);
size_t		ft_strlen(const char *str);
int		ft_countd(int n);
void	ft_putwstr(wchar_t *s);

#endif
