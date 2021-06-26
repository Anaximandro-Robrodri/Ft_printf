#include "ft_printf.h"

int	ft_print_char (va_list VaList, int n_bytes)
{
	int	print_int;

	print_int = va_arg(VaList, int);
	ft_putchar(print_int);
	return (++n_bytes);
}
