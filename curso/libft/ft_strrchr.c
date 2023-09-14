#include <stdio.h>

char *strrchr(const char *s, int c)
{
	int		i;
	int		lasti;
	char	foundchar;

	foundchar = (char)c;
	i = 0;
	lasti = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)foundchar)
		{
			lasti = i;
		}
		i++;
	}
	return ((char *)&s[lasti]);
}
int main()
{
	const	char	*s = "hello";
	int				c = 108;
	char			*result = strrchr(s, c);
	printf("%c", *result);
	return (0);
}
