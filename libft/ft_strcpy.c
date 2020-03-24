#include <string.h>

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	len;

	len = 0;
	while (src[len])
	{
		dst[len] = src[len];
		len++;
	}
	dst[len] = '\0';
	return (dst);
}
