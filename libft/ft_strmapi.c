/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 10:35:08 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/02/05 00:55:42 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	result = NULL;
	result = ft_calloc(1, ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/* 
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int	main(void)
{
	char const	*string;
	
	printf("ft_strmapi\n\n");
	string = "Th1s iS 4 test SENT3NCE with Numbers.";
	printf("original sentence: %s\n", string);
	printf("result: %s\n", ft_strmapi(string, test_function_upper));
	printf("\n\n");

	return (0);
} */