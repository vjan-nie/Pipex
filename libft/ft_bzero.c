/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:35:10 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/01/29 16:13:54 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
/* 
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	void	*ptr;
	unsigned char	*str;
	size_t	size = 5;
	size_t	i = 0;

	write(1, "ft_bzero\n\n", 10);
	ptr = NULL;
	ptr = malloc (size);
	if (!ptr)
		return (-1);
	str = (unsigned char *) ptr;
	ft_bzero(ptr, size);
	while (i < size)
	{
		if (str[i] == '\0' && i < size)
			write(1, "0", 1);

		else
			write(1, "x", 1);
		i++;
	}
	write(1, "\n", 1);

	i = 0;
	bzero(ptr, size);
	while (i < size)
	{
		if (str[i] == '\0' && i < size)
			write(1, "0", 1);

		else
			write(1, "x", 1);
		i++;
	}
	write(1, "\n", 1);
	free(ptr);
	write(1, "\n\n", 2);
	
	return (0);
} */
