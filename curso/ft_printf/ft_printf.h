/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:27:42 by wlin              #+#    #+#             */
/*   Updated: 2023/10/07 19:10:32 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_put_digit(int n);
int	ft_put_recursive(unsigned int n);
int	ft_printf(const	char *str, ...);
int	put_str(char *s);
int	put_char(char c);
#endif
