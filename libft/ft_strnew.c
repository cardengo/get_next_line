#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*buf;
	size_t	i;

	if (size + 1 == 0)
		return (NULL);
	if (!(buf = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (i <= size)
	{
		buf[i] = '\0';
		i++;
	}
	return (buf);
}
