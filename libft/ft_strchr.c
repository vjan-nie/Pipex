/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:31:15 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/02/03 13:49:02 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == (char) c)
		return ((char *) &s[i]);
	return (NULL);
}
/* 
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int	main(void)
{
	const char	sentence[] = "where is the Character cap c";
	int	character = 'C';
	char	*check;

	printf("ft_strchr\n\n");	
	check = ft_strchr(sentence, character);
	if (check != NULL)
	{
		write(1, "My ft: char found where the pointer points at is: ", 50);
		write(1, check, 1);
		write(1, "\n", 1);
		printf("Adress with my ft: %p\n", check);
	}
	else
		write(1, "My ft not found", 15);
	
	check = strchr(sentence, character);
	if (check != NULL)
	{
		write(1, "Original ft: char found where the pointer points at is: ", 56);
		write(1, check, 1);
		write(1, "\n", 1);
		printf("Adress with original: %p\n", check);
	}
	else
		write(1, "Original not found", 18);
	printf("\n\n");
	return (0);
} */