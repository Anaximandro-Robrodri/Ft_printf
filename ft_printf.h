#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "./libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

typedef struct	s_flag
{
	int	    flag_dot;
	int	    flag_minus;
	int	    flag_zero;
	int	    flag_width;
	int	    flag_prec;
	int		flag_is_prec;
	int		flag_is_width;
	int		flag_is_negative;
	int		flag_put_minus;
}	t_flag;

int					ft_printf(const char *str, ...);
int					ft_print_string(va_list VaList, int n_bytes, t_flag *flag);
int					ft_print_char (va_list arg, int n_bytes, t_flag *flag);
int					ft_print_int(va_list VaList, int n_bytes, t_flag *flag);
int					ft_print_hex(va_list VaList, int n_bytes, t_flag *flag);
int					ft_print_address(va_list VaList, int n_bytes, t_flag *flag);
int					ft_print_percent(int n_bytes);
int					ft_print_unsigned_hexa(va_list VaList, int n_bytes, t_flag *flag);
int					ft_print_unsigned_int(va_list arg, int n_bytes, t_flag *flag);
int					ft_calculate_len(unsigned long long nbr, char *base);
void				ft_init_flags(t_flag *flag);
int					ft_int_len(long n);
const char			*ft_check_flags(const char *str, t_flag *flag, va_list VaList);
const char			*ft_flag_is_num(const char *str, t_flag *flag);
const char			*ft_load_prec_num(const char *str, t_flag *flag);
const char			*ft_load_width_num(const char *str, t_flag *flag);
int					ft_print_zero(t_flag *flag, int n_bytes, int len);
int					ft_print_width_is_zero(t_flag *flag, int n_bytes, int len);
int					ft_print_spaces(t_flag *flag, int n_bytes, int len);

#endif
