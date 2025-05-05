/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:05:46 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/01/28 12:11:27 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/* 
#include <stdio.h>

int	main(void)
{
	char	string[] = "Th1s iS 4 test SENT3NCE with Numbers.";
	
	printf("ft_striteri\n\n");
	printf("original sentence: %s\n", string);
	ft_striteri(string, test_function2_upper);
	printf("result: %s\n", string);
	printf("\n\n");

	return (0);
} */