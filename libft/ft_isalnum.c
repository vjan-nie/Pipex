/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:11:35 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/01/27 14:35:31 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((ft_isalpha(c) == 1) || (ft_isdigit(c) == 1))
	{
		return (1);
	}
	return (0);
}
/* 
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	unsigned char	example1 = 'f';
	int		example2 = 32;

	printf("ft_isalnum\n\n");
	printf("my ft alnum: %d\n", ft_isalnum(example1));
	printf("standard alnum: %d\n", isalnum(example1)); 
	printf("my ft not alnum: %d\n", ft_isalnum(example2));
	printf("standard not alnum: %d\n", isalnum(example2));
	printf("\n\n");
	return (0);
} */
