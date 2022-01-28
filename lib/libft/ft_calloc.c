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
