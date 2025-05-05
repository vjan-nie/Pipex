/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:09:35 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/01/27 14:36:57 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/* 
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	char	character;
	int		file_descriptor;

	character = '*';
	file_descriptor = 1;
	printf("ft_putchar_fd\n\n");
	ft_putchar_fd(character, file_descriptor);
	printf("\n\n");

	return (0);
} */