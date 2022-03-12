/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lholdo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 04:07:45 by lholdo            #+#    #+#             */
/*   Updated: 2022/03/12 04:07:45 by lholdo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	int		i;

	if (!(s1) || !(s2))
		return (NULL);
	d = (char *)malloc(sizeof(*d) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(d))
		return (NULL);
	i = 0;
	while (*s1 != '\0')
		d[i++] = *s1++;
	while (*s2 != '\0')
		d[i++] = *s2++;
	d[i] = '\0';
	return (d);
}
