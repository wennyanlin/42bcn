#include <stdio.h>

size_t  ft_strlcpy(char *dest, const char *src, size_t size)
{
    int i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
	{
		i++;
	}
	return (i);
}

int	main()
{
	size_t size= 0;
	char *src = "Hello";
	char dest[3];
	size_t	result = ft_strlcpy(dest, src, size);
	printf("%zu\n%s\n%s", result, dest, src);
	return (0);
}
