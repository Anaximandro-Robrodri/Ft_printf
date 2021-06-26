
#include "ft_printf.h"
#include <limits.h>

static int	ft_check_args(const char **str, va_list VaList, int n_bytes, t_flag *flag)
{
/*	if (**str == 's')
		return (ft_print_string(VaList, n_bytes));
	else if (**str == 'c')
		return (ft_print_char(VaList, n_bytes));*/
	if (**str == 'i' || **str == 'd')
		return (ft_print_int(VaList, n_bytes, flag));
/*	else if (**str == 'x')
		return (ft_print_hex(VaList, n_bytes));
	else if (**str == 'p')
		return (ft_print_address(VaList, n_bytes));
	else if (**str == 'X')
		return (ft_print_unsigned_hexa(VaList, n_bytes));*/
	else if (**str == '%')
		return (ft_print_percent(n_bytes));
	return (0);
}

static const char	*ft_is_flag(const char *str, t_flag *flag, va_list VaList)
{
	while (*str == '-' || *str == '*' || (*str == '.' && (*(str + 1) == '*')) || *str == '0')
		str = ft_check_flags(str, flag, VaList);
	while (*str == '.' || ft_isdigit(*str))
		str = ft_flag_is_num(str, flag);
	return (str);
}

int	ft_printf(const char *str, ...)
{
	int			n_bytes;
	va_list		VaList;
	t_flag		flag;

	n_bytes = 0;
	va_start(VaList, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_init_flags(&flag);
			str = ft_is_flag(str, &flag, VaList);
			n_bytes = ft_check_args(&str, VaList, n_bytes, &flag);
		}
		else
		{
			ft_putchar(*str);
			n_bytes++;
		}
		str++;
	}
	va_end(VaList);
	return(n_bytes);
}

int main()
{
    int i = ft_printf(" %-30.20d ", -10);
    printf("\n%i\n", i);
    int d = printf(" %-30.20d ", -10);
    printf("\n%d", d);
}

/*int main()
{
//	int i;
//	unsigned int hexa = -245612;
//	int hex = -245612;
//	char a[] = "Do";
//	char car = 'z';
	int d = 2147483647;

	printf("\nPARA INTS\n");
	printf("FLAG = *\n");
	ft_printf("\n%13d", d);
	ft_printf("\n%.13d", d);
	ft_printf("\n%40.30d", d);
	ft_printf("\n%*.*d",25, 20, d);
	ft_printf("\n%*d",13, d);
	printf("\n--------------------------");
	printf("\n%13d", d);
	printf("\n%.13d", d);
	printf("\n%40.30d", d);
	printf("\n%*.*d",25, 20, d);
	printf("\n%*d",13, d);
	printf("\nFLAG = 0\n");
	ft_printf("\n%0.13d", d);
	ft_printf("\n%013d", d);
	ft_printf("\n%040.30d \n%013d \n%040.30d", d, d, d);
	ft_printf("\n%40.30d", d);
	ft_printf("\n%0*.*d",25, 20, d);
	ft_printf("\n%05.*d",13, d);
	ft_printf("\n%0*.15d",20, d);
	printf("\n--------------------------");
	printf("\n%013d", d);
	printf("\n%0.13d", d);
	printf("\n%040.30d \n%013d \n%040.30d", d, d, d);
	printf("\n%40.30d", d);
	printf("\n%0*.*d",25, 20, d);
	printf("\n%05.*d",13, d);
	printf("\n%0*.15d",20, d);
	printf("\nFLAG = -\n");
	ft_printf("\n%-013d", d);
	ft_printf("\n%-40.30d", d);
	ft_printf("\n%-*.*d",30, 20, d);
	printf("\n--------------------------");
	printf("\n%-13d", d);
	printf("\n%-40.30d", d);
	printf("\n%-*.*d",30, 20, d);
//	printf("\nPARA CHARS\n");
//	printf("\n%05.*d %05.*d",6, 6, d, d);
//	ft_printf("\n///////////////////////////////////////");
//	ft_printf("\n%05.*d %05.*d",6, 6, d, d);
}*/
