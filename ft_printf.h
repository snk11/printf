/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 01:54:33 by syusof            #+#    #+#             */
/*   Updated: 2016/03/09 16:04:05 by syusof           ###   ########.fr       */
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
	int					cnt1;
	int					ret1;
	int					pr;
	int					prbegi;
	int					d;
	int					g;
	long				l;
	unsigned int		u;
	unsigned long		ul;
	char				*s;
	wchar_t				wc;
	wchar_t				*ss;
	int					ind1;
	int					ind2;
	int					ind6;
	int					indletter;
	int					indlast;
	char				*begi;
}						t_numb;

typedef struct			s_elem
{
	int		n;
	int		n2;
	char	*str;
	char	*str2;
	char	*begi;
	char	*begi2;
	int c2;
	int c3;
	int ret;
	int ret1;
	int i;
	int j;
	int prbegi;
	int *r;
	int pr1;
}						t_elem;

typedef struct			s_lst
{
	void				*content;
	struct s_lst		*next;
}						t_lst;

int		ft_case1(char **str,t_numb **e,va_list ap);
int		ft_case1b(char ***str,t_numb ***e,va_list ap);
int		ft_case1c(char ***str,t_numb ***e,va_list ap);
int		ft_case1a(char ***str,t_numb ***e,va_list ap);
char	*ft_strnew(size_t size);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
void		lst_add1(t_lst **toplist, t_lst *t_lst1);
void	ft_push1stback(t_lst **lstmp);
t_lst		*create_lst1(void *content);
void	*ft_memmove(void *dest, const void *src, size_t n);
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
//char	*ft_check_perc8(char *str);
int	ft_countul(unsigned long n);
void	ft_putunbr(int w,int pr,int zero,unsigned int n);
void	ft_putldnbr(long int n);
int ft_checkflag(t_numb *e,char *str);
char	*ft_getfield(char *str);
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
int		ft_checkbs(char *str,t_numb *e);
int		ft_checkbs1(char *str,t_numb *e);
int		ft_checkbs1a(char *str,t_numb *e);
int		ft_checkbs1a1(char *str,t_numb *e);
int		ft_checkbs1a1a(char *str,t_numb *e);
int		ft_checkbs1a1b(char *str,t_numb *e);
int		ft_checkbs1a2(char *str,t_numb *e);
int		ft_checkbs1a2a(char *str,t_numb *e);
int		ft_checkbs1a2b(char *str,t_numb *e);
int		ft_checkbs1b(char *str,t_numb *e);
int		ft_checkbs1b1(char *str,t_numb *e);
int		ft_checkbs1b1a(char *str,t_numb *e);
int		ft_checkbs1b1b(char *str,t_numb *e);
int		ft_checkbs1b2(char *str,t_numb *e);
int		ft_checkbs1b2a(char *str,t_numb *e);
int		ft_checkbs1b2b(char *str,t_numb *e);
int		ft_checkbs1b2b1(char *str,t_numb *e);
int		ft_checkbs2(char *str,t_numb *e);
int		ft_checkbs2a(char *str,t_numb *e);
int		ft_checkbs2a1(char *str,t_numb *e);
int		ft_checkbs2a2(char *str,t_numb *e);
int		ft_checkbs2b(char *str,t_numb *e);
int		ft_checkbs2b1(char *str,t_numb *e);
int		ft_checkbs2b2(char *str,t_numb *e);
int		ft_checkp(char *str,t_numb *e);
int		ft_checkp1(char *str,t_numb *e);
int		ft_checkp1a(char *str,t_numb *e);
int		ft_checkp1a1(char *str,t_numb **e);
int		ft_checkp1a1a(char *str,t_numb *e);
int		ft_checkp1b(char *str,t_numb *e);
int		ft_checkp1b1(char *str,t_numb **e);
int		ft_checkp1b1a(char *str,t_numb *e);
int		ft_checkp2(char *str,t_numb *e);
int		ft_checkp2a(char *str,t_numb **e);
int		ft_checkp2a1(char *str,t_numb ***e);
int		ft_checkp2a1a(char *str,t_numb ****e);
int		ft_checkp2a1a1(char *str,t_numb *****e);
int		ft_checkx(char *str,t_numb *e);
int		ft_checkx1(char *str,t_numb *e);
int		ft_checkx1a(char *str,t_numb *e);
int		ft_checkx1a1(char *str,t_numb *e);
int		ft_checkbx(char *str,t_numb *e);
int		ft_checkbx1(char *str,t_numb *e);
int		ft_checko(char *str,t_numb *e);
int		ft_checko1(char *str,t_numb *e);
int		ft_checko1a(char *str,t_numb *e);
int		ft_checko1a1(char *str,t_numb *e);
int		ft_checkbo(char *str,t_numb *e);
int		ft_checkbo1(char *str,t_numb *e);
int		ft_altprime(char *str,t_numb *e);
void		ft_altprime1(char **str,t_numb **e);
int		ft_altprime2(char *str,t_numb **e);
int		ft_altprime2a(char *str,t_numb ***e);
int		ft_altprime2a1(char *str,t_numb ****e);
int		ft_altprime2a1a(char *str,t_numb *****e);
int		ft_altprime2a2(char *str,t_numb ****e);
int		ft_altprime2a2a(char *str,t_numb *****e);
int		ft_elseend(char *str,t_numb *e);
int		ft_elseend1(char *str,t_numb **e, char c);
int	ft_putwchar1(t_elem *e);
void	ft_putwchar1a(t_elem **e);
void	ft_putwchar1b(t_elem **e);
void	ft_putwchar1c(t_elem **e);
void	ft_putwchar1d(t_elem **e);
void	ft_putwchar1d1(t_elem ***e);
void	ft_putwchar1e(t_elem **e);
void	ft_putwchar1e1(t_elem ***e);
void	ft_putwchar1f(t_elem **e);
void	ft_putwchar1g(t_elem **e);
void	ft_putwchar1h(t_elem **e);
void	ft_putwchar1i(t_elem **e);
void	ft_putwchar1j(t_elem **e);
void	ft_putwstr1(t_elem **e);
void	ft_putwstr1a(t_elem ***e);
void	ft_putwstr1b(t_elem ***e);
void	ft_putwstr1c(t_elem ***e);
void	ft_putwstr1d(t_elem ***e);
void	ft_putwstr1d1(t_elem ****e);
void	ft_putwstr1e(t_elem ***e);
void	ft_putwstr1e1(t_elem ****e);
void	ft_putwstr1f(t_elem ***e);
void	ft_putwstr1g(t_elem ***e);
void	ft_putwstr1h(t_elem ***e);
void	ft_putwstr1i(t_elem ***e);
void	ft_putwstr1j(t_elem ***e);
int	ft_strlen1(t_elem *e);
void	ft_strlen1a(t_elem **e);
void	ft_strlen1b(t_elem **e);
void	ft_strlen1c(t_elem **e);
void	ft_strlen1d(t_elem **e);
void	ft_strlen1d1(t_elem ***e);
void	ft_strlen1e(t_elem **e);
void	ft_strlen1e1(t_elem ***e);
void	ft_strlen1f(t_elem **e);
void	ft_strlen1g(t_elem **e);
void	ft_strlen1h(t_elem **e);
void	ft_strlen1i(t_elem **e);
void	ft_strlen1j(t_elem **e);

#endif
