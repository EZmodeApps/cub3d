/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lholdo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 04:07:20 by lholdo            #+#    #+#             */
/*   Updated: 2022/03/12 04:07:20 by lholdo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*to;
	char	*from;
	size_t	i;

	i = 0;
	to = (char *)dst;
	from = (char *)src;
	while (i < n)
	{
		to[i] = from[i];
		if ((unsigned char)from[i] == (unsigned char)c)
			return ((char *)dst + i + 1);
		i++;
	}
	return (NULL);
}
