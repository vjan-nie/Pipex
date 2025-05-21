/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:13:47 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/05/21 11:32:49 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_not_found(char *cmd, char **args)
{
	ft_putstr_fd("command not found: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", 2);
	ft_free_split(args);
	exit(127);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i ++;
	}
	free(split);
}

char	**ft_build_path(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i ++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

char	*ft_get_full_path(char *command, char **envp)
{
	char	**paths;
	char	*full_path;
	char	*path;
	int		i;

	full_path = NULL;
	paths = ft_build_path(envp);
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(path, command);
		free(path);
		if (access(full_path, X_OK) == 0)
			return (ft_free_split(paths), full_path);
		free(full_path);
		full_path = NULL;
		i ++;
	}
	return (ft_free_split(paths), NULL);
}

char	*ft_check_path(char *command, char **envp)
{
	char	*full_path;

	if (ft_strchr(command, '/'))
	{
		full_path = ft_strdup(command);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		else
		{
			free(full_path);
			return (NULL);
		}
	}
	else
	{
		full_path = ft_get_full_path(command, envp);
		return (full_path);
	}
	return (NULL);
}
