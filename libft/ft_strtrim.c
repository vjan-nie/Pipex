/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:33:04 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/01/27 14:39:39 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strrchr(set, s1[end -1]))
		end--;
	return (ft_substr(s1, start, (end - start)));
}
/* 
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char const	*str1;
	char const	*to_trim;
	char		*trimmed;
	
	str1 = NULL;
	to_trim = NULL;
	trimmed = NULL;
	str1 = malloc(29);
	to_trim = malloc(9);
	if (!str1 || !to_trim)
		return(-1);
	str1 = "aaccbbddhello world!ddaabbcc";
	to_trim = "ccaaddbb";
	trimmed = ft_strtrim(str1, to_trim);
	printf("ft_strtrim\n\n");
	printf("string: %s\n", str1);
	printf("set: %s\n", to_trim);
	printf("string trim: %s\n", trimmed);
	printf("\n\n");
	return (0);
} */