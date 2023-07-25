/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 23:04:45 by wlin              #+#    #+#             */
/*   Updated: 2023/07/25 23:51:08 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	if ('a' <= str[i] && str[i] <= 'z')
	{
		str[i] = str[i] - 32;
	}
	i++;
	while (str[i])
	{
		if (! ('a' <= str[i] && str[i] <= 'z') 
						|| ('A' <= str[i] && str[i] <= 'Z'))
		i++;
		else if ('a' <= str[i] && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
}
int	main(void)
{
	char str[20] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	ft_strcapitalize(str);
	return (0);
}
