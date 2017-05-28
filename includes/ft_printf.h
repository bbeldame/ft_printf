/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 19:54:10 by msakwins          #+#    #+#             */
/*   Updated: 2017/05/28 19:38:48 by msakwins         ###   ########.fr       */
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

typedef struct	s_modifiers
{
	size_t		mod;
	size_t		flag;
	size_t		plus;
	size_t		minus;
	size_t		sharp;
	size_t		space;
	size_t		zero;
	size_t		preci;
	size_t		digit;
	size_t		period;
	size_t		cap;
	size_t		percent;
}				t_modif;

size_t			ft_printf(const char *format, ...);
size_t			parse(va_list argl, const char *format);
size_t			handle(char c, va_list argl, t_modif *modi);
size_t			search_format(va_list argl, char l, t_modif *modi);
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
int				get_octlen(uintmax_t nb);
void			ft_putnstr(const char *s, size_t n);
int				ft_putwstr(wchar_t *wstr);
int				ft_countbits(wchar_t value);
intmax_t		lenght_mod(va_list argl, t_modif *modi);
uintmax_t		ulenght_mod(va_list argl, t_modif *modi);
size_t			handle_s(va_list argl, t_modif *modi);
size_t			handle_d(va_list argl, t_modif *modi);
size_t			handle_x(va_list argl, t_modif *modi);
size_t			handle_p(va_list argl, t_modif *modi);
size_t			handle_o(va_list argl, t_modif *modi);
size_t			handle_u(va_list argl, t_modif *modi);
size_t			handle_w(va_list argl, t_modif *modi);
size_t			handle_ws(va_list argl, t_modif *modi);
size_t			diouflag(uintmax_t nb, t_modif *modi,
		size_t neg, char *base);
size_t			handle_mod(t_modif *modi, size_t neg,
		size_t nblen, size_t negok);
size_t			flagzero(t_modif *modi, size_t neg,
		size_t nblen, size_t negok);
size_t			digitorpreci(t_modif *modi, size_t neg,
		size_t nblen, size_t negok);
size_t			handflag(t_modif *modi);
size_t			padding(size_t nblen, size_t dig, char p);
size_t			paddingchar(size_t dig, char p);
int				ft_putwchar11(unsigned int mask1,
		unsigned char octet, wchar_t value);
int				ft_putwchar16(unsigned int mask2,
		unsigned char octet, wchar_t value);
int				ft_putwchar32(unsigned int mask3,
		unsigned char octet, wchar_t value);
void			init_all(t_modif *modi);

#endif
