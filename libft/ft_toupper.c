/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:04:20 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/01/27 14:40:03 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
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

	printf("ft_toupper\n\n");
	printf("My ft from lower: %c\n", ft_toupper(low));
	printf("My ft from upper: %c\n", ft_toupper(upp));
	printf("My ft from non alph: %c\n", ft_toupper(nonalpha));
	printf("Original ft from lower: %c\n", toupper(low));
	printf("Original ft from upper: %c\n", toupper(upp));
	printf("Original ft from non alph: %c\n", toupper(nonalpha));
	printf("\n\n");
	return (0);
} */