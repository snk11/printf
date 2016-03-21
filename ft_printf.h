/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 01:54:33 by syusof            #+#    #+#             */
/*   Updated: 2016/03/22 00:03:17 by syusof           ###   ########.fr       */
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

typedef struct			s_count
{
	int i;
	int v;
	int u;
	int neg;
	int	w;
	int	pr;
	int	minus;
}						t_count;

typedef struct			s_flag
{
	int	i;
	char *begi;
	char *s;
	char *s2;
	int		indend1;
	int		indend2;
	int		num;
	int		ret;
}						t_flag;

typedef struct			s_field
{
	int	i;
	char *s3;
}						t_field;

typedef struct			s_width
{
	int	i;
	char *begi;
	char *s;
	char *s2;
}						t_width;

typedef struct			s_lst
{
	void				*content;
	struct s_lst		*next;
}						t_lst;

int		ft_strcmp(const char *s1, const char *s2);
void		*ft_getfield1(char *str,t_field *f);
void		ft_checkwidth1(char *str,t_width *w);
void		ft_checkwidth2(char *str,t_width *w);
void	ft_checkflag1(t_numb *e,char *str,t_flag *f);
void	ft_checkflag2(t_numb *e,t_flag *f);
void	ft_checkflag3(t_numb *e,t_flag *f);
void	ft_checkflag3a(t_numb *e,t_flag *f);
void	ft_checkflag3a1(t_numb *e,t_flag *f);
void	ft_checkflag4(t_numb *e,t_flag *f);
void	ft_checkflag4a(t_numb *e,t_flag *f);
void	ft_ltooct11(char *res,long l,int i);
void	ft_ltooct12(char *res,unsigned long l,int i);
void	ft_ltooct13(char *res,unsigned short l,int i);
void	ft_ltooct14(char *res,unsigned long long l,int i);
void	ft_ltooct15(char *res,unsigned short int l,int i);
void	ft_ltooct16(char *res,unsigned char l,int i);
void	ft_ltohex11(char **res,long *l);
void	ft_ltohex12(char **res,unsigned long *l);
void	ft_ltohex13(char **res,unsigned long *l);
void	ft_ltohex14(char **res,unsigned long long *l);
void	ft_ltohex15(char **res,unsigned long long *l);
void	ft_ltohex16(char **res,unsigned short *l);
void	ft_ltohex17(char **res,unsigned short *l);
void	ft_ltohex18(char **res,unsigned char *l);
void	ft_ltohex19(char **res,unsigned char *l);
int		ft_case1(char **str,t_numb *e,va_list ap);
int		ft_case1b(char ***str,t_numb *e,va_list ap);
int		ft_case1c(char ***str,t_numb *e,va_list ap);
int		ft_case1a(char ***str,t_numb *e,va_list ap);
char	*ft_strnew(size_t size);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
void		lst_add1(t_lst **toplist, t_lst *t_lst1);
void	ft_push1stback(t_lst **lstmp);
t_lst		*create_lst1(void *content);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_printf(char *str, ...);
void	ft_initialize(t_numb *e);
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
int	ft_putnbr(int w, int pr,int zero,int n,t_numb *e);
int	ft_putnbr2(int w, int pr,int zero,int n,t_numb *e);
void	ft_putstr(char const *s);
void	ft_putstr2(int pr,char const *s);
void	ft_putstrad(char const *s);
void	ft_putstrad2(int pr,char const *s);
void	ft_putstrad3(int pr,char const *s);
void	ft_putchar(char c);
int	ft_count(int n);
int	ft_countd(t_numb *e,int n);
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
int	ft_countu(t_numb *e,unsigned int n);
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
int		ft_checks1a1(char *str,t_numb *e);
int		ft_checks1b(char *str,t_numb *e);
int		ft_checks1b1(char *str,t_numb *e);
int		ft_checks1b1a(char *str,t_numb *e);
int		ft_checks1b2(char *str,t_numb *e);
int		ft_checks1b2a(char *str,t_numb *e);
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
int		ft_checks42a(char *str,t_numb *e);
int		ft_checks42b(char *str,t_numb *e);
void ft_decr(t_numb *e);
int		ft_checks242(char *str,t_numb *e);
int		ft_checks242a(char *str,t_numb *e);
int		ft_checks242b(char *str,t_numb *e);
int		ft_checks21(char *str,t_numb *e);
int		ft_checks21a(char *str,t_numb *e);
int		ft_checks21a1(char *str,t_numb *e);
int		ft_checks21b(char *str,t_numb *e);
int		ft_checks21b1(char *str,t_numb *e);
int		ft_checks21b1a(char *str,t_numb *e);
int		ft_checks21b2(char *str,t_numb *e);
int		ft_checks21b2a(char *str,t_numb *e);
int		ft_checks22(char *str,t_numb *e);
int		ft_checks22a(char *str,t_numb *e);
int		ft_checks22b(char *str,t_numb *e);
int		ft_checks22b1(char *str,t_numb *e);
int		ft_checks22b1a(char *str,t_numb *e);
int		ft_checks22b2(char *str,t_numb *e);
int		ft_checks22b2a(char *str,t_numb *e);
int		ft_checks22b2b(char *str,t_numb *e);
int		ft_checks22c(char *str,t_numb *e);
int		ft_checks22c1(char *str,t_numb *e);
int		ft_checks22c1a(char *str,t_numb *e);
int		ft_checks22c2(char *str,t_numb *e);
int		ft_checks22c2a(char *str,t_numb *e);
int		ft_checks22c2b(char *str,t_numb *e);
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
int		ft_checkp1(char *str,t_numb *e,char *s1);
int		ft_checkp1a(char *str,t_numb *e,char *s1);
int		ft_checkp1a1(char *str,t_numb *e,char *s1);
int		ft_checkp1a1a(char *str,t_numb *e,char *s1);
int		ft_checkp1b(char *str,t_numb *e,char *s1);
int		ft_checkp1b1(char *str,t_numb *e,char *s1);
int		ft_checkp1b1a(char *str,t_numb *e,char *s1);
int		ft_checkp2(char *str,t_numb *e,char *s1);
int		ft_checkp2a(char *str,t_numb *e,char *s1);
int		ft_checkp2a1(char *str,t_numb *e,char *s1);
int		ft_checkp2a1a(char *str,t_numb *e,char *s1);
int		ft_checkp2a1a1(char *str,t_numb *e,char *s1);
int		ft_checkx(char *str,t_numb *e);
int		ft_checkx0(char *str,t_numb *e);
int		ft_checkx1(char *str,t_numb *e);
int		ft_checkx1a(char *str,t_numb *e);
int		ft_checkx1a1(char *str,t_numb *e);
int		ft_checkbx(char *str,t_numb *e);
int		ft_checkbx1(char *str,t_numb *e);
int		ft_checko(char *str,t_numb *e);
int		ft_checko1(char *str,t_numb *e);
int		ft_checko1a(char *str,t_numb *e);
int		ft_checko1a1(char *str,t_numb *e);
int		ft_checko21(char *str,t_numb *e);
int		ft_checko21a(char *str,t_numb *e);
int		ft_checko21a1(char *str,t_numb *e);
int		ft_checkbo(char *str,t_numb *e);
int		ft_checkbo1(char *str,t_numb *e);
int		ft_altprime(char *str,t_numb *e);
void		ft_altprime1(char **str,t_numb *e);
int		ft_altprime2(char *str,t_numb *e);
int		ft_altprime2a(char *str,t_numb *e);
int		ft_altprime2a1(char *str,t_numb *e);
int		ft_altprime2a1a(char *str,t_numb *e);
int		ft_altprime2a2(char *str,t_numb *e);
int		ft_altprime2a2a(char *str,t_numb *e);
int		ft_elseend(char *str,t_numb *e);
int		ft_elseend1(char *str,t_numb *e, char c);
int	ft_putwchar1(t_elem *e);
void	ft_putwchar1a(t_elem *e);
void	ft_putwchar1b(t_elem *e);
void	ft_putwchar1c(t_elem *e);
void	ft_putwchar1d(t_elem *e);
void	ft_putwchar1d1(t_elem *e);
void	ft_putwchar1e(t_elem *e);
void	ft_putwchar1e1(t_elem *e);
void	ft_putwchar1f(t_elem *e);
void	ft_putwchar1g(t_elem *e);
void	ft_putwchar1h(t_elem *e);
void	ft_putwchar1i(t_elem *e);
void	ft_putwchar1j(t_elem *e);
void	ft_putwstr1(t_elem *e);
void	ft_putwstr1a(t_elem *e);
void	ft_putwstr1b(t_elem *e);
void	ft_putwstr1c(t_elem *e);
void	ft_putwstr1d(t_elem *e);
void	ft_putwstr1d1(t_elem *e);
void	ft_putwstr1e(t_elem *e);
void	ft_putwstr1e1(t_elem *e);
void	ft_putwstr1f(t_elem *e);
void	ft_putwstr1g(t_elem *e);
void	ft_putwstr1h(t_elem *e);
void	ft_putwstr1i(t_elem *e);
void	ft_putwstr1j(t_elem *e);
size_t		ft_strlen(const char *str);
size_t		ft_strlen2(wchar_t *str);
int	ft_strlen1(t_elem *e);
void	ft_strlen1a(t_elem *e);
void	ft_strlen1b(t_elem *e);
void	ft_strlen1c(t_elem *e);
void	ft_strlen1d(t_elem *e);
void	ft_strlen1d1(t_elem *e);
void	ft_strlen1e(t_elem *e);
void	ft_strlen1e1(t_elem *e);
void	ft_strlen1f(t_elem *e);
void	ft_strlen1g(t_elem *e);
void	ft_strlen1h(t_elem *e);
void	ft_strlen1i(t_elem *e);
void	ft_strlen1j(t_elem *e);
void	ft_countwstr1(t_elem *e);
void	ft_countwstr1a(t_elem *e);
void	ft_countwstr1b(t_elem *e);
void	ft_countwstr1c(t_elem *e);
void	ft_countwstr1d(t_elem *e);
void	ft_countwstr1d1(t_elem *e);
void	ft_countwstr1e(t_elem *e);
void	ft_countwstr1e1(t_elem *e);
void	ft_countwstr1f(t_elem *e);
void	ft_countwstr1g(t_elem *e);
void	ft_countwstr1h(t_elem *e);
void	ft_countwstr1i(t_elem *e);
void	ft_countwstr1j(t_elem *e);
int	ft_countd(t_numb *e,int n);
void 	ft_countd1(t_count *f,int n);
void 	ft_countd2(t_count *f,int n);
int	ft_countd3(t_numb *e,t_count *f);
int	ft_countd3a(t_numb *e,t_count *f);
int	ft_countd3a1(t_numb *e,t_count *f);
int	ft_countd3a1a(t_numb *e,t_count *f);
int	ft_countd4(t_numb *e,t_count *f);
int	ft_countd4a(t_numb *e,t_count *f);
int	ft_countd4a1(t_numb *e,t_count *f);
int	ft_countd5(t_numb *e,t_count *f);
void 	ft_countud1(t_count *f);
void 	ft_countud2(t_count *f,unsigned int n);
void	ft_countud3(t_numb *e,t_count *f);
void	ft_countud3a(t_numb *e,t_count *f);
void	ft_countud3a0(t_numb *e,t_count *f);
void	ft_countud3a1(t_numb *e,t_count *f);
void	ft_countud4(t_numb *e,t_count *f);
void	ft_countud4a(t_numb *e,t_count *f);
void	ft_countud4a1(t_numb *e,t_count *f);
int	ft_countud5(t_numb *e,t_count *f);

#endif
