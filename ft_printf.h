/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 01:54:33 by syusof            #+#    #+#             */
/*   Updated: 2016/02/09 15:19:59 by syusof           ###   ########.fr       */
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


typedef struct			s_numb
{
	int					indplus;
	int					indspace;
	int					indsharp;
}						t_numb;


int		ft_printf(char *str, ...);
int		ft_atoi(const char *nptr);
int		ft_checkletter(char *str);
int		ft_checkstrlast(char *str);
int		ft_checkprec(char *s);
int		ft_checkwidth(char *str);
void	ft_putnbr(int w, int pr,int zero,int n);
void	ft_putstr(char const *s);
void	ft_putstr2(int pr,char const *s);
void	ft_putstrad(char const *s);
void	ft_putchar(char c);
size_t		ft_strlen(const char *str);
size_t		ft_strlen2(wchar_t *str);
int	ft_count(int n);
int	ft_countd(int w,int pr,int zero,t_numb e,int n);
int	ft_countld(long int n);
int	ft_countus(unsigned short n);
int	ft_countsd(short int n);
int			ft_countwstr(int pr,wchar_t *s);
int	ft_putwstr(wchar_t *s);
int			ft_putwstr2(int pr,wchar_t *s);
void	ft_putlongnbr(long n);
void	ft_putulongnbr(unsigned long n);
void	ft_putushortnbr(unsigned short n);
void	ft_putllnbr(long long n);
void	ft_putulonglongnbr(unsigned long long n);
void	ft_putsdnbr(short int n);
int	ft_countl(long n);
int	ft_countu(int w,int pr,int zero,t_numb e,unsigned int n);
int	ft_countuc(unsigned char n);
int	ft_countul(unsigned long n);
int	ft_countlld(long long n);
char	*ft_ltohex(long l);
char	*ft_ltohex2(unsigned long l);
char	*ft_ltohex3( unsigned long l);
char	*ft_ltohex4(unsigned long long l);
char	*ft_ltohex5(unsigned long long l);
char	*ft_ltohex6(unsigned short l);
char	*ft_ltohex7(unsigned short l);
char	*ft_ltohex8( unsigned char l);
char	*ft_ltohex9(unsigned char l);
char	*ft_ltooct(long l);
char	*ft_ltooct2(unsigned long l);
char	*ft_ltooct3(unsigned short l);
char	*ft_ltooct4(unsigned long long l);
char	*ft_ltooct5(unsigned short int l);
char	*ft_ltooct6(unsigned char l);
int	ft_putwchar(wchar_t c);
char	*ft_check_perc0(char *str);
char	*ft_check_perc8(char *str);
int	ft_countul(unsigned long n);
void	ft_putunbr(int w,int pr,int zero,unsigned int n);
void	ft_putldnbr(long int n);

#endif
