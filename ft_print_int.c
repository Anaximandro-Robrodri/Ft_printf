#include "ft_printf.h"

static int	ft_treat_negative(long print, t_flag *f, int len, int n_bytes)
{
	if (f->flag_is_width == 1 && f->flag_minus == 0)
	{
		if (f->flag_zero == 1 && f->flag_is_prec == 0 && f->flag_dot == 0)
		{
			f->flag_put_minus = 1;
			ft_putchar('-');
			n_bytes = ft_print_width_is_zero(f, n_bytes, len);
		}
		else
			n_bytes = ft_print_spaces(f, n_bytes, len);
	}
	if (f->flag_put_minus == 0)
		ft_putchar('-');
	print *= -1;
	if (f->flag_is_prec == 1)
		n_bytes = ft_print_zero(f, n_bytes, len - 1);
	ft_putnbr(print);
	if (f->flag_minus == 1)
		n_bytes = ft_print_spaces(f, n_bytes, len);
	return (n_bytes + len);
}

static int	ft_treat_positive(long print, t_flag *f, int len, int n_bytes)
{
	if (f->flag_is_width == 1 && f->flag_minus == 0)
	{
		if ((f->flag_zero == 1 && f->flag_is_prec == 0 && f->flag_dot == 0))
			n_bytes = ft_print_width_is_zero(f, n_bytes, len);
		else
			n_bytes = ft_print_spaces(f, n_bytes, len);
	}
	if (f->flag_is_prec == 1)
		n_bytes = ft_print_zero(f, n_bytes, len);
	if (f->flag_dot == 1 && print == 0 && f->flag_is_prec == 0)
		ft_putchar(' ');
	else
		ft_putnbr(print);
	if (f->flag_minus == 1)
		n_bytes = ft_print_spaces(f, n_bytes, len);
	return (n_bytes + len);
}

int	ft_print_int(va_list arg, int n_bytes, t_flag *f)
{
	long				print;
	int					len;

	print = va_arg(arg, int);
	if (print < 0)
		f->flag_is_negative = 1;
	if ((print == 0 && f->flag_dot == 1
			&& f->flag_is_prec == 0 && f->flag_is_width == 0))
		return (n_bytes);
	len = ft_int_len(print);
	if (print >= 0)
		n_bytes = ft_treat_positive(print, f, len, n_bytes);
	else
		n_bytes = ft_treat_negative(print, f, len, n_bytes);
	return (n_bytes);
}
