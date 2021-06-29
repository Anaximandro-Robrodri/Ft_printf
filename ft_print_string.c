#include "ft_printf.h"

static int	ft_print_string_spaces(t_flag *flag, int n_bytes, int len)
{
	int	width;
	int	i;

	i = 0;
	width = flag->flag_width;
	if (flag->flag_is_prec == 1)
		{
			if (width > flag->flag_prec)
				width -= flag->flag_prec;
			else
				width -= len;
		}
	else if (width >= len || flag->flag_dot == 1)
		width -= len;
	else if (width < len)
		width = 0;
	while (i++ < width)
		n_bytes = write(1, " ", 1);
	return (n_bytes);
}

int	ft_print_string(va_list VaList, int n_bytes, t_flag *flag)
{
	char	*print_str;
	int		len;
	int		prec;

	print_str = va_arg(VaList, char *);
	prec = flag->flag_prec;
	len = ft_strlen(print_str);
	if (flag->flag_is_width == 1 && flag->flag_minus == 0)
		n_bytes = ft_print_string_spaces(flag, n_bytes, len);
	if (flag->flag_is_prec == 1 && flag->flag_dot == 0)
		while (prec-- && *print_str)
			write(1, &*print_str++, 1);
	else if (flag->flag_dot == 0)
		ft_putstr(print_str);
	if (flag->flag_minus == 1)
		n_bytes = ft_print_string_spaces(flag, n_bytes, len);
	return (n_bytes + len);
}
