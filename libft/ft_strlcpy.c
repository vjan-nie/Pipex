/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:32:18 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/01/30 16:00:47 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len_src;

	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	if (!dst || !src)
		return (len_src);
	while ((size > 1) && *src)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst++ = '\0';
	return (len_src);
}
/* 
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	char	source[] = "HellyeahRnR";
	char	*destiny;
	void	*dest;
	size_t	len = 4;

	destiny = NULL;
	destiny = malloc(len + 1);
	if (!destiny)
		return (-1);
	printf("ft_strlcpy\n\n");
	printf("My ft length of source: 11\n");
	printf("My ft length after: %lu\n", ft_strlcpy(destiny, source, len));
	printf("My ft copied sentence: %s\n", destiny);

	dest = (char *)malloc(1);
	ft_strlcpy(dest, "lorem ipsum dolor sit amet", 0);
    write(1, "\n", 1);
    write(1, dest, 15);
	
	printf("\n\n");

	return (0);
} */