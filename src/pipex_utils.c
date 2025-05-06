/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:13:47 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/05/06 12:18:21 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_split(char **split)
{
	int i;

	i = 0;
	if (!split)
		return;
	while (split[i])
	{
		free(split[i]);
		i ++;
	}
	free(split);
}
