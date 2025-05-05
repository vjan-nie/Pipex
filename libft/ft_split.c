/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:12:06 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/02/05 00:45:02 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	chunk_count(char const *s, char c)
{
	size_t	count;
	size_t	chunk;

	count = 0;
	chunk = 0;
	while (*s)
	{
		if (*s == c)
			chunk = 0;
		else if (!chunk)
		{
			chunk = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static void	get_chunk(char **chnks, size_t cnt, const char *strt, size_t len)
{
	chnks[cnt] = malloc(len +1);
	ft_strlcpy(chnks[cnt], strt, len +1);
}

static size_t	find_chunks(char **chunks, char const *s, char c, size_t t_cnts)
{
	size_t	count;
	size_t	start;
	size_t	end;

	count = 0;
	start = 0;
	end = 0;
	while (s[end] && count < t_cnts)
	{
		while (s[end] == c)
			end++;
		start = end;
		while (s[end] && s[end] != c)
			end++;
		if (s[start] != s[end])
		{
			get_chunk(chunks, count, &s[start], end - start);
			if (!chunks[count])
				return (0);
			count++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**chunks;
	size_t	counts;
	size_t	i;

	if (!s)
		return (NULL);
	counts = chunk_count(s, c);
	chunks = NULL;
	chunks = malloc((counts + 1) * sizeof(char *));
	if (!chunks)
		return (NULL);
	chunks[counts] = NULL;
	if (!find_chunks(chunks, s, c, counts))
	{
		i = 0;
		while (chunks[i])
		{
			free(chunks[i]);
			i++;
		}
		free(chunks);
		return (NULL);
	}
	return (chunks);
}
/* 
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	//the character where the split is done 
	//should be ignored. Use as many splits as needed.
	//memory handling? free?
	char const	*string;
	char		**splits;
	
	printf("ft_split.c\n\n");
	string = "Where oooodooo you want to split this?";
	printf("Sentence to split: %s\n", string);
	splits = ft_split(string, 'o');
	printf("split 1: '%s'\n", splits[0]);
	printf("split 2: '%s'\n", splits[1]);
	printf("split 3: '%s'\n", splits[2]);
	printf("split 4: '%s'\n", splits[3]);
	printf("split 5: '%s'\n", splits[4]);
	free(splits[4]);
	free(splits[3]);
	free(splits[2]);
	free(splits[1]);
	free(splits[0]);
	free(splits);
	
	printf("T1[0]:'%s'\n", ft_split("hello!", ' ')[0]);
	printf("T1[1]:'%s'\n", ft_split("hello!", ' ')[1]);
	printf("T2[0]:'%s'\n", ft_split("xxxxxxxxhello!",'x')[0]);
	printf("T2[1]:'%s'\n", ft_split("xxxxxxxxhello!",'x')[1]);
	printf("T4[0]:'%s'\n", ft_split("\t\t\t\thello!\t\t\t\t", '\t')[0]);
	printf("T4[1]:'%s'\n", ft_split("\t\t\t\thello!\t\t\t\t", '\t')[1]);
	printf("T5[0]:'%s'\n", ft_split("", 'a')[0]);

	printf("\n\n");
	return (0);
} */