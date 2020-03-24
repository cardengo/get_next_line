#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*st1;
	char	*st2;

	if (!s1 && !s2)
		return (0);
	st1 = (char *)s1;
	st2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)st1[i] != (unsigned char)st2[i])
			return ((int)(unsigned char)st1[i] - (unsigned char)st2[i]);
		i++;
	}
	return (0);
}
