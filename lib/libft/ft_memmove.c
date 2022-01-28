#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*to;
	char	*from;

	i = 0;
	to = (char *)dst;
	from = (char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (to > from)
	{
		while (len-- > 0)
			to[len] = from[len];
	}
	if (from > to)
	{
		while (i < len)
		{
			to[i] = from[i];
			i++;
		}
	}
	return (dst);
}
