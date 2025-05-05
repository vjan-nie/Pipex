/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:45:06 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/01/27 14:38:54 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/* 
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	whatever[] = "abcde";

	printf("ft_strlen\n\n");
	printf("My ft_strlen: %lu\n", ft_strlen(whatever));
	printf("Standard  strlen: %lu\n", strlen(whatever));
	printf("\n\n");
	return (0);
} */