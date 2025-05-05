/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:32:04 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/01/27 14:35:52 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= 32) && (c <= 126))
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
	unsigned char	print = ' ';
	int	print2 = 4;
	int	notprint = 31;

	printf("ft_isprint\n\n");
	printf("My ft print: %d\n", ft_isprint(print));
	printf("My ft print2: %d\n", ft_isprint(print2));
	printf("My ft  notprint2: %d\n", ft_isprint(notprint));
	printf("Original ft print: %d\n", isprint(print));
	printf("Original ft print2: %d\n", isprint(print2));
	printf("Original ft notprint2: %d\n", isprint(notprint));
	printf("\n\n");
	
	return (0);
} */