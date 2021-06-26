#include "ft_printf.h"

int	ft_print_hex(va_list VaList, int n_bytes)
{
	int		print_int;

	print_int = va_arg(VaList, int);
	ft_putnbr_base(print_int, "0123456789abcdef");
	return (n_bytes);
}

// Modificar BASE para que devuelva la cantidad de caracteres que a escrito.
