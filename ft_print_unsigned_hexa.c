#include "ft_printf.h"

int	ft_print_unsigned_hexa(va_list VaList, int n_bytes)
{
	unsigned long long print;

	print = va_arg(VaList, unsigned long long);
	ft_putnbr_base_long(print, "0123456789ABCDEF");
	return (n_bytes);
}
