#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ss;
	int		i;

	if (!s || !f)
		return (NULL);
	ss = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!(ss))
		return (NULL);
	i = 0;
	while (s[i])
	{
		ss[i] = f(i, s[i]);
		i++;
	}
	ss[i] = '\0';
	return (ss);
}
