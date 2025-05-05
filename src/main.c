/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:53:55 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/05/05 18:51:20 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		pid1;
	int		pid2;
	int 	infile_fd;
	int		outfile_fd;
	char	*path1;
	char	*path2;

	if (pipe(fd) == -1)
	{
		perror("fail to create pipe\n");
		exit(1);
	}
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("no fork1 on the table\n");
		exit(1);
	}
	if (pid1 == 0) //sólo esto se refirá al hijo, después estaremos en el padre / PRIMER COMANDO
	{
		infile_fd = open("infile", O_RDONLY);
		if (infile_fd < 0)
		{
			perror("failed to open infile\n");
			exit(1);
		}
		dup2(infile_fd, 0);
		close(infile_fd);
		dup2(fd[1], 1); //redirige salida estándar, duplica la salida
		close(fd[0]); //no use -- We close the pipe on this process
		close(fd[1]); // cerramos este porque está la estándar y esta abierta, y son copias?
		execve(PATH?, argv[1], envp);
	}
	pid2 = fork();
	if (pid2 < 0)
	{
		perror("no fork2 on the table\n");
		exit(1);
	}
	if (pid2 == 0) // SEGUNDO COMANDO
	{
		outfile_fd = open("outfile", O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (outfile_fd < 0)
		{
			perror("failed to open/create outfile\n");
			exit(1);
		}
		dup2(outfile_fd, 0);
		close(outfile_fd);
		dup2(fd[0], 0);
		close(fd[1]); //no use -- We close the pipe on this process
		close(fd[0]); // it remains open despite being duplicated, so we need to close it?
		execve(PATH?, 0, envp);
	}
	close(fd[0]); // Si no cerramos todos los fd de lectura , incluyendo al padre, no para de leer
	close(fd[1]);
	waitpid(pid1, 0, 0);
	waitpid(pid2, 0, 0);
	return (0);
}
