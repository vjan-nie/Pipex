/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:27:39 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/01/30 18:53:17 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}
/* 
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	slong[]="This is a long sentence";
	const char	sshort[]="This is a different one";
	const char	slong2[]="This is a long sentence";

	printf("ft_strncmp\n\n");
	printf("My ft long & short:\n");
	printf("%d\n", ft_strncmp(slong, sshort, sizeof(slong)));
	printf("My ft short & long:\n");
	printf("%d\n", ft_strncmp(sshort, slong, sizeof(sshort)));
	printf("My ft long & long:\n");
	printf("%d\n", ft_strncmp(slong, slong2, sizeof(sshort)));

	printf("Original ft long & short:\n");
	printf("%d\n", strncmp(slong, sshort, sizeof(slong)));
	printf("Original ft short & long:\n");
	printf("%d\n", strncmp(sshort, slong, sizeof(sshort)));
	printf("Original ft long & long:\n");
	printf("%d\n", strncmp(slong, slong2, sizeof(sshort)));
	printf("\n\n");
	return (0);
} */