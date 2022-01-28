#include "libft.h"

static int	freee(char **str, int size)
{
	while (size--)
		free(str[size]);
	return (-1);
}

static int	count(const char *str, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i + 1] == c || str[i + 1] == '\0') == 1
			&& (str[i] == c || str[i] == '\0') == 0)
			words++;
		i++;
	}
	return (words);
}

static void	writemall(char *dest, const char *from, char charset)
{
	int	i;

	i = 0;
	while ((from[i] == charset || from[i] == '\0') == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

static int	power(char **split, const char *str, char c)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] == c || str[i] == '\0') == 1)
			i++;
		else
		{
			j = 0;
			while ((str[i + j] == c || str[i + j] == '\0') == 0)
				j++;
			split[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (!(split[word]))
				return (freee(split, word - 1));
			writemall(split[word], str + i, c);
			i += j;
			word++;
		}
	}
	return (0);
}

char	**ft_split(const char *str, char c)
{
	char	**res;
	int		words;

	words = count(str, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!(res))
		return (NULL);
	res[words] = 0;
	if (power(res, str, c) == -1)
		return (NULL);
	return (res);
}
