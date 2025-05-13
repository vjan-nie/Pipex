/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_fdx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:49:10 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/05/13 17:07:59 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_first_command(int *pipe_fd, char **argv, char **envp)
{
	int 	infile;
	char	**args;
	char	*cmd;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		ft_printf("no such file or directory\n");
		exit(128); //invalid arg
	}
	dup2(infile, 0);
	dup2(pipe_fd[1], 1); //redirige salida estándar, duplica la salida
	close(infile);
	close(pipe_fd[0]); //no use -- We close the pipe_fd on this process
	close(pipe_fd[1]); // cerramos este porque está la estándar y esta abierta, y son copias?
	args = ft_split(argv[2], ' ');
	cmd = ft_get_full_path(args[0], envp);
	if (!cmd) //si falla, liberar memoria dentro de proceso hijo!
	{
		ft_free_split(args);
		ft_printf("command not found: %s\n", cmd);
		exit(127); //command not found
	}
	execve(cmd, args, envp); //execve reemplazael proceso actual con el nuevo programa, 
	// el código del proceso original desaparece y es reemplazado por el nuevo ejecutable. 
	// Si falla: retorna -1, y el proceso continúa ejecutando desde la siguiente línea.
	// POR TANTO: liberar memoria!!
	free(cmd);
	ft_free_split(args);
	exit(1);
	return ;
}

static void	ft_second_command(int *pipe_fd, char **argv, char **envp)
{
	int 	outfile;
	char	**args;
	char	*cmd;

	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		exit(1);
	dup2(outfile, 1); //redirección salida estándar a outfile
	dup2(pipe_fd[0], 0);
	close(outfile);
	close(pipe_fd[1]); //no use -- We close the pipe_fd on this process
	close(pipe_fd[0]); // it remains open despite being duplicated, so we need to close it?
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
	return ;
}

void	pipex(char **argv, char **envp, int *pipe_fd)
{
	int		pid1;
	int		pid2;

	pid1 = fork();
	if (pid1 < 0)
		exit(1);
	if (pid1 == 0) //sólo esto se refirá al hijo, después estaremos en el padre / PRIMER COMANDO
		ft_first_command(pipe_fd, argv, envp);
	pid2 = fork();
	if (pid2 < 0)
		exit(1);
	if (pid2 == 0) // SEGUNDO COMANDO
		ft_second_command(pipe_fd, argv, envp);
	close(pipe_fd[0]); // Si no cerramos todos los fd de lectura , incluyendo al padre, no para de leer
	close(pipe_fd[1]);
	return ;
}
