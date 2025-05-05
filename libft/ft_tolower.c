/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:15:24 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/01/27 14:39:56 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
		return (c + 32);
	return (c);
}
/* 
#include <stdio.h>
#include <ctype.h>

int		main(void)
{
	unsigned char	low = 'g';
	unsigned char	upp = 'H';
	unsigned char	nonalpha = '4';
	printf("ft_tolower\n\n");
	printf("My ft from lower: %c\n", ft_tolower(low));
	printf("My ft from lower: %c\n", ft_tolower(upp));
	printf("My ft from non alph: %c\n", ft_tolower(nonalpha));
	printf("Original ft from lower: %c\n", tolower(low));
	printf("Original ft from lower: %c\n", tolower(upp));
	printf("Original ft from non alph: %c\n", tolower(nonalpha));
	printf("\n\n");
	return (0);
} */