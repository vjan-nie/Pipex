/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:49:10 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/05/13 18:42:25 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_close_three(int fd1, int fd2, int fd3)
{
	close(fd1);
	close(fd2);
	close(fd3);
	return ;
}

static void	ft_first_command(int *pipe_fd, char **argv, char **envp)
{
	int		infile;
	char	**args;
	char	*cmd;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		ft_printf("no such file or directory: %s\n", argv[1]);
		exit(1);
	}
	dup2(infile, 0);
	dup2(pipe_fd[1], 1);
	ft_close_three(infile, pipe_fd[0], pipe_fd[1]);
	args = ft_split(argv[2], ' ');
	cmd = ft_get_full_path(args[0], envp);
	if (!cmd)
	{
		ft_free_split(args);
		ft_printf("command not found: %s\n", cmd);
		exit(127);
	}
	execve(cmd, args, envp);
	free(cmd);
	ft_free_split(args);
	exit(1);
}

static void	ft_second_command(int *pipe_fd, char **argv, char **envp)
{
	int		outfile;
	char	**args;
	char	*cmd;

	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		exit(1);
	dup2(outfile, 1);
	dup2(pipe_fd[0], 0);
	close(outfile);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	args = ft_split(argv[3], ' ');
	cmd = ft_get_full_path(args[0], envp);
	if (!cmd)
	{
		ft_free_split(args);
		ft_printf("command not found: %s\n", cmd);
		exit(127);
	}
	execve(cmd, args, envp);
	free(cmd);
	ft_free_split(args);
	exit(1);
}

void	pipex(char **argv, char **envp, int *pipe_fd)
{
	int		pid1;
	int		pid2;

	pid1 = fork();
	if (pid1 < 0)
		exit(1);
	if (pid1 == 0)
		ft_first_command(pipe_fd, argv, envp);
	pid2 = fork();
	if (pid2 < 0)
		exit(1);
	if (pid2 == 0)
		ft_second_command(pipe_fd, argv, envp);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	return ;
}
