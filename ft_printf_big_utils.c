#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c < 65) || (c > 90 && c < 97) || (c > 122))
	{
		return (0);
	}
	return (1);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		(((unsigned char *)b)[i]) = (unsigned char) c;
		i++;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;

	ptr = malloc (size * count);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, size * count);
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_isdigit (int c)
{
	if ((c < 48) || (c > 57))
	{
		return (0);
	}
	return (1);
}

void	ft_putchar(char c)
{
	write (1, &c, sizeof(char));
}

void	ft_putnbr(int n)
{
	char			z;
	unsigned int	nb;

	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write (1, "-", sizeof(char));
		n = n * (-1);
	}
	nb = (unsigned int) n;
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		z = '0' + (nb % 10);
		write (1, &z, sizeof(char));
	}
	else
	{
		z = nb + '0';
		write (1, &z, sizeof(char));
	}
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write (1, &s[i++], sizeof(char));
	}
}

static int	gest_errors(char *base)
{
	int	d;
	int	e;
	int	f;

	e = 0;
	d = ft_strlen(base);
	f = 0;
	if (d <= 1)
		return (1);
	while (base[e] != '\0' && base[f] != '\0' && d > 1 )
	{
		while (base[e] != '\0' && base[f] != '\0')
		{
			if ((base[e] == base[f] && e != f) || (base[f] == '+'\
				|| base[f] == '-'))
			{
				return (e);
			}
			f++;
		}
		e++;
		f = 0;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	a;
	int	b;

	if (gest_errors(base) == 0)
	{
		a = ft_strlen(base);
		if (nbr > 0)
		{
			ft_putnbr_base(nbr / a, base);
			b = nbr % a;
			write(1, &base[b], 1);
		}
		if (nbr < 0)
		{
			write(1, "-", 1);
			ft_putnbr_base(-nbr, base);
		}
	}
}

void	ft_putnbr_base_long(unsigned long long nbr, char *base)
{
	int	a;
	int	b;

	if (gest_errors(base) == 0)
	{
		a = ft_strlen(base);
		if (nbr > 0)
		{
			ft_putnbr_base_long(nbr / a, base);
			b = nbr % a;
			write(1, &base[b], 1);
		}
		if (nbr < 0)
		{
			write(1, "-", 1);
			ft_putnbr_base_long(-nbr, base);
		}
	}
}

static char	*ft_strcpy (char *dest, const char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char		*str;
	int			i;

	i = ft_strlen(s1);
	str = ft_calloc (i + 1, sizeof(char));
	if (str == 0)
		return (0);
	return (ft_strcpy(str, s1));
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned int	nb;
	int				sign;

	i = 0;
	nb = 0;
	sign = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' \
			|| str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nb = (nb * 10) + (str[i++] - '0');
	if (nb > 2147483647 && !sign)
		return (-1);
	else if (nb > 2147483648 && sign)
		return (0);
	else if (sign)
		return ((int)nb * -1);
	return ((int) nb);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_int_len(n);
	str = malloc(sizeof(char) * i + 1);
	if (str == 0)
		return (0);
	str[i--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 9 && i > 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	str[i] = n + '0';
	return (str);
}

