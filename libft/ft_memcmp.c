/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:28:43 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/01/29 16:14:35 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str_s1;
	unsigned char	*str_s2;
	size_t			i;

	str_s1 = (unsigned char *) s1;
	str_s2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (str_s1[i] != str_s2[i])
			return (str_s1[i] - str_s2[i]);
		i++;
	}
	return (0);
}
/* 
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	const void	*ptr1;
	const void	*ptr2;
	const void	*ptr3;
	char	*slong;
	char	*sshort;
	char	*slong2;
	size_t	size = 40;

	printf("ft_memcmp\n\n");
	ptr1 = NULL;
	ptr2 = NULL;
	ptr3 = NULL;
	ptr1 = malloc(size);
	ptr2 = malloc(size);
	ptr3 = malloc(size);
	slong = (char *) ptr1;
	sshort = (char *) ptr2;
	slong2 = (char *) ptr3;

	strcpy(slong, "This is a long sentence");
	strcpy(sshort, "This is a different one");
	strcpy(slong2, "This is a long sentence");

	printf("long & short with my ft:\n");
	printf("%d\n", ft_memcmp(ptr1, ptr2, size));
	printf("short & long with my ft:\n");
	printf("%d\n", ft_memcmp(ptr2, ptr1, size));
	printf("long & long with my ft:\n");
	printf("%d\n", ft_memcmp(ptr1, ptr3, size));

	printf("long & short with original:\n");
	printf("%d\n", memcmp(ptr1, ptr2, size));
	printf("short & long with original:\n");
	printf("%d\n", memcmp(ptr2, ptr1, size));
	printf("long & long with original:\n");
	printf("%d\n", memcmp(ptr1, ptr3, size));

	free((void *)ptr1);
	free((void *)ptr2);
	free((void *)ptr3);

	printf("\n\n");
	return (0);
} */