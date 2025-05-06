/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:29:05 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/05/06 13:30:38 by vjan-nie         ###   ########.fr       */
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

int		ft_check_command(char *command, char **envp);
char	*ft_get_full_path(char *command, char **envp);
void	ft_free_split(char **split);

#endif
