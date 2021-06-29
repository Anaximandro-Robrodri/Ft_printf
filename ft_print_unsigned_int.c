#include "ft_printf.h"

static int ft_unsigned_width_calculator (t_flag *flag, int width, int len)
{
	if ((width == len && width > flag->flag_prec) || flag->flag_is_negative == 1)
		{
			if ((flag->flag_is_negative == 1 && flag->flag_prec < len) ||
				flag->flag_prec < width)
				width -= len;
			else
				width = (width - flag->flag_prec) - 1;
		}
	else if ((width < len && width > flag->flag_prec) ||
			(width > len && width > flag->flag_prec && flag->flag_prec < len))
				width -= len;
	else
		width -= flag->flag_prec;
	return (width);
}

static int	ft_print_unsigned_spaces(t_flag *flag, int n_bytes, int len)
{
	int	width;
	int	i;

	i = 0;
	width = flag->flag_width;
	if (flag->flag_is_prec == 1)
	{
		if ((width >= len && width >= flag->flag_prec) || width < len )
			width =  ft_unsigned_width_calculator(flag, width, len);
		else
		{
			if (flag->flag_prec > width && flag->flag_prec > len && width > len)
				width -= flag->flag_prec;
			else
				width -= len;
		}
	}
	else if (flag->flag_is_prec == 0 || width > flag->flag_prec)
		width -= len;
	else if (width <= flag->flag_prec)
		width = 0;
	while (i++ < width)
		n_bytes += write(1, " ", 1);
	return (n_bytes);
}

static int	ft_treat_positive(long print_int, t_flag *flag, int len, int n_bytes)
{
	if (flag->flag_is_width == 1 && flag->flag_minus == 0)
	{
		if ((flag->flag_zero == 1 && flag->flag_is_prec == 0 && flag->flag_dot == 0))
			n_bytes = ft_print_width_is_zero(flag, n_bytes, len);
		else
			n_bytes = ft_print_unsigned_spaces(flag, n_bytes, len);
	}
	if (flag->flag_is_prec == 1)
		n_bytes = ft_print_zero(flag, n_bytes, len);
	if (flag->flag_dot == 1 && print_int == 0 && flag->flag_is_prec == 0)
		ft_putchar(' ');
	else
		ft_putnbr(print_int);
	if (flag->flag_minus == 1)
		n_bytes = ft_print_unsigned_spaces(flag, n_bytes, len);
	return (n_bytes + len);
}

int	ft_print_unsigned_int(va_list arg, int n_bytes, t_flag *flag)
{
	long				print_int;
	int					len;

	print_int = va_arg(arg, unsigned int);
	if ((print_int == 0 && flag->flag_dot == 1 && flag->flag_is_prec == 0 && flag->flag_is_width == 0))
		return (n_bytes);
	len = ft_int_len(print_int);
	n_bytes = ft_treat_positive(print_int, flag, len, n_bytes);
	return (n_bytes);
}
