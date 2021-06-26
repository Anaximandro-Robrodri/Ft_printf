#include "ft_printf.h"

int	ft_print_address(va_list VaList, int n_bytes)
{
	unsigned long long print;

	print = va_arg(VaList, unsigned long long);
	ft_putstr("0x");
	ft_putnbr_base_long(print, "0123456789abcdef");
	return (n_bytes);
}
