#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	char	*cpy;
	int		i;
	int		len;

	cpy = ft_strdup(s2);
	len = ft_strlen(s1);
	i = 0;
	while (cpy[i])
	{
		s1[len + i] = cpy[i];
		i++;
	}
	s1[len + i] = '\0';
	free(cpy);
	return (s1);
}
