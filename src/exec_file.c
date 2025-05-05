/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:42:42 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/05/05 18:46:12 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_exec(char *cmd, char **paths)
{
	char	*path;

	if ((ft_strncmp(cmd, "./", 2) == 0) \
		&& access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	while (*paths)
	{
		path = ft_strjoin(*paths, "/");
		path = ft_strjoin(path, cmd);
		if (access(path, X_OK) == 0)
			return (path);
		paths++;
	}
	perror("no exec");
	return (NULL);
}
