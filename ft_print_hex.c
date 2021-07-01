#include "ft_printf.h"

int	ft_print_hex(va_list arg, int n_bytes, t_flag *flag)
{
	unsigned int			print;
	int						len;

	print = va_arg(arg, unsigned int);
	if (print == 0 && flag->flag_dot == 0)
		len = 1;
	else
		len = (ft_calculate_len(print, "0123456789abcdef")) - 2;
	if (flag->flag_is_width == 1 && flag->flag_minus == 0)
	{
		if ((flag->flag_zero == 1 && flag->flag_is_prec == 0 && flag->flag_dot == 0))
			n_bytes =  ft_print_width_is_zero(flag, n_bytes, len);
		else
			n_bytes = ft_print_spaces(flag, n_bytes, len);
	}
	if (flag->flag_is_prec == 1)
		n_bytes = ft_print_zero(flag, n_bytes, len);
	if (print ==  0 && flag->flag_dot == 0)
		n_bytes += write(1, "0", 1);
	else
		n_bytes += ft_putnbr_base_long(print, "0123456789abcdef");
	if (flag->flag_minus == 1)
		n_bytes = ft_print_spaces(flag, n_bytes, len);
	return (n_bytes);
}
