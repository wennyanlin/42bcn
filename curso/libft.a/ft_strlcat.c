#include <stdio.h>
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	destlen;
	size_t	srclen;

	destlen = dstsize;
	srclen = 0;
	while (src[srclen] && srclen < (dstsize - 1))
	{
		dest[destlen] = src[srclen];
		srclen++;
		destlen++;
	}
	dest[destlen] = '\0';
	while (src[srclen])
	{
		srclen++;
	}
	return (dstsize + srclen);
}


int	main()
{
	size_t dstsize= 6;
	char *src = "Adios123";
	char dest[12] = "Hola, ";
	printf("%zu", ft_strlcat(dest, src, dstsize));
	return (0);
}
