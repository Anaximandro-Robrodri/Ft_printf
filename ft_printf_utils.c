#include "ft_printf.h"

void	ft_init_flags(t_flag *flag)
{
	flag->flag_dot = 0;
	flag->flag_prec = 0;
	flag->flag_minus = 0;
	flag->flag_width = 0;
	flag->flag_zero = 0;
	flag->flag_is_width = 0;
	flag->flag_is_prec = 0;
	flag->flag_is_negative = 0;
	flag->flag_put_minus = 0;
}
static const char *ft_load_prec(const char *str, t_flag *flag, va_list VaList)
{
	flag->flag_prec = va_arg(VaList, int);
	if (flag->flag_prec > 0)
		flag->flag_is_prec = 1;
	if (flag->flag_prec == 0)
		flag->flag_dot = 1;
	return (str + 1);
}

static void ft_load_width_astherisk(t_flag *flag, va_list VaList)
{

	flag->flag_width = va_arg(VaList, int);
	if (flag->flag_width > 0)
		flag->flag_is_width = 1;
	else if (flag->flag_width < 0)
	{
		flag->flag_is_width = 1;
		flag->flag_zero = 0;
		flag->flag_minus = 1;
		flag->flag_width *= -1;
	}
}

const char *ft_check_flags(const char *str, t_flag *flag, va_list VaList)
{
	if (*str == '-')
	{
		flag->flag_zero = 0;
		flag->flag_minus = 1;
	}
	if (*str == '0' && flag->flag_minus == 0)
		flag->flag_zero = 1;
	else if (*str == '.' && *(str + 1) == '*')
		str = ft_load_prec(str, flag, VaList);
	else if (*str == '*')
		ft_load_width_astherisk(flag, VaList);
	else if (*str == '.' || ft_isdigit(*str))
		str = ft_flag_is_num(str, flag);
	return (str + 1);
}

const char *ft_flag_is_num(const char *str, t_flag *flag)
{
	if (*str == '.')
		str = ft_load_prec_num(++str, flag);
	else
		str = ft_load_width_num(str, flag);
	return (str - 1);
}
