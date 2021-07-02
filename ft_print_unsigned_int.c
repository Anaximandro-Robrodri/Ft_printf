#include "ft_printf.h"

static int	ft_unsigned_width_calculator (t_flag *f, int width, int len)
{
	if ((width == len && width > f->flag_prec) || f->flag_is_negative == 1)
	{
		if ((f->flag_is_negative == 1 && f->flag_prec < len)
			|| f->flag_prec < width)
			width -= len;
		else
			width = (width - f->flag_prec) - 1;
	}
	else if ((width < len && width > f->flag_prec)
		|| (width > len && width > f->flag_prec && f->flag_prec < len))
		width -= len;
	else
		width -= f->flag_prec;
	return (width);
}

static int	ft_print_unsigned_spaces(t_flag *flag, int n_bytes, int len)
{
	int	width;
	int	i;

	i = 0;
	width = flag->flag_width;
	if (flag->flag_is_prec == 1)
		width = ft_unsigned_width_calculator(flag, width, len);
	else if (flag->flag_is_prec == 0 || width > flag->flag_prec)
		width -= len;
	else if (width <= flag->flag_prec)
		width = 0;
	while (i++ < width)
		n_bytes += write(1, " ", 1);
	return (n_bytes);
}

static int	ft_treat_positive(long print, t_flag *f, int len, int n_bytes)
{
	if (f->flag_is_width == 1 && f->flag_minus == 0)
	{
		if ((f->flag_zero == 1 && f->flag_is_prec == 0 && f->flag_dot == 0))
			n_bytes = ft_print_width_is_zero(f, n_bytes, len);
		else
			n_bytes = ft_print_unsigned_spaces(f, n_bytes, len);
	}
	if (f->flag_is_prec == 1)
		n_bytes = ft_print_zero(f, n_bytes, len);
	if (f->flag_dot == 1 && print == 0 && f->flag_is_prec == 0)
		ft_putchar(' ');
	else
		ft_putnbr(print);
	if (f->flag_minus == 1)
		n_bytes = ft_print_unsigned_spaces(f, n_bytes, len);
	return (n_bytes + len);
}

int	ft_print_unsigned_int(va_list arg, int n_bytes, t_flag *f)
{
	long				print;
	int					len;

	print = va_arg(arg, unsigned int);
	if ((print == 0 && f->flag_dot == 1
			&& f->flag_is_prec == 0 && f->flag_is_width == 0))
		return (n_bytes);
	len = ft_int_len(print);
	n_bytes = ft_treat_positive(print, f, len, n_bytes);
	return (n_bytes);
}
