#include "ft_printf.h"

int	ft_print_string(va_list VaList, int n_bytes)
{
	char	*aux;
	char	*print_str;

	aux = va_arg(VaList, char *);
	print_str = ft_strdup(aux);
	ft_putstr(print_str);
	n_bytes += ft_strlen(print_str);
	free (print_str);
	return (n_bytes);
}
