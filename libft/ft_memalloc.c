#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*buf;

	if (!(buf = malloc(size)))
		return (NULL);
	buf = ft_memset(buf, 0, size);
	return (buf);
}
