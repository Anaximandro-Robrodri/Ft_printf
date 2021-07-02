#include "ft_printf.h"

int	ft_print_char (va_list arg, int n_bytes, t_flag *f)
{
	int	print_char;

	print_char = va_arg(arg, int);
	if (f->flag_is_width == 1 && f->flag_minus == 0)
		n_bytes = ft_print_spaces(f, n_bytes, 1);
	ft_putchar(print_char);
	if (f->flag_minus == 1)
		n_bytes = ft_print_spaces (f, n_bytes, 1);
	return (++n_bytes);
}
