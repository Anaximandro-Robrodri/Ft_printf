#include "ft_printf.h"

int ft_calculate_len(unsigned long long nbr, char *base)
{
	static int 	n;

	n = 2;
	if (nbr > 0)
	{
		ft_calculate_len(nbr / 16, base);
		n++;
	}
	return (n);
}

static int ft_width_calculator (t_flag *flag, int width, int len)
{
	if ((width == len && width > flag->flag_prec) || flag->flag_is_negative == 1)
		{
			if (flag->flag_is_negative == 1 && flag->flag_prec < len)
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

int	ft_print_zero(t_flag *flag, int n_bytes, int len)
{
	int	prec;
	int	i;

	i = 0;
	prec = flag->flag_prec;
	if ((flag->flag_width > len && flag->flag_width > prec) || prec > len)
		prec = (prec - len) + 1;
	else if (prec <= len || prec < flag->flag_width)
		prec -= len;
	while (++i < prec)
	{
		ft_putnbr(0);
		n_bytes++;
	}
	return (n_bytes);
}

int	ft_print_width_is_zero(t_flag *flag, int n_bytes, int len)
{
	int	width;
	int	i;

	i = 0;
	width = flag->flag_width;
	if (flag->flag_is_prec == 1)
	{
		if ((width >= len && width >= flag->flag_prec) || width < len)
			width = ft_width_calculator(flag, width, len);
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
		n_bytes += write(1, "0" ,1);
	return (n_bytes);
}

int	ft_print_spaces(t_flag *flag, int n_bytes, int len)
{
	int	width;
	int	i;

	i = 0;
	width = flag->flag_width;
	if (flag->flag_is_prec == 1)
	{
		if ((width >= len && width >= flag->flag_prec) || width < len )
			width =  ft_width_calculator(flag, width, len);
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
