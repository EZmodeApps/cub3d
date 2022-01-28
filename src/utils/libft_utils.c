#include "cub3d.h"

void	*ft_realloc(char **mas, int count)
{
	char	**new;
	int		i;

	if (!mas)
		return (malloc(sizeof(char *) * (count + 1)));
	new = (char **)malloc(sizeof(char *) * (count + 1));
	if (!new)
		return (NULL);
	i = -1;
	while (++i < count)
	{
		new[i] = (char *)malloc(sizeof(char) * (ft_strlen(mas[i]) + 1));
		if (!new)
			return (NULL);
		if (!ft_strlcpy(new[i], mas[i], ft_strlen(mas[i]) + 1))
			return (NULL);
	}
	i = -1;
	while (++i < count)
		free(mas[i]);
	free(mas);
	return (new);
}
