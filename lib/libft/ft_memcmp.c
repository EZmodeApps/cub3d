#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s11;
	unsigned char	*s22;

	if (n == 0)
		return (0);
	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	i = 0;
	while (i++ < n)
	{
		if (*s11 != *s22)
			return (*s11 - *s22);
		else
		{
			s11++;
			s22++;
		}
	}
	return (0);
}
