#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	d = (char *)malloc(sizeof(*s) * (len + 1));
	if (!(d))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			d[j] = s[i];
			j++;
		}
		i++;
	}
	d[j] = 0;
	return (d);
}
