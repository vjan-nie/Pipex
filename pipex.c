/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:02:57 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/04/01 20:10:13 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
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
}
