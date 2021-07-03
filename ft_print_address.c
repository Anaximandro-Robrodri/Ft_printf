#include "ft_printf.h"

int	ft_print_address(va_list arg, int n_bytes, t_flag *f)
{
	unsigned long long			print;
	int							len;

	print = va_arg(arg, unsigned long long);
	if (print == 0)
		len = 3;
	else
		len = ft_calculate_len(print, "0123456789abcdef");
	if (f->flag_is_width == 1 && f->flag_minus == 0)
		n_bytes = ft_print_spaces(f, n_bytes, len);
	ft_putstr("0x");
	n_bytes += 2;
	if (print == 0)
		n_bytes += write(1, "0", 1);
	n_bytes += ft_putnbr_base_long(print, "0123456789abcdef");
	if (f->flag_minus == 1)
		n_bytes = ft_print_spaces(f, n_bytes, len);
	return (n_bytes);
}
