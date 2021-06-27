#include "ft_printf.h"

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
		{
			if (width == len && width > flag->flag_prec)
				width = (width - flag->flag_prec) - 1;
			else if ((width < len && width > flag->flag_prec) ||
				(width > len && width > flag->flag_prec && flag->flag_prec < len))
				width -= len;
			else
				width -= flag->flag_prec;
		}
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
	{
		ft_putnbr(0);
		n_bytes++;
	}
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
		if ((width >= len && width >= flag->flag_prec) || width < len)
		{
			if (width == len && width > flag->flag_prec)
				width = (width - flag->flag_prec) - 1;
			else if ((width < len && width > flag->flag_prec) ||
				(width > len && width > flag->flag_prec && flag->flag_prec < len))
				width -= len;
			else
				width -= flag->flag_prec;
		}
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
	{
		ft_putchar(' ');
		n_bytes++;
	}
	return (n_bytes);
}

int	ft_print_minus(t_flag *flag, int n_bytes, int len)
{
	int	width;
	int	i;

	i = 0;
	width = flag->flag_width;
	if (flag->flag_is_prec == 1)
	{
		if ((width >= len && width >= flag->flag_prec) || width < len)
		{
			if (width == len && width > flag->flag_prec)
				width = (width - flag->flag_prec) - 1;
			else if ((width < len && width > flag->flag_prec) ||
				(width > len && width > flag->flag_prec && flag->flag_prec < len))
				width -= len;
			else
				width -= flag->flag_prec;
		}
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
	{
		ft_putchar(' ');
		n_bytes++;
	}
	return (n_bytes);
}
