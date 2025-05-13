/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:53:55 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/05/13 17:23:42 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];

	if (argc != 5)
	{
		ft_printf("Invalid amount of arguments: <FILE1 COMMAND1 COMMAND2 FILE2>\n");
		exit(128); //invalid arg?
		return (0);
	}
	if (pipe(pipe_fd) == -1)
	{
		ft_printf("Failed to create pipe\n");
		return (0);
	}
	pipex(argv, envp, pipe_fd);
	return (0);
}
