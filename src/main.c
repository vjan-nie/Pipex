/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:53:55 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/05/16 00:03:48 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];

	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 2);
		exit(1);
	}
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe error");
		exit(129);
	}
	pipex(argv, envp, pipe_fd);
	return (0);
}
