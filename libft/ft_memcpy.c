/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:13:53 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/02/05 13:36:27 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	ft_memmove(dest, src, n);
	return (dest);
}
/* 
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	void	*dst;
	const void	*srce;
	char	*str_dst;
	char	*str_srce;
	size_t	size = 5;
	size_t	i = 0;

	write(1, "ft_memcpy\n\n", 11);
	dst = NULL;
	srce = NULL;
	dst = malloc(size);
	srce = malloc(size);
	if (!dst || !srce)
		return (-1);
	str_dst = (char *) dst;
	str_srce = (char *) srce;
	strcpy(str_srce, "test");
	
	ft_memcpy(dst, srce, size);
	
	while (i < size)
	{
		if (str_dst[i] == str_srce[i])
			write(1, "v", 1);
		else
			write(1, "x", 1);
		i++;
	}
	write(1, "\n", 1);

	memcpy(dst, srce, size);
	i = 0;
	while (i < size)
	{
		if (str_dst[i] == str_srce[i])
			write(1, "v", 1);
		else
			write(1, "x", 1);
		i++;
	}
	write(1, "\n", 1);
	free(dst);
	free((void *) srce);
	write(1, "\n\n", 2);
	return (0);
} */