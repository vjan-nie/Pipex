/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:27:19 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/01/27 14:36:03 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if ((c >= 0) && (c <= 127))
	{
		return (1);
	}
	return (0);
}
/* 
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	unsigned char	ascii = 'g';
	unsigned char	notascii = '~';
	int	ascii2 = 42;
	int	notascii2 = 128;

	printf("ft_isascii\n\n");
	printf("My ft ascii: %d\n", ft_isascii(ascii));
	printf("My ft  notascii: %d\n", ft_isascii(notascii));
	printf("My ft ascii2: %d\n", ft_isascii(ascii2));
	printf("My ft  not ascii2: %d\n", ft_isascii(notascii2));
	printf("Original ft ascii: %d\n", isascii(ascii));
	printf("Original ft notascii: %d\n", isascii(notascii));
	printf("Original ft ascii2: %d\n", isascii(ascii2));
	printf("Original ft not ascii2: %d\n", isascii(notascii2));
	printf("\n\n");
	
	return (0);
} */