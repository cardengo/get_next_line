#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*cpy;
	int		len;
	int		i;

	len = 0;
	while (str[len])
		len++;
	cpy = (char *)malloc((len + 1) * sizeof(*cpy));
	if (!cpy)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
