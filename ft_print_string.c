#include "ft_printf.h"

static int	ft_width_analyze(t_flag *f, int width, int len)
{
	if (f->flag_dot == 1)
		width = f->flag_width;
	else if (((width > f->flag_prec && width < len) || f->flag_prec < len))
	{
		if (width < len || f->flag_prec < len)
			width -= f->flag_prec;
		else
			width -= len;
	}
	else
		width -= len;
	return (width);
}

static int	ft_print_string_spaces(t_flag *f, int n_bytes, int len)
{
	int	width;
	int	i;

	i = 0;
	width = f->flag_width;
	if (f->flag_is_prec == 1 || f->flag_dot == 1)
		width = ft_width_analyze(f, width, len);
	else
		width -= len;
	while (i++ < width)
		n_bytes += write(1, " ", 1);
	return (n_bytes);
}

int	ft_print_string(va_list arg, int n_bytes, t_flag *f)
{
	char	*print_str;
	int		len;
	int		prec;

	print_str = va_arg(arg, char *);
	if (!print_str)
		print_str = "(null)";
	prec = f->flag_prec;
	len = ft_strlen(print_str);
	if (f->flag_is_width == 1 && f->flag_minus == 0)
		n_bytes = ft_print_string_spaces(f, n_bytes, len);
	if (f->flag_is_prec == 1 && f->flag_dot == 0)
		while (prec-- && *print_str)
			n_bytes += write(1, &*print_str++, 1);
	else if (f->flag_dot == 0)
	{
		ft_putstr(print_str);
		n_bytes += len;
	}
	if (f->flag_minus == 1)
		n_bytes = ft_print_string_spaces(f, n_bytes, len);
	return (n_bytes);
}
