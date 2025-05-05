/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:38:43 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/01/29 17:04:55 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return ((c >= '0') && (c <= '9'));
}
/* 
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	unsigned char	digit = '3';
	unsigned char	notdigit = 'g';
	int	digit2 = 52;

	printf("ft_isdigit\n\n");
	printf("My ft digit: %d\n", ft_isdigit(digit));
	printf("My ft  notdigit: %d\n", ft_isdigit(notdigit));
	printf("My ft digit2: %d\n", ft_isdigit(digit2));
	printf("Original ft digit: %d\n", isdigit(digit));
	printf("Original ft notdigit: %d\n", isdigit(notdigit));
	printf("Original ft digit2: %d\n", isdigit(digit2));
	printf("\n\n");
	
	return (0);
} */