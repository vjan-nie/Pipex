/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:05:52 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/02/03 16:03:10 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s || ft_strlen(s) <= start || len == 0)
		return (ft_calloc(1, 1));
	if ((len + start) > ft_strlen(s))
		len = ft_strlen(s) - start;
	substr = NULL;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, &s[start], len + 1);
	return (substr);
}
/* 
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char const		*string;
	unsigned int	index = 10;
	size_t			size = 5;

	string = NULL;
	string = malloc(25);
	if (!string)
		return (-1);
	string = "is this a piece of cake?";
	printf("ft_substr\n\n");
	printf("full string: %s\n", string);
	printf("ft_substr should print 'piece'\n");
	printf("substr with my ft: %s\n", ft_substr(string, index, size));
	printf("test1: %s\n", ft_substr("", 1, 1));
	printf("test2: %p\n", ft_substr("", 0, 0));
	printf("test3: %p\n", ft_substr("hola", 4294967295, 0));
	printf("\n\n");
	return (0);
} */