#include "ft_printf.h"

static void ft_calculate_len(int nbr, char *base, int *len)
{
	int	a;
	int	b;

	a = ft_strlen(base);
	if (nbr > 0)
	{
		ft_calculate_len(nbr / a, base, len);
		b = nbr % a;
		(*len)++;
	}
	if (nbr < 0)
	{
		ft_calculate_len(-nbr, base, len);
		(*len)++;
	}
}

int	ft_print_address(va_list arg, int n_bytes, t_flag *flag)
{
	unsigned long long 		print;
	int						len;

	print = va_arg(arg, unsigned long long);
	len = 0;
	ft_calculate_len(print, "0123456789abcdef", &len);
	ft_printf("\nSoy la len %i\n", len);
	if (flag->flag_is_width == 1 && flag->flag_minus == 0)
		n_bytes = ft_print_spaces(flag, n_bytes, len);
	ft_putstr("0x");
	n_bytes += 2;
	n_bytes += ft_putnbr_base_long(print, "0123456789abcdef");
	if (flag->flag_minus == 1)
		n_bytes = ft_print_spaces(flag, n_bytes, len);
	return (n_bytes);
}
