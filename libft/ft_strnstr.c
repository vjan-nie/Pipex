/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:22:00 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/02/05 13:43:40 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (*s2 == 0)
		return ((char *) s1);
	i = 0;
	while ((s1[i]) && (i < n))
	{
		j = 0;
		while (s1[i + j] && s2[j] && s1[i + j] == s2[j] && (i + j) < n)
		{
			j++;
		}
		if (s2[j] == '\0')
			return ((char *) &s1[i]);
		i++;
	}
	return (NULL);
}
/* 
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int	main(void)
{
	const char		*haystack = "Encontrar una aguja en un pajar";
	const char		*needle = "aguja";
	unsigned int	haystack_size = 31;
	unsigned int	needle_size = 5;
	const char		*haystack2 = "Perdona, es que soy ta ta tartamudo...";
	const char		*needle2 = "tartamudo";
	unsigned int	haystack2_size = 38;
	unsigned int	needle2_size = 9;
	const char		*need;
	unsigned int	i;

	printf("ft_strnstr\n\n");
	need = ft_strnstr(haystack, needle, haystack_size);
	printf("Adress with my ft example1: %p\n", need);
	if (need)
	{
		i = 0;
		while (i < needle_size)
		{
			write(1, &need[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);

	need = ft_strnstr(haystack2, needle2, haystack2_size);
	printf("Adress with my ft example2: %p\n", need);
	if (need)
	{
		i = 0;
		while (i < needle2_size)
		{
			write(1, &need[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);

	need = strstr(haystack, needle);
	printf("Adress with my orig example1: %p\n", need);
	if (need)
	{
		i = 0;
		while (i < needle_size)
		{
			write(1, &need[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);

	need = strstr(haystack2, needle2);
	printf("Adress with my orig example2: %p\n", need);
	if (need)
	{
		i = 0;
		while (i < needle2_size)
		{
			write(1, &need[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	printf("\n\n");
	return (0);
} */