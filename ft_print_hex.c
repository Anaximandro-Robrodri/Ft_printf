#include "ft_printf.h"

int	ft_print_hex(va_list arg, int n_bytes, t_flag *f)
{
	unsigned int			print;
	int						len;

	print = va_arg(arg, unsigned int);
	if (print == 0 && f->flag_dot == 0)
		len = 1;
	else
		len = (ft_calculate_len(print, "0123456789abcdef")) - 2;
	if (f->flag_is_width == 1 && f->flag_minus == 0)
	{
		if ((f->flag_zero == 1 && f->flag_is_prec == 0 && f->flag_dot == 0))
			n_bytes = ft_print_width_is_zero(f, n_bytes, len);
		else
			n_bytes = ft_print_spaces(f, n_bytes, len);
	}
	if (f->flag_is_prec == 1)
		n_bytes = ft_print_zero(f, n_bytes, len);
	if (print == 0 && f->flag_dot == 0)
		n_bytes += write(1, "0", 1);
	else
		n_bytes += ft_putnbr_base_long(print, "0123456789abcdef");
	if (f->flag_minus == 1)
		n_bytes = ft_print_spaces(f, n_bytes, len);
	return (n_bytes);
}
