/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:20:27 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/02/05 13:38:12 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*ptr_src;
	unsigned char		*ptr_dest;

	ptr_src = (const unsigned char *) src;
	ptr_dest = (unsigned char *) dest;
	if (ptr_src == ptr_dest || n == 0)
		return (dest);
	if (ptr_src < ptr_dest)
	{
		ptr_src = ptr_src + n;
		ptr_dest = ptr_dest + n;
		while (n--)
			*--ptr_dest = *--ptr_src;
	}
	else
	{
		while (n--)
			*ptr_dest++ = *ptr_src++;
	}
	return (dest);
}
/* 
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	void	*dst;
	const void	*srce;
	char	*str_dst;
	char	*str_srce;
	size_t	size = 5;
	size_t	i = 0;

	write(1, "ft_memmove\n\n", 12);
	dst = NULL;
	srce = NULL;
	dst = malloc(size);
	srce = malloc(size);
	if (!dst || !srce)
		return (-1);
	str_dst = (char *) dst;
	str_srce = (char *) srce;
	strcpy(str_srce, "test");
	
	ft_memmove(dst, srce, size);
	
	while (i < size)
	{
		if (str_dst[i] == str_srce[i])
			write(1, "v", 1);
		else
			write(1, "x", 1);	
		i++;
	}
	write(1, "\n", 1);
	
	i = 0;
	memmove(dst, srce, size);

	while (i < size)
	{
		if (str_dst[i] == str_srce[i])
			write(1, "v", 1);
		else
			write(1, "x", 1);
		i++;
	}
	write(1, "\n", 1);
	ft_memmove(NULL, NULL, 0);
	free(dst);
	free((void *) srce);
	write(1, "\n\n", 2);
	return (0);
} */