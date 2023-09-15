#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned int)s1[i] - (unsigned int)s2[i]);
		i++;
	}
	return (0);
}
int	main()
{
	char *s1 = "Hello";
	char *s2 = "Hola";
	size_t n = 3;
	printf("%i", ft_strncmp(s1, s2, n));
	return (0);
}
