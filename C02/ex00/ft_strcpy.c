/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpujades <cpujades@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:34:05 by wlin              #+#    #+#             */
/*   Updated: 2023/07/24 18:04:25 by wlin             ###   ########.fr       */
/*                                                                            */
/*************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);

}
/*
 int main(void)
 {
 	char paste[5];
 	char copy[5] = "hola";
	ft_strcpy(paste, copy);
 }
 */
