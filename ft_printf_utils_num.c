#include "ft_printf.h"

int	ft_int_len(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

const char	*ft_load_prec_num(const char *str, t_flag *flag)
{
	flag->flag_prec = ft_atoi(str);
	if (flag->flag_prec > 0)
		flag->flag_is_prec = 1;
	flag->flag_dot = 1;
	while (ft_isdigit(*str))
		str++;
	return (str);
}

const char *ft_load_width_num(const char *str, t_flag *flag)
{
	flag->flag_width = ft_atoi(str);
	if (flag->flag_width > 0)
		flag->flag_is_width = 1;
	while (ft_isdigit(*str))
		str++;
	return (str);
}
