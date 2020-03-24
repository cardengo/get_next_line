#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	max;

	if (!size)
		return (ft_strlen(src));
	i = 0;
	while (dst[i] && i < size)
		i++;
	max = i;
	while (src[i - max] && i < size - 1)
	{
		dst[i] = src[i - max];
		i++;
	}
	if (max < size)
		dst[i] = '\0';
	return (max + ft_strlen(src));
}
