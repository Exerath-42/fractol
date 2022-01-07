/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exerath <exerath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 04:02:21 by exerath           #+#    #+#             */
/*   Updated: 2021/12/13 20:00:57 by exerath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	dest = (char *)malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	check_len(int n, int sign)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	if (len == 0)
		return (1 + sign);
	else
		return (len + sign);
}

static char	*convert(int nlen, int sign, int n)
{
	char	*c;

	c = (char *)malloc((sizeof(char) * nlen + 1));
	if (!c)
		return (NULL);
	c[nlen] = '\0';
	while (--nlen >= sign)
	{
		c[nlen] = n % 10 + 48;
		n = n / 10;
	}
	if (nlen >= 0)
		c[nlen] = '-';
	return (c);
}

char	*ft_itoa(int n)
{
	int		nlen;
	char	*a;
	int		sign;

	nlen = 0;
	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = n * -1;
		sign = 1;
	}
	nlen = check_len(n, sign);
	a = convert(nlen, sign, n);
	return (a);
}
