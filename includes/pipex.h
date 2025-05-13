/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:29:05 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/05/13 17:58:50 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h> //malloc, free, exit
# include <fcntl.h> // open, close
# include <unistd.h> // read, write, access, dup, dup2, execve, fork, pipe, unlink
# include <stdio.h> // perror !! careful with printf!!
# include <string.h> // strerror
# include <sys/wait.h> // wait, waitpid
# include "libft.h"

void	pipex(char **argv, char **envp, int *pipe_fd);
void	ft_free_split(char **split);
char	*ft_get_full_path(char *command, char **envp);

#endif
