#include "ft_printf.h"

int	ft_print_char (va_list arg, int n_bytes, t_flag *flag)
{
	int	print_char;

	print_char = va_arg(arg, int);
	if (flag->flag_is_width == 1 && flag->flag_minus == 0)
		n_bytes = ft_print_spaces(flag, n_bytes, 1, 1);
	ft_putchar(print_char);
	if (flag->flag_minus == 1)
		n_bytes = ft_print_spaces (flag, n_bytes, 1, 1);
	return (++n_bytes);
}
