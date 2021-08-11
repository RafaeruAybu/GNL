#include "get_next_line.h"

size_t		ft_strlen(const char *string)
{
	const char		*ptr;
	size_t			counter;

	ptr = string;
	counter = 0;
	while (*ptr)
	{
		ptr++;
		counter++;
	}
	return (counter);
}

char		*ft_strchr(const char *s, int c)
{
	const unsigned char	*s_ptr;
	unsigned char		ch;

	s_ptr = (unsigned char *)s;
	ch = (unsigned char)c;
	while (1)
	{
		if (*s_ptr == c)
			return ((char *)s_ptr);
		if (*s_ptr == 0)
			return (0);
		s_ptr++;
	}
	return (0);
}

void		*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, size);
	return (ptr);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *ptr;
	char *tmp;

	ptr = (char *)malloc(len + 1);
	if (s == 0)
		return (0);
	if (!ptr)
		return (ptr);
	tmp = ptr;
	if (start < (ft_strlen(s)))
	{
		while (start-- != 0)
			s++;
		while ((len-- != 0) && *s)
			*ptr++ = *s++;
	}
	*ptr = '\0';
	return (tmp);
}

char		*ft_strdup(const char *s1)
{
	size_t	size;
	char	*ptr;
	char	*tmp;

	size = ft_strlen(s1);
	ptr = malloc(size + 1);
	tmp = ptr;
	if (ptr == 0)
		return (ptr);
	while (*s1)
		*ptr++ = *s1++;
	*ptr = '\0';
	return (tmp);
}
