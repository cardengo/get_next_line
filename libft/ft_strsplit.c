#include "libft.h"

static	size_t	ft_cntwrd(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	count = 0;
	while (i < ft_strlen(s))
	{
		while (s[i] == c)
			i++;
		j = 0;
		while (s[i] != c && s[i])
		{
			j++;
			i++;
		}
		if (j)
			count++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	l;
	char	**box;

	if (!s || !(box = (char **)malloc(sizeof(char *) *\
					(ft_cntwrd(s, c) + 1))))
		return (NULL);
	i = 0;
	l = 0;
	while (l < ft_cntwrd(s, c))
	{
		while (s[i] == c)
			i++;
		j = 0;
		while (s[i + j] != c && s[i + j])
			j++;
		if (!(box[l] = ft_strsub((char const *)s, i, j)))
			return (NULL);
		i += j;
		l++;
	}
	box[l] = (void *)0;
	return (box);
}
