/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:55:44 by robrodri          #+#    #+#             */
/*   Updated: 2021/05/30 15:55:45 by robrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static char	**ft_allocate(char **dst)
{
	dst = ft_calloc (1, sizeof(char **));
	return (dst);
}

static void	ft_put_str (char **dst, char *src, int n, char c)
{
	char	*aux;
	int		i;

	if (n == 1)
	{
		dst[0] = ft_strdup(src);
	}
	else
	{
		i = 0;
		while (i < n - 1)
		{
			aux = ft_strchr(src, c);
			dst[i] = ft_substr(src, 0, (aux - src));
			while (*aux == c)
				aux++;
			src = aux;
			i++;
		}
		dst[i] = ft_strdup(aux);
	}
}

static int	ft_num_words(char const *s, char c)
{
	int	i;
	int	n;
	int	flag;

	i = 0;
	n = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			n++;
		}
		i++;
	}
	return (n);
}

char	**ft_split(char const *s, char c)
{
	char		*trim;
	char		**str_mother;
	int			n;

	if (s == 0)
		return (0);
	str_mother = NULL;
	if (*s == 0)
		return (ft_allocate(str_mother));
	trim = ft_strtrim (s, &c);
	if (trim == 0)
		return (0);
	n = ft_num_words(trim, c);
	if (n == 0)
	{
		free (trim);
		return (ft_allocate(str_mother));
	}
	str_mother = ft_calloc((n + 1), (sizeof (char **)));
	if (str_mother == 0)
		return (0);
	ft_put_str (str_mother, trim, n, c);
	free (trim);
	return (str_mother);
}
