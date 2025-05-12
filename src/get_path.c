/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:12:13 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/05/12 13:11:38 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_check_command(char *command, char **envp)
{
	char	*full_path;

	full_path = ft_get_full_path(command, envp);
	if (full_path)
	{
		free(full_path);
		return (1);
	}
	return (0);
}

char	*ft_get_full_path(char *command, char **envp)
{
	char	**paths;
	char	*full_path;
	char	*path;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i ++;
	if (!envp[i]) //path not found
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(path, command);
		free(path);
		if (access(full_path, X_OK) == 0)
		{
			ft_free_split(paths);
			return (full_path);
		}
		free(full_path);
		i ++;
	}
	ft_free_split(paths);
	return (NULL);
}
