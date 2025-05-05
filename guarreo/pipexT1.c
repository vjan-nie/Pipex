/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexT1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:02:57 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/05/05 18:01:38 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
# include <stdlib.h> //malloc, free, exit
# include <fcntl.h> // open, close
# include <unistd.h> // read, write, access, dup, dup2, execve, fork, pipe, unlink
# include <stdio.h> // perror
# include <string.h> // strerror
# include <sys/wait.h> // wait, waitpid

/* int	main(int argc, char *argv[], char *envp[]) //step 0
{
	int	fd[2]; // 2 file descriptors for pipe(): read 0 / write 1
	pid_t	pid; //pid_t is a data type used to represent process IDs (PIDs). It is typically a signed integer type.
	
	// How can I handle args?? envp??
	pipe(fd); //create pipe
	pid = fork(); // creates a new process (everytime we call it twice, it doubles!) <0 fail / 0 the child process / >0 parent process // getpid() not allowed!
	if (pid == 0) //child process??
	{
		close(fd[0]); // Close unused read end
		close(fd[1]); // Close duplicate
		execve(path?); // ??
		perror(??);
	}
	else //parent process?
	{
		close(fd[1]); // Close unused write end
		dup2(fd[0], STDIN_FILENO); // Redirect stdin to pipe
		close(fd[0]); // Close duplicate
		execve(?); // Execute grep ".c"
		perror(?);
	}
	return (0);
} */

/* int	main(void) //step 1: simple pipe
{
	int	 	pipe_fds[2];
	pid_t	pid;
	char	*buffer;
	int		bytes_read;

	printf("parent id: %d\n", getpid());
	pipe(pipe_fds);
	buffer = malloc(17);
	if (!buffer)
		return (-1);
	write(pipe_fds[1], "What's uuuuuup!\n", 16);
	pid = fork();
	printf("pid from fork: %d\n", pid);
	if (pid > 0)
	{
		printf("no fork? id: %d\n", pid);
		free(buffer);
		return (-1);
	}
	bytes_read = read(pipe_fds[0], buffer, 16);
	buffer[bytes_read] = '\0';
	printf("bytes_read: %d\n", bytes_read);
	printf("child pid: %d\n", getpid());
	printf("Message: %s\n", buffer);
	free(buffer);
	return (0);
} */

/* int	main(int argc, char **argv, char **envp) //step 2 :pipe with files
{
	int	 	pipe_fds[2];
	pid_t	pid;
	char	*buffer;
	char	*buffer2;
	int		bytes_read;
	int		infile_fd;
	int		outfile_fd;
	int		i;

	if (argc != 5)
		return (-1);
	infile_fd = open(argv[1], O_RDONLY);
	if (infile_fd < 0)
		return (-1);
	outfile_fd = open(argv[4], O_RDWR); // or just write only??
	if (outfile_fd < 0)
		return (-1);
	pipe(pipe_fds);
	buffer = malloc(17);
	if (!buffer)
		return (-1);
	bytes_read = read(infile_fd, buffer, 16);
	printf("bytes_read from infile: %d\n", bytes_read);
	buffer[bytes_read] = '\0';
	i = 0;
	while (buffer[i])
	{
		write(pipe_fds[1], &buffer[i], 1);
		i ++;
	}
	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		printf("child pid from fork?: %d\n", pid);
		printf("child pid: %d\n", getpid());
		buffer2 = malloc(17);
		if (!buffer2)
		{
			free(buffer);
			close(infile_fd);
			close(outfile_fd);
			return (-1);
		}
	}
	else
	{
		printf("parent fork? id: %d\n", pid);
		free(buffer);
		close(infile_fd);
		close(outfile_fd);
		return (-1);
	}
	
	
	bytes_read = read(pipe_fds[0], buffer2, 16);
	buffer2[bytes_read] = '\0';
	i = 0;
	while (buffer2[i])
	{
		write(outfile_fd, &buffer2[i], 1);
		i ++;
	}
	free(buffer);
	free(buffer2);
	close(infile_fd);
	close(outfile_fd);
	return (0);
} */

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (pipe(fd) == -1)
	{
		perror("fail to create pipe\n");
		return (-1);
	}
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("no fork1 on the table\n");
		return (-1);
	}
	if (pid1 == 0) //sólo esto se refirá al hijo, después estaremos en el padre / PRIMER COMANDO
	{
		dup2(fd[1], 1); //redirige salida estándar, duplica la salida
		close(fd[0]); //no use -- We close the pipe on this process
		close(fd[1]); // cerramos este porque está la estándar y esta abierta, y son copias?
		execve(PATH?, argv[1], envp);
	}
	pid2 = fork();
	if (pid2 < 0)
	{
		perror("no fork2 on the table\n");
		return (-1);
	}
	if (pid2 == 0) // SEGUNDO COMANDO
	{
		dup2(fd[0], 0);
		close(fd[1]); //no use -- We close the pipe on this process
		close(fd[0]); // it remains open despite being duplicated, so we need to close it?
		execve(PATH?, argv[1], envp);
	}
	close(fd[0]); // Si no cerramos todos los fd de lectura , incluyendo al padre, no para de leer
	close(fd[1]);
	waitpid(pid1, 0, 0);
	waitpid(pid2, 0, 0);
	return (0);
}
