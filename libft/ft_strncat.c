#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	char	*cpy;
	size_t	i;
	size_t	ln;

	cpy = ft_strdup(s2);
	ln = ft_strlen(s1);
	i = 0;
	while (cpy[i] && i < n)
	{
		s1[ln + i] = cpy[i];
		i++;
	}
	s1[ln + i] = '\0';
	return (s1);
}
