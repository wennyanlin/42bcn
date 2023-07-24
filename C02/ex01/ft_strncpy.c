char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i != n)
	{
		dest[i] = src[i]
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
int	main()
{
	int n = 3;
	char src = "hola";
	char dest = "hello";

	ft_strncpy(dest, src, n);
	return (0);
}
*/
