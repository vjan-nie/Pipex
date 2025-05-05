/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:36:49 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/01/30 15:33:38 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		n += 2000000000;
		n *= -1;
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	if (n >= 0 && n <= 9)
		ft_putchar_fd(n + '0', fd);
}
/* 
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int		nbr;
	int		file_descriptor;
	
	//range int: -2,147,483,648 .. 2,147,483,647
	printf("ft_putnbr_fd\n\n");
	file_descriptor = 1;
	
	nbr = 4;
	ft_putnbr_fd(nbr, file_descriptor);
	write(1, "\n", 1);

	nbr = -345;
	ft_putnbr_fd(nbr, file_descriptor);
	write(1, "\n", 1);

	nbr = 23423523;
	ft_putnbr_fd(nbr, file_descriptor);
	write(1, "\n", 1);

	nbr = - 45;
	ft_putnbr_fd(nbr, file_descriptor);
	write(1, "\n", 1);

	nbr = 2147483647;
	ft_putnbr_fd(nbr, file_descriptor);
	write(1, "\n", 1);

	nbr = -2147483648;
	ft_putnbr_fd(nbr, file_descriptor);
	write(1, "\n", 1);

	printf("\n\n");
} */