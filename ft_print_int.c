#include "ft_printf.h"

static int ft_treat_negative(long print_int, t_flag *flag, int len, int n_bytes)
{
	if (flag->flag_is_width == 1 && flag->flag_minus == 0)
	{
		if (flag->flag_zero == 1 && flag->flag_is_prec == 0  && flag->flag_dot == 0)
		{
			ft_putchar('-');
			n_bytes = ft_print_width_is_zero(flag, n_bytes, len);
		}
		else
			n_bytes = ft_print_spaces(flag, n_bytes, len, print_int);
	}
	if ((flag->flag_zero == 0) || (flag->flag_zero == 1 && flag->flag_is_prec == 1) ||
		(flag->flag_zero == 1 && flag->flag_dot == 1))
		ft_putchar('-');
	print_int *= -1;
	flag->flag_is_negative = 1;
	if (flag->flag_is_prec == 1)
		n_bytes = ft_print_zero(flag, n_bytes, len - 1);
	ft_putnbr(print_int);
	if (flag->flag_minus == 1)
		n_bytes = ft_print_minus(flag, n_bytes, len);
	return (n_bytes + len);
}

static int	ft_treat_positive(long print_int, t_flag *flag, int len, int n_bytes)
{
	if (flag->flag_is_width == 1 && flag->flag_minus == 0)
	{
		if ((flag->flag_zero == 1 && flag->flag_is_prec == 0 && flag->flag_dot == 0))
			n_bytes = ft_print_width_is_zero(flag, n_bytes, len);
		else
			n_bytes = ft_print_spaces(flag, n_bytes, len, print_int);
	}
	if (flag->flag_is_prec == 1)
		n_bytes = ft_print_zero(flag, n_bytes, len);
	if (flag->flag_dot == 1 && print_int == 0 && flag->flag_is_prec == 0)
		ft_putchar(' ');
	else
		ft_putnbr(print_int);
	if (flag->flag_minus == 1)
		n_bytes = ft_print_minus(flag, n_bytes, len);
	return (n_bytes + len);
}

int	ft_print_int(va_list VaList, int n_bytes, t_flag *flag)
{
	long				print_int;
	int					len;

	print_int = va_arg(VaList, int);
	if ((print_int == 0 && flag->flag_dot == 1 && flag->flag_is_prec == 0 && flag->flag_is_width == 0))
		return (n_bytes);
	len = ft_int_len(print_int);
	if (print_int >= 0)
		n_bytes = ft_treat_positive(print_int, flag, len, n_bytes);
	else
		n_bytes = ft_treat_negative(print_int, flag, len, n_bytes);
	return (n_bytes);
}
