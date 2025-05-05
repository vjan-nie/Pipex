/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:30:47 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/04/10 12:02:23 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	integer;
	int	i;
	int	pos_neg;

	integer = 0;
	pos_neg = 1;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			pos_neg = -1;
		i++;
	}
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		integer = integer * 10 + (nptr[i] - '0');
		i++;
	}
	return (integer * pos_neg);
}
/* 
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	const char	*str1 = "  53";
	const char	*str2 = "   -f53";
	const char	*str3 = "  -53";
	const char	*str4 = " --53";
	const char	*str5 = "5-3";
	const char	*str6 = "-";
	const char	*str7 = "dsf4d";
	const char	*str8 = "0";
	const char	*str9 = "\t\n\r\v\f  469 \n";
	const char	*str10 = "\n\n\n  -46\b9 \n5d6";

	printf("ft_atoi\n\n");
	printf("original ft str1: %d\n", atoi(str1));
	printf("original ft str2: %d\n", atoi(str2));
	printf("original ft sstr3: %d\n", atoi(str3));
	printf("original ft sstr4: %d\n", atoi(str4));
	printf("original ft sstr5: %d\n", atoi(str5));
	printf("original ft sstr6: %d\n", atoi(str6));
	printf("original ft sstr7: %d\n", atoi(str7));
	printf("original ft sstr8: %d\n", atoi(str8));
	printf("original ft sstr8: %d\n", atoi(str9));
	printf("original ft sstr8: %d\n", atoi(str10));
	
	printf("my ft str1: %d\n", ft_atoi(str1));
	printf("my ft str2: %d\n", ft_atoi(str2));
	printf("my ft str3: %d\n", ft_atoi(str3));
	printf("my ft str4: %d\n", ft_atoi(str4));
	printf("my ft str5: %d\n", ft_atoi(str5));
	printf("my ft str6: %d\n", ft_atoi(str6));
	printf("my ft str7: %d\n", ft_atoi(str7));
	printf("my ft str8: %d\n", ft_atoi(str9));
	printf("my ft str8: %d\n", ft_atoi(str10));
	printf("\n\n");
	return (0);
} */