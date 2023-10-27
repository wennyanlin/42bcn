/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:13:02 by wlin              #+#    #+#             */
/*   Updated: 2023/10/27 13:18:37 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_copy;

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
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	t_len;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
		{
			free(s1);
			return (NULL);
		}
		s1[0] = '\0';
	}
	t_len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc((t_len + 1) * sizeof(char));
	if (!result)
		return (ft_free_space(&s1));
	i = -1;
	while (s1[++i] != '\0')
		result[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
		result[i + j] = s2[j];
	result[i + j] = '\0';
	free(s1);
	return (result);
}

/*
int	main()
{
	char s[] = "Welcome to 42";
	int	c = 'l';

	printf("%s", ft_strchr(s, c));
	return (0);
}
int	main()
{
	char const s1[] = "Hola";
	char const s2[] = ", quetal?";
	printf("%s", ft_strjoin(s1, s2));
}*/
