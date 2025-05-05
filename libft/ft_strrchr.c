/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:18:29 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/02/03 13:50:11 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	while (i > 0)
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i--;
	}
	if (s[i] == (char) c)
		return ((char *) &s[i]);
	return (0);
}
/* 
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int	main(void)
{
	const char	sentence[] = "where is the Character cap C";
	int	character = 'C';
	char	*check;
	printf("ft_strrchr\n\n");
	check = ft_strrchr(sentence, character);
	printf("Adress with my ft: %p\n", check);
	if (check != NULL)
	{
		write(1, "My ft: char found where the pointer points at is: ", 50);
		write(1, check, 1);
		write(1, "\n", 1);
	}
	else
		write(1, "My ft not found", 15);
	
	check = strrchr(sentence, character);
	printf("Adress with original: %p\n", check);
	if (check != NULL)
	{
		write(1, "Original ft: char found where the pointer points at is: ", 56);
		write(1, check, 1);
		write(1, "\n", 1);
	}
	else
		write(1, "Original not found", 18);
	printf("\n\n");
	return (0);
} */