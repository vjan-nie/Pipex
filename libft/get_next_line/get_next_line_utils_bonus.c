/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:32:40 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/03/26 14:26:54 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == (char) c)
		return ((char *) &s[i]);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len_src;

	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	if (!dst || !src)
		return (len_src);
	while ((size > 1) && *src)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst++ = '\0';
	return (len_src);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	i;
	size_t	j;

	string = malloc(ft_strlen(s1) + ft_strlen(s2) +1);
	if (!string)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		string[i] = s2[j];
		i++;
		j++;
	}
	string[i] = '\0';
	return (string);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	n;

	n = ft_strlen(s);
	str = NULL;
	str = malloc(n + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, n + 1);
	return (str);
}
