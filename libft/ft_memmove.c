#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	if (!src && !dst)
		return (dst);
	s = (char *)src;
	d = (char *)dst;
	if (s <= d)
	{
		while (len--)
			*(d + len) = *(s + len);
	}
	else
	{
		i = 0;
		while (i < len)
		{
			*(d + i) = *(s + i);
			i++;
		}
	}
	return (d);
}
