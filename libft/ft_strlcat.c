/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:04:31 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/01/30 17:46:19 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	if (!dst || !src)
		return (size + src_len);
	i = dst_len;
	j = 0;
	while (src[j] && (i +1) < size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}
/* 
#include <stdio.h>
#include <string.h>

int		main(void)
{
	char	destiny[20] = "hola";
	char	destiny2[20] = "hola";
	char	source[] = ", que tal vas";
    unsigned int    length = sizeof(destiny) / sizeof(destiny[0]);

	printf("ft_strlcat\n\n");
	printf("destiny: %s\n", destiny);
	printf("source: %s\n", source);
	printf("My ft len of dest: %d\n", length);
	printf("My ft len after concat: %lu\n", ft_strlcat(destiny, source, length));
	printf("My ft string after concat: %s\n", destiny);
	
	printf("Stdrd ft len of dest: %d\n", length);
	printf("Stdrd ft len after: %lu\n", strlcat(destiny2, source, length));
	printf("Stdrd ft string after: %s\n", destiny2);
	printf("\n\n");
	
	return (0);
} */