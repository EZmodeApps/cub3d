/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lholdo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 04:01:28 by lholdo            #+#    #+#             */
/*   Updated: 2022/03/12 04:01:28 by lholdo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "cub3d.h"

char	*ft_mod_strdup(char *str)
{
	char	*s;
	int		i;
	int		j;

	if (str == NULL)
		i = 0;
	else
		i = ft_strlen(str);
	s = malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	j = i;
	i = 0;
	while (i < j && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

int	ft_mod_strchr(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_mod_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_mod_strdup(s2));
	if (s2 == NULL)
		return (ft_mod_strdup(s1));
	str = (char *)malloc(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(str))
		return (NULL);
	i = 0;
	while (*s1 != '\0')
		str[i++] = *s1++;
	while (*s2 != '\0')
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
