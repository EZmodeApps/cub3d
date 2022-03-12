/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lholdo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 04:07:08 by lholdo            #+#    #+#             */
/*   Updated: 2022/03/12 04:07:08 by lholdo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	mult;
	void	*str;

	mult = count * size;
	str = malloc(mult);
	if (!(str))
		return (NULL);
	ft_memset(str, 0, mult);
	return (str);
}
