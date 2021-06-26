#include "ft_printf.h"

static int	ft_print_zero(t_flag *flag, int n_bytes, int len, int print_int)
{
	int	i;

	i = 0;
	if (flag->flag_minus == 1)
	{
		if (print_int == 0 && flag->flag_width >= flag->flag_prec)
			i++;
		if (flag->flag_prec > flag->flag_width)
		flag->flag_prec = 0;
	}
	if (flag->flag_prec < flag->flag_width || flag->flag_prec < len)
		flag->flag_prec -= len;
	while (i < flag->flag_prec)
	{
		ft_putnbr(0);
		n_bytes++;
		i++;
	}
	return (n_bytes);
}

static	int	ft_print_spaces(t_flag *flag, int n_bytes, int len, int print_int)
{
	int i;

	i = 0;
	if (flag->flag_width >= len)
	{
		if (flag->flag_is_prec == 0 || (flag->flag_width > flag->flag_prec && print_int < 0))
			flag->flag_width -= len;
		if (flag->flag_width > flag->flag_prec)
			flag->flag_width -= flag->flag_prec;
		else if (flag->flag_width <= flag->flag_prec)
			flag->flag_width = 0;
	}
	else
		flag->flag_width -= len;
	while (i < flag->flag_width)
	{
		ft_putchar(' ');
		n_bytes++;
		i++;
	}
	return (n_bytes);
}

static int	ft_print_minus(t_flag *flag, int n_bytes, int len)
{
	int i;

	i = 0;
	if (flag->flag_prec < 0)
		flag->flag_prec *= -1;
	if (flag->flag_width >= len)
	{
		if (flag->flag_is_prec == 0 || flag->flag_prec > len)
			flag->flag_width -= len;
		if (flag->flag_width > flag->flag_prec)
		{
			if (flag->flag_prec > 0)
				flag->flag_width -= flag->flag_prec;
		}
		else if (flag->flag_width <= flag->flag_prec)
			flag->flag_width = 0;
	}
	while (i < flag->flag_width)
	{
		ft_putchar(' ');
		n_bytes++;
		i++;
	}
	return (n_bytes);
}

static int ft_treat_negative(int print_int, t_flag *flag, int len, int n_bytes)
{
	if (flag->flag_is_width == 1 && flag->flag_minus == 0)
		n_bytes = ft_print_spaces(flag, n_bytes, len, print_int);
	ft_putchar('-');
	print_int *= -1;
	if (flag->flag_is_prec == 1)
		n_bytes = ft_print_zero(flag, n_bytes, len, print_int);
	ft_putnbr(print_int);
	if (flag->flag_minus == 1)
		n_bytes = ft_print_minus(flag, n_bytes, len);
	return (n_bytes + len);
}

static int	ft_treat_positive(int print_int, t_flag *flag, int len, int n_bytes)
{
	if (flag->flag_is_width == 1 && flag->flag_minus == 0)
		n_bytes = ft_print_spaces(flag, n_bytes, len, print_int);
	if (flag->flag_is_prec == 1)
		n_bytes = ft_print_zero(flag, n_bytes, len, print_int);
	ft_putnbr(print_int);
	if (flag->flag_minus == 1)
		n_bytes = ft_print_minus(flag, n_bytes, len);
	return (n_bytes + len);
}

int	ft_print_int(va_list VaList, int n_bytes, t_flag *flag)
{
	int				print_int;
	int				len;

	print_int = va_arg(VaList, int);
	if ((print_int == 0 && flag->flag_dot == 1 && flag->flag_is_prec == 0))
		return (n_bytes);
	len = ft_int_len(print_int);
	if (print_int >= 0)
		n_bytes = ft_treat_positive(print_int, flag, len, n_bytes);
	else
		n_bytes = ft_treat_negative(print_int, flag, len, n_bytes);
	return (n_bytes);
}
