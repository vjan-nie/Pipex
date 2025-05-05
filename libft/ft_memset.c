/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:09:13 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/01/27 14:36:50 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	value;

	value = (unsigned char) c;
	str = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		str[i] = value;
		i++;
	}
	return (s);
}
/* 
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	void	*ptr;
	char	*str;
	int	byte = -128; // range -128...127 char
	size_t	size = 5;
	size_t	i = 0;

	write(1, "ft_memset\n\n", 11);
	ptr = NULL;
	ptr = malloc(size);
	if(!ptr)
		return(-1);
	str = (char *) ptr;
	
	ft_memset(ptr, byte, size);
	
	while (i < size)
	{
		if (str[i] == byte)
		{
			write(1, "v", 1);
			i++;
		}
		else
		{
			write(1, "\n", 1);
			write(1, "x", 1);
			return (-1);
		}	
	}
	write(1, "\n", 1);

	i= 0;
	memset(ptr, byte, size);

	while (i < size)
	{
		if (str[i] == byte)
		{
			write(1, "v", 1);
			i++;
		}
		else
		{
			write(1, "\n", 1);
			write(1, "x", 1);
			return (-1);
		}	
	}
	write(1, "\n", 1);
	free(ptr);
	write(1, "\n\n", 2);
	
	return (0);
} */