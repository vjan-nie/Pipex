/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:37:05 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/01/27 14:37:07 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
/* 
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	char	str[] = "Hello World!";
	int		file_descriptor;

	file_descriptor = 1;
	printf("ft_putendl_fd\n\n");
	ft_putendl_fd(str, file_descriptor);
	printf("\n\n");

	return (0);
} */