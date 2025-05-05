/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:51:53 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/01/27 14:38:12 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	i;
	size_t	j;

	string = malloc(ft_strlen(s1) + ft_strlen(s2) +1);
	if (!string)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		string[i] = s2[j];
		i++;
		j++;
	}
	string[i] = '\0';
	return (string);
}
/* 
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char const	*string1;
	char const	*string2;

	string1 = malloc(21 + 1);
	string2 = malloc(7 + 1);
	if (!string1 || !string2)
		return (-1);
	string1 = "This sentence should ";
	string2 = "finish.";
	printf("ft_strjoin\n\n");
	printf("sentence 1: %s\n", string1);
	printf("sentence 2: %s\n", string2);
	printf("sentence joined: %s\n", ft_strjoin(string1, string2));
	free((void *) string1);
	free((void *) string2);
	printf("\n\n");
	return (0);
} */