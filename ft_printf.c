#include "ft_printf.h"
#include <stdio.h>

static int	ft_args(const char **str, va_list arg, int n_bytes, t_flag *flag)
{
	if (**str == 's')
		return (ft_print_string(arg, n_bytes, flag));
	else if (**str == 'c')
		return (ft_print_char(arg, n_bytes, flag));
	else if (**str == 'i' || **str == 'd')
		return (ft_print_int(arg, n_bytes, flag));
	else if (**str == 'u')
		return (ft_print_unsigned_int(arg, n_bytes, flag));
	else if (**str == 'x')
		return (ft_print_hex(arg, n_bytes, flag));
	else if (**str == 'p')
		return (ft_print_address(arg, n_bytes, flag));
	else if (**str == 'X')
		return (ft_print_unsigned_hexa(arg, n_bytes, flag));
	else if (**str == '%')
		return (ft_print_percent(n_bytes));
	return (0);
}

static const char	*ft_is_flag(const char *str, t_flag *flag, va_list arg)
{
	while (!ft_isalpha(*str) && *str != '%')
		str = ft_check_flags(str, flag, arg);
	return (str);
}

int	ft_printf(const char *str, ...)
{
	int			n_bytes;
	va_list		arg;
	t_flag		flag;

	n_bytes = 0;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_init_flags(&flag);
			str = ft_is_flag(str, &flag, arg);
			n_bytes = ft_args(&str, arg, n_bytes, &flag);
		}
		else
		{
			ft_putchar(*str);
			n_bytes++;
		}
		str++;
	}
	va_end (arg);
	return (n_bytes);
}
