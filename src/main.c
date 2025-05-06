/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:53:55 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/05/06 13:43:42 by vjan-nie         ###   ########.fr       */
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
	char	**args1;
	char	**args2;
	char	*cmd1;
	char	*cmd2;

	if (argc != 5)
	{
		perror("Invalid ammount of args");
		exit(1);
		return (0);
	}
	if (pipe(fd) == -1)
	{
		perror("fail to create pipe");
		exit(1);
		return (0);
	}
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("no fork1 on the table");
		exit(1);
	}
	if (pid1 == 0) //sólo esto se refirá al hijo, después estaremos en el padre / PRIMER COMANDO
	{
		infile_fd = open(argv[1], O_RDONLY);
		if (infile_fd < 0)
		{
			perror("failed to open infile");
			exit(1);
		}
		dup2(infile_fd, 0);
		dup2(fd[1], 1); //redirige salida estándar, duplica la salida
		close(infile_fd);
		close(fd[0]); //no use -- We close the pipe on this process
		close(fd[1]); // cerramos este porque está la estándar y esta abierta, y son copias?
		args1 = ft_split(argv[2], ' ');
		cmd1 = ft_get_full_path(args1[0], envp);
		if (!cmd1) //si falla, liberar memoria dentro de proceso hijo!
		{
			ft_free_split(args1);
			exit(1);
		}
		execve(cmd1, args1, envp); //execve reemplazael proceso actual con el nuevo programa, 
		// el código del proceso original desaparece y es reemplazado por el nuevo ejecutable. 
		// Si falla: retorna -1, y el proceso continúa ejecutando desde la siguiente línea.
		// POR TANTO: liberar memoria!!
		perror("execve1 failed");
		free(cmd1);
		ft_free_split(args1);
		exit(1);
	}
	pid2 = fork();
	if (pid2 < 0)
	{
		perror("no fork2 on the table");
		exit(1);
	}
	if (pid2 == 0) // SEGUNDO COMANDO
	{
		outfile_fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (outfile_fd < 0)
		{
			perror("failed to open/create outfile");
			exit(1);
		}
		dup2(outfile_fd, 1); //redirección salida estándar a outfile
		dup2(fd[0], 0);
		close(outfile_fd);
		close(fd[1]); //no use -- We close the pipe on this process
		close(fd[0]); // it remains open despite being duplicated, so we need to close it?
		args2 = ft_split(argv[3], ' ');
		cmd2 = ft_get_full_path(args2[0], envp);
		if (!cmd2)
		{
			ft_free_split(args2);
			exit(1);
		}
		execve(cmd2, args2, envp);
		perror("execve2 failed");
		free(cmd2);
		ft_free_split(args2);
		exit(1);
	}
	close(fd[0]); // Si no cerramos todos los fd de lectura , incluyendo al padre, no para de leer
	close(fd[1]);
	waitpid(pid1, 0, 0);
	waitpid(pid2, 0, 0);
	return (0);
}
