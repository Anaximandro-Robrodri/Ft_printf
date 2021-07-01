#include "ft_printf.h"
#include <limits.h>

static int ft_print_pointer_spaces(t_flag *flag, int n_bytes, int len, int  print)
{
	int	width;
	int	i;

	i = 0;
	width = flag->flag_width;
	if (print < 0)
		width = 0;
	else
		width -= len;
	while (i++ < width)
		n_bytes += write(1, " ", 1);
	return (n_bytes);
}

int	ft_print_address(va_list arg, int n_bytes, t_flag *flag)
{
	unsigned long long			print;
	int							len;

	print = va_arg(arg, unsigned long long);
	if (print == 0)
		len = 3;
	else
		len = ft_calculate_len(print, "0123456789abcdef");
	if (flag->flag_is_width == 1 && flag->flag_minus == 0)
		n_bytes = ft_print_pointer_spaces(flag, n_bytes, len, print);
	ft_putstr("0x");
	n_bytes += 2;
	if (print == 0)
		n_bytes += write(1, "0", 1);
	n_bytes += ft_putnbr_base_long(print, "0123456789abcdef");
	if (flag->flag_minus == 1)
		n_bytes = ft_print_pointer_spaces(flag, n_bytes, len, print);
	return (n_bytes);
}
