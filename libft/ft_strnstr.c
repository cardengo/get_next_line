#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	j = 0;
	while (i <= ft_strlen(haystack) && i < len)
	{
		if (haystack[i + j] == needle[j] && needle[j])
			j++;
		if (needle[j] == '\0' && j == ft_strlen(needle) && j + i <= len)
			return ((char *)haystack + i);
		if (haystack[i + j] != needle[j])
		{
			i++;
			j = 0;
		}
	}
	return (NULL);
}
