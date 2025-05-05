/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:07:29 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/01/27 14:35:34 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
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
	unsigned char	alpha = 'g';
	unsigned char	notalpha = '3';
	int	alpha2 = 66;
	int	notalpha2 = 40;

	printf ("ft_isalpha\n\n");
	printf("My ft alpha: %d\n", ft_isalpha(alpha));
	printf("My ft  notalpha: %d\n", ft_isalpha(notalpha));
	printf("My ft alpha2: %d\n", ft_isalpha(alpha2));
	printf("My ft  notalpha2: %d\n", ft_isalpha(notalpha2));
	printf("Original ft alpha: %d\n", isalpha(alpha));
	printf("Original ft notalpha: %d\n", isalpha(notalpha));
	printf("Original ft alpha2: %d\n", isalpha(alpha2));
	printf("Original ft notalpha2: %d\n", isalpha(notalpha2));
	printf("\n\n");
	
	return (0);
} */