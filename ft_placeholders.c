#include "ft_printf.h"

int	ft_calculate_len(unsigned long long nbr, char *base)
{
	static int	n;

	n = 2;
	if (nbr > 0)
	{
		ft_calculate_len(nbr / 16, base);
		n++;
	}
	return (n);
}

static int	ft_width_calculator (t_flag *f, int width, int len)
{
	if ((width == len && width > f->flag_prec) || f->flag_is_negative == 1)
	{
		if (f->flag_is_negative == 1 && f->flag_prec < len)
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

int	ft_print_zero(t_flag *f, int n_bytes, int len)
{
	int	prec;
	int	i;

	i = 0;
	prec = f->flag_prec;
	if ((f->flag_width > len && f->flag_width > prec) || prec > len)
		prec = (prec - len) + 1;
	else if (prec <= len || prec < f->flag_width)
		prec -= len;
	while (++i < prec)
	{
		ft_putnbr(0);
		n_bytes++;
	}
	return (n_bytes);
}

int	ft_print_width_is_zero(t_flag *f, int n_bytes, int len)
{
	int	width;
	int	i;

	i = 0;
	width = f->flag_width;
	if (f->flag_is_prec == 1)
		width = ft_width_calculator(f, width, len);
	else if (f->flag_is_prec == 0 || width > f->flag_prec)
		width -= len;
	else if (width <= f->flag_prec)
		width = 0;
	while (i++ < width)
		n_bytes += write(1, "0", 1);
	return (n_bytes);
}

int	ft_print_spaces(t_flag *f, int n_bytes, int len)
{
	int	width;
	int	i;

	i = 0;
	width = f->flag_width;
	if (f->flag_is_prec == 1)
		width = ft_width_calculator(f, width, len);
	else if (f->flag_is_prec == 0 || width > f->flag_prec)
		width -= len;
	else if (width <= f->flag_prec)
		width = 0;
	while (i++ < width)
		n_bytes += write(1, " ", 1);
	return (n_bytes);
}
