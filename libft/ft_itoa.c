/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:17:53 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/02/05 00:53:31 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_int(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*case_zero(char *s)
{
	s = (char *) ft_calloc(1, 2);
	if (!s)
		return (NULL);
	s[0] = '0';
	s[1] = '\0';
	return (s);
}

static char	*positive(char *s, long n, int index)
{
	while (n > 0)
	{
		s[index -1] = n % 10 + '0';
		n /= 10;
		index--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		neg_flag;
	long	nbr;

	str = NULL;
	nbr = n;
	neg_flag = 0;
	i = len_int(n);
	if (nbr < 0)
	{
		neg_flag = 1;
		nbr *= -1;
		i++;
	}
	if (n == 0)
		return (case_zero(str));
	str = (char *) ft_calloc(1, i + 1);
	if (!str)
		return (NULL);
	str = positive(str, nbr, i);
	if (neg_flag == 1)
		str[0] = '-';
	return (str);
}
/* 
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	int	nbr;

	printf("ft_itoa\n\n");
	nbr = 4;
	printf("%s\n", ft_itoa(nbr));
	nbr = -345;
	printf("%s\n", ft_itoa(nbr));
	nbr = 23423523;
	printf("%s\n", ft_itoa(nbr));
	nbr = -45;
	printf("%s\n", ft_itoa(nbr));
	nbr = 2147483647;
	printf("%s\n", ft_itoa(nbr));
	nbr = -2147483648;
	printf("%s\n", ft_itoa(nbr));
	nbr = 0;
	printf("%s\n", ft_itoa(nbr));
	printf("\n\n");
	return (0);
} */