/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 12:51:26 by wlin              #+#    #+#             */
/*   Updated: 2023/10/28 18:09:25 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strdup(char *s1, char *s2)
{
	char	*dup_s1;
	int		i;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	dup_s1 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dup_s1)
		return (NULL);
	while (s1[++i] != '\0')
		dup_s1[i] = s1[i];
	dup_s1[i] = '\0';
	return (dup_s1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	i = ft_strlen(s1);
	result = ft_strdup(s1, s2);
	if (!result)
		return (NULL);
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
