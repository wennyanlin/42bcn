/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:13:02 by wlin              #+#    #+#             */
/*   Updated: 2023/10/20 19:32:19 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char *s_copy;

	s_copy = (char *)s;
	while (*s_copy != '\0')
	{
		if (*s_copy == c)
			return (s_copy);
		s_copy++;
	}
	if (c == '\0')
		return (s_copy);
	return (NULL);
}


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char 	*result;
	size_t	s1_len;
	size_t	s2_len;
	int		i;
	int		j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		result[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
		result[i+j] = s2[j];
	result[i+j] = '\0';
	return (result);
}

/*
int	main()
{
	char s[] = "Welcome to 42";
	int	c = 'l';

	printf("%s", ft_strchr(s, c));
	return (0);
}*//*
int	main()
{
	char const s1[] = "Hola";
	char const s2[] = ", quetal?";
	printf("%s", ft_strjoin(s1, s2));
}*/
