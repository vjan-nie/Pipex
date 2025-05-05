/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:45:38 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/01/27 14:37:55 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	n;

	n = ft_strlen(s);
	str = NULL;
	str = malloc(n + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, n + 1);
	return (str);
}
/* 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	const char	*str;
	const char	*str2;

	printf("ft_strdup\n\n");
	str = "123456789";
	str2 = "abcdefghijklmnopqrstuvwxyz";

	printf("output string with my ft: %s\n", ft_strdup(str));
	printf("output string2 with my ft: %s\n", ft_strdup(str2));
	printf("output string with original ft: %s\n", strdup(str));
	printf("output string2 with original ft: %s\n", strdup(str2));
	printf("\n\n");
	return (0);
} */
