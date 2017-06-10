/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 19:54:10 by msakwins          #+#    #+#             */
/*   Updated: 2017/06/10 20:20:05 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <locale.h>
# include <inttypes.h>
# include "../libft/libft.h"
# define HEXA_MIN "0123456789abcdef"
# define HEXA_CAP "0123456789ABCDEF"
# define BASE_10 "0123456789"
# define BASE_8 "01234567"
# define BASE_2 "01"
# define BLACK "\033[22;30m"
# define WHITE "\033[01;37m"
# define GRAY "\033[22;37m"
# define DARKGRAY "\033[01;30m"
# define YELLOW "\033[01;33m"
# define BLUE "\033[22;34m"
# define LIGHTBLUE "\033[01;34m"
# define MAGENTA "\033[22;35m"
# define LIGHTMAGENTA "\033[01;35m"
# define RED "\033[22;31m"
# define LIGHTRED "\033[01;31m"
# define GREEN "\033[22;32m"
# define LIGHTGREEN "\033[01;32m"
# define CYAN "\033[22;36m"
# define LIGHTCYAN "\033[01;36m"
# define NONE "\033[0m"

# define LEN modi->len
# define MOD modi->mod
# define FLAG modi->flag
# define PLUS modi->plus
# define MINUS modi->minus
# define SHARP modi->sharp
# define SPACE modi->space
# define ZERO modi->zero
# define PRECI modi->preci
# define DIGIT modi->digit
# define PERIOD modi->period
# define CAP modi->cap
# define NEG modi->neg

typedef struct	s_modifiers
{
	int			len;
	int			mod;
	int			flag;
	int			plus;
	int			minus;
	int			sharp;
	int			space;
	int			zero;
	int			preci;
	int			digit;
	int			period;
	int			cap;
	int			percent;
	int			hexa;
	int			neg;
}				t_modif;

int				ft_printf(const char *format, ...);
int				parse(va_list argl, const char *format, t_modif *modi);
void			handle(char c, va_list argl, t_modif *modi);
void			search_format(va_list argl, char l, t_modif *modi);
int				parse_flags(const char *format, int i, t_modif *modi);
void			search_mod(const char *format, int i, t_modif *modi);
void			search_flag(const char *format, int i, t_modif *modi);
int				search_digit(const char *format, int i, t_modif *modi);
int				search_period(const char *format, int i, t_modif *modi);
int				search_percent(const char *format, int i, t_modif *modi);
char			*itoa_base(uintmax_t n, char *base);
char			*ft_strchr(const char *str, int c);
int				ft_putwchar(wchar_t value, int size);
char			*ft_strdup(const char *s1);
void			ft_putllnbr(intmax_t nb);
void			ft_putnbr_base(uintmax_t nb, char *base);
int				get_intlen(intmax_t nb);
int				get_uintlen(uintmax_t nb, char *base);
int				get_charlen(char c);
int				get_strlen(char *str);
int				get_wstrlen(wchar_t *wstr);
int				get_preciw(wchar_t *wstr, int n);
int				get_clen(int size);
int				get_octlen(uintmax_t nb);
void			ft_putnstr(const char *s, size_t n);
int				ft_putwstr(wchar_t *wstr);
int				ft_putwnstr(wchar_t *wstr, int n);
int				ft_countbits(wchar_t value);
intmax_t		lenght_mod(va_list argl, t_modif *modi);
uintmax_t		ulenght_mod(va_list argl, t_modif *modi);
size_t			handle_s(va_list argl, t_modif *modi);
int				handle_d(va_list argl, t_modif *modi);
int				handle_x(va_list argl, t_modif *modi);
int				handle_p(va_list argl, t_modif *modi);
int				handle_o(va_list argl, t_modif *modi);
int				handle_u(va_list argl, t_modif *modi);
int				handle_w(va_list argl, t_modif *modi);
int				handle_ws(va_list argl, t_modif *modi);
int				handle_bd(t_modif *modi, char c);
void			width_errors(t_modif *modi, int nblen);
void			width_errs(t_modif *modi, int sblen);
void			apply_flags(t_modif *modi);
void			apply_digits(t_modif *modi);
void			apply_preci(t_modif *modi);
int				padding(int dig, char p);
size_t			paddingchar(size_t dig, char p);
int				ft_putwchar11(unsigned int mask1,
		unsigned char octet, wchar_t value);
int				ft_putwchar16(unsigned int mask2,
		unsigned char octet, wchar_t value);
int				ft_putwchar32(unsigned int mask3,
		unsigned char octet, wchar_t value);
void			init_all(t_modif *modi);
uintmax_t		to_unsigned_char_modulo(uintmax_t nbr);
size_t			handle_b(va_list argl, t_modif *modi);
int				period_zero(intmax_t nb, t_modif *modi);

#endif
