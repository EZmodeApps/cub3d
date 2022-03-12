/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lholdo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 04:07:19 by lholdo            #+#    #+#             */
/*   Updated: 2022/03/12 04:07:19 by lholdo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	ii;

	ii = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		ii++;
	}
	return (ii);
}

static char	*pos(int n, int len)
{
	char	*ss;

	ss = (char *)malloc(sizeof(*ss) * (len + 1));
	if (ss)
	{
		ss[len] = '\0';
		len--;
		while (len >= 0)
		{
			ss[len] = n % 10 + '0';
			n = n / 10;
			len--;
		}
		return (ss);
	}
	return (NULL);
}

static char	*neg(int n, int len)
{
	char	*ss;

	ss = (char *)malloc(sizeof(*ss) * (len + 2));
	if (ss)
	{
		ss[0] = '-';
		len++;
		ss[len] = '\0';
		len--;
		while (len > 0)
		{
			ss[len] = n % 10 + '0';
			n = n / 10;
			len--;
		}
		return (ss);
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	char	*ss;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = count_digits(n);
	if (n >= 0)
		return (ss = pos(n, len));
	return (ss = neg((n * -1), len));
}
