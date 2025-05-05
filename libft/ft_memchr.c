/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:25:07 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/01/27 14:36:10 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	value;
	size_t			i;

	str = (unsigned char *) s;
	value = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (str[i] == value)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
/* 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	const void	*ptr;
	int	value = 42;
	size_t	size = 20;
	char	*str_yes;
	char	*str_no;

	printf("ft_memchr\n\n");
	ptr = NULL;
	ptr = malloc(size);
	if (!ptr)
		return (-1);
	str_yes = (char *) ptr;
	str_no = (char *) ptr;

	strcpy(str_yes, "sdfs*sd");

	printf("First example with my ft: %p\n", ft_memchr(ptr, value, size));
	printf("First example with original: %p\n", memchr(ptr, value, size));

	strcpy(str_no, "sfafsdghdfhb");

	printf("Second example with my ft: %p\n", ft_memchr(ptr, value, size));
	printf("Second example with original ft: %p\n", memchr(ptr, value, size));
	free((void *) ptr);
	printf("\n\n");
	return (0);
} */