/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 01:54:33 by syusof            #+#    #+#             */
/*   Updated: 2016/01/12 18:34:47 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include <limits.h>
# include <stdlib.h>
# include <math.h>


int		ft_printf(char *str, ...);
void	ft_putnbr(int n);
void	ft_putstr(char const *s);
void	ft_putstrad(char const *s);
void	ft_putchar(char c);
size_t		ft_strlen(const char *str);
int		ft_countd(int n);
int	ft_putwstr(wchar_t *s);
void	ft_putlongnbr(long n);
void	ft_putulongnbr(unsigned long n);
int	ft_countl(long n);
int	ft_countul(unsigned long n);
char	*ft_ltohex(long l);
char	*ft_ltohex2(unsigned long l);
char	*ft_ltooct(long l);
char	*ft_ltooct2(long l);
int	ft_putwchar(wchar_t c);
char	*ft_check_perc0(char *str);
char	*ft_check_perc(char *str);
int	ft_countul(unsigned long n);
void	ft_putunbr(unsigned int n);

#endif
