#include "ft_printf.h"

int	ft_print_percent(int n_bytes)
{
	ft_putchar('%');
	return (++n_bytes);
}
