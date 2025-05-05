/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:26:10 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/01/27 14:35:27 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = NULL;
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/* 
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	size_t	num_elements;
	size_t	size_elements;
	size_t	i = 0;
	unsigned char	*str;

	printf("ft_calloc\n\n");
	num_elements = 4;
	size_elements = 4;
 	str = (unsigned char *) ft_calloc(num_elements, size_elements);
	printf("Adress with my ft: %p\n", str);
	while (i < (num_elements * size_elements))
		{
			if (str[i] == '\0')
				write(1, "v", 1);
			else
				write(1, "x", 1);
			i++;
		}
	write(1, "\n", 1);

	i = 0;
	str = (unsigned char *) calloc(num_elements, size_elements);
	printf("Adress with original ft: %p\n", str);
	while (i < (num_elements * size_elements))
	{
		if (str[i] == '\0')
			write(1, "v", 1);
		else
			write(1, "x", 1);
		i++;
	}
	write(1, "\n", 1);
	free(str);
	printf ("\n\n");
	return (0);
} */