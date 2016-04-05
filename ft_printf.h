/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 01:54:33 by syusof            #+#    #+#             */
/*   Updated: 2016/04/05 04:55:01 by syusof           ###   ########.fr       */
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
	int					indll;
	int					indperc;
	int					w;
	int					cnt1;
	int					ret1;
	int					pr;
	int					prbegi;
	int					d;
	int					g;
	size_t				z;
	intmax_t			j;
	short int			sd;
	long				l;
	unsigned int		u;
	unsigned short		us;
	unsigned long		ul;
	unsigned long long		ull;
	char				*s;
	wchar_t				wc;
	wchar_t				*ss;
	int					ind1;
	int					ind2;
	int					ind6;
	int					indletter;
	int					indlast;
	char				*begi;
	int					valzero;
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
	int neg;
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

typedef struct			s_ll
{
	int k;
	int k2;
}						t_ll;

typedef struct			s_width
{
	int	i;
	int	j;
	char *begi;
	char *s;
	char *s2;
}						t_width;

typedef struct			s_lst
{
	void				*content;
	struct s_lst		*next;
}						t_lst;

int	ft_checkll(char *str, t_numb *e,va_list ap, t_ll *w);
int	ft_pow(int n, int p);
int		ft_strcmp(const char *s1, const char *s2);
void		*ft_getfield1(char *str,t_field *f);
void	ft_checkflag1(t_numb *e,char *str,t_flag *f);
void	ft_checkflag2(t_numb *e,t_flag *f);
void	ft_checkflag3(t_numb *e,t_flag *f);
void	ft_checkflag3a(t_numb *e,t_flag *f);
void	ft_checkflag3a1(t_numb *e,t_flag *f);
void	ft_checkflag4(t_numb *e,t_flag *f);
void	ft_checkflag4a(t_numb *e,t_flag *f);
void	ft_ltooct10(char *res,long l,int i);
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
int		ft_checkletter(char str);
int		ft_checkstrlast(char *str);
int		ft_checkprec(t_numb *e,char *s);
int		ft_checkwidth(t_numb *e,char *str);
void		ft_checkwidth1(char *str,t_width *w,t_numb *e);
void		ft_checkwidth2(char *str,t_width *w);
int	ft_putnbr(int n,t_numb *e);
int	ft_putnbr1(int n,t_numb *e);
int	ft_putnbr2(int n,t_numb *e);
int	ft_putnbr2a(int n,t_numb *e);
int	ft_putnbr2a1(int n,t_numb *e);
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
int	ft_countul(unsigned long n);
int	ft_putunbr(unsigned int n,t_numb *e);
int	ft_putunbr1(unsigned int n,t_numb *e);
int	ft_putunbr2(unsigned int n,t_numb *e);
int	ft_putunbr2a(unsigned int n,t_numb *e);
int	ft_putunbr2a1(unsigned int n,t_numb *e);
void	ft_putldnbr(long int n);
//int ft_checkflag(t_numb *e,char *str);
char	*ft_getfield(char *str);
int		ft_checks52a(char *str,t_numb *e);
int		ft_checks52b(char *str,t_numb *e);
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
int		ft_checkx0a(char *str,t_numb *e);
int		ft_checkx1(char *str,t_numb *e);
int		ft_checkx142a(char *str,t_numb *e);
int		ft_checkx142b(char *str,t_numb *e);
int		ft_checkx1a(char *str,t_numb *e);
int		ft_checkx1a1(char *str,t_numb *e);
int		ft_checko(char *str,t_numb *e);
int		ft_checko42(char *str,t_numb *e);
int		ft_checko1(char *str,t_numb *e);
int		ft_checko1a(char *str,t_numb *e);
int		ft_checko1a1(char *str,t_numb *e);
int		ft_checko21(char *str,t_numb *e);
int		ft_checko21a(char *str,t_numb *e);
int		ft_checko21a42a(char *str,t_numb *e);
int		ft_checko21a42a1(char *str,t_numb *e);
int		ft_checko21a42b(char *str,t_numb *e);
int		ft_checko21a1(char *str,t_numb *e);
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
int		ft_checkd1(t_numb *e);
int		ft_checkd1a(t_numb *e);
int		ft_checkd1a1(t_numb *e);
int		ft_checkd1b(t_numb *e);
int		ft_checkd1b1(t_numb *e);
int	ft_countd(t_numb *e,int n);
void 	ft_countd2(t_count *f,int n);
int		ft_countd3(t_numb *e,t_count *f);
int		ft_countd342a(t_numb *e,t_count *f);
int		ft_countd342a1(t_numb *e,t_count *f);
int		ft_countd342a1a(t_numb *e,t_count *f);
int		ft_countd342b(t_numb *e,t_count *f);
int	ft_countd3a(t_numb *e,t_count *f);
int	ft_countd3a1(t_numb *e,t_count *f);
int	ft_countd3a142(t_numb *e,t_count *f);
int	ft_countd3a1a(t_numb *e,t_count *f);
int	ft_countd4(t_numb *e,t_count *f);
int	ft_countd442(t_numb *e,t_count *f);
int	ft_countd4a(t_numb *e,t_count *f);
int	ft_countd4a42(t_numb *e,t_count *f);
int	ft_countd4a2(t_numb *e,t_count *f);
int		ft_checku1(t_numb *e);
int		ft_checku1a(t_numb *e);
int		ft_checku1b(t_numb *e);
int	ft_countu(t_numb *e,unsigned n);
void 	ft_countu2(t_count *f,unsigned int n);
int		ft_countu3(t_numb *e,t_count *f);
int		ft_countu342(t_numb *e,t_count *f);
int		ft_countu342a(t_numb *e,t_count *f);
int	ft_countu3a(t_numb *e,t_count *f);
int	ft_countu3a1(t_numb *e,t_count *f);
int	ft_countu3a1a(t_numb *e,t_count *f);
int	ft_countu4(t_numb *e,t_count *f);
int	ft_countu4a(t_numb *e,t_count *f);
int	ft_countu4a1(t_numb *e,t_count *f);
int		ft_checku(char *str,t_numb *e);
int		ft_checkd(char *str,t_numb *e);
int	ft_count2(unsigned int n);
int		ft_checkbx(char *str,t_numb *e);
int		ft_checkbx0(char *str,t_numb *e);
int		ft_checkbx0a(char *str,t_numb *e);
int		ft_checkbx1(char *str,t_numb *e);
int		ft_checkbx142a(char *str,t_numb *e);
int		ft_checkbx142b(char *str,t_numb *e);
int		ft_checkbx1a(char *str,t_numb *e);
int		ft_checkbx1a1(char *str,t_numb *e);
int		ft_checkbo(char *str,t_numb *e);
int		ft_checkbo42(char *str,t_numb *e);
int		ft_checkbo1(char *str,t_numb *e);
int		ft_checkbo1a(char *str,t_numb *e);
int		ft_checkbo1a1(char *str,t_numb *e);
int		ft_checkbo21(char *str,t_numb *e);
int		ft_checkbo21a(char *str,t_numb *e);
int		ft_checkbo21a42a(char *str,t_numb *e);
int		ft_checkbo21a42a1(char *str,t_numb *e);
int		ft_checkbo21a42b(char *str,t_numb *e);
int		ft_checkbo21a1(char *str,t_numb *e);
int	ft_putznbr(size_t n,t_numb *e);
int	ft_putznbr1(size_t n,t_numb *e);
int	ft_putznbr2(size_t n,t_numb *e);
int	ft_putznbr2a(size_t n,t_numb *e);
int	ft_putznbr2a1(size_t n,t_numb *e);
int	ft_count3(size_t n);
int	ft_putjnbr(intmax_t n,t_numb *e);
int	ft_putjnbr1(intmax_t n,t_numb *e);
int	ft_putjnbr2(intmax_t n,t_numb *e);
int	ft_putjnbr2a(intmax_t n,t_numb *e);
int	ft_count4(intmax_t n);
int		ft_case2(char **str,t_numb *e,va_list ap);
int		ft_case2a(char ***str,t_numb *e,va_list ap);
int		ft_case2b(char ***str,t_numb *e,va_list ap);
int		ft_case2c(char ***str,t_numb *e,va_list ap);
int		ft_case3(char **str,t_numb *e,va_list ap);
int		ft_case3a(char ***str,t_numb *e,va_list ap);
int		ft_case3b(char ***str,t_numb *e,va_list ap);
int		ft_case3c(char ***str,t_numb *e,va_list ap);
int		ft_case4(char **str,t_numb *e,va_list ap);
int		ft_case4a(char ***str,t_numb *e,va_list ap);
int		ft_case4b(char ***str,t_numb *e,va_list ap);
int		ft_case4c(char ***str,t_numb *e,va_list ap);
int		ft_case4d(char ***str,t_numb *e,va_list ap);




#endif
