/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 01:54:33 by syusof            #+#    #+#             */
/*   Updated: 2016/03/02 08:05:06 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
#define FT_PRINTF_H

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
	int					indzero;
	int					indminus;
	int					indpr;
	int					w;
	int					pr;
	int					prbegi;
	int					d;
	char				*s;
	int					ind2;
}						t_numb;


int		ft_printf(char *str, ...);
void	ft_initialize(t_numb **e);
int ft_onelettercase(char *str,t_numb *e);
int ft_checkc(char *str,t_numb *e);
int	ft_checkc1(char *str,t_numb *e);
int		ft_checkc1a(char *str,t_numb *e);
int		ft_checkc1b(char *str,t_numb *e);
int	ft_checkc2(char *str,t_numb *e);
int		ft_checkc2a(char *str,t_numb *e);
int		ft_checkc2b(char *str,t_numb *e);
int		ft_atoi(const char *nptr);
int		ft_checkletter(char *str);
int		ft_checkstrlast(char *str);
int		ft_checkprec(char *s);
int		ft_checkwidth(char *str);
void	ft_putnbr(int w, int pr,int zero,int n);
void	ft_putstr(char const *s);
void	ft_putstr2(int pr,char const *s);
void	ft_putstrad(char const *s);
void	ft_putstrad2(int pr,char const *s);
void	ft_putstrad3(int pr,char const *s);
void	ft_putchar(char c);
size_t		ft_strlen(const char *str);
size_t		ft_strlen2(wchar_t *str);
int	ft_count(int n);
int	ft_countd(int w,int pr,t_numb *e,int n);
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
int	ft_countu(int w,int pr,int zero,t_numb *e,unsigned int n);
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
int ft_checkflag(t_numb *e,char *str);
char	*ft_getfield(int indpr,char *str);
int		ft_checks(char *str,t_numb *e);
int		ft_checks1(char *str,t_numb *e);
int		ft_checks1a(char *str,t_numb *e);
int		ft_checks1a1(char *str,t_numb **e);
int		ft_checks1b(char *str,t_numb *e);
int		ft_checks1b1(char *str,t_numb *e);
int		ft_checks1b1a(char *str,t_numb **e);
int		ft_checks1b2(char *str,t_numb *e);
int		ft_checks1b2a(char *str,t_numb **e);
int		ft_checks2(char *str,t_numb *e);
int		ft_checks2a(char *str,t_numb *e);
int		ft_checks2b(char *str,t_numb *e);
int		ft_checks2b1(char *str,t_numb *e);
int		ft_checks2b1a(char *str,t_numb *e);
int		ft_checks2b2(char *str,t_numb *e);
int		ft_checks2b2a(char *str,t_numb *e);
int		ft_checks2b2b(char *str,t_numb *e);
int		ft_checks2c(char *str,t_numb *e);
int		ft_checks2c1(char *str,t_numb *e);
int		ft_checks2c1a(char *str,t_numb *e);
int		ft_checks2c2(char *str,t_numb *e);
int		ft_checks2c2a(char *str,t_numb *e);
int		ft_checks2c2b(char *str,t_numb *e);
int		ft_checks42(char *str,t_numb *e);
int		ft_checks42a(char *str,t_numb **e);
int		ft_checks42b(char *str,t_numb *e);
void ft_decr(t_numb **e);

#endif
