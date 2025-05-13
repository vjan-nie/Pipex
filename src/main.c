/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:53:55 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/05/13 18:32:30 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];

	if (argc != 5)
	{
		ft_printf("Invalid amount of arguments: <F1 CMND1 CMND2 F2>\n");
		exit(128);
		return (-1);
	}
	if (pipe(pipe_fd) == -1)
	{
		ft_printf("Failed to create pipe\n");
		return (-1);
	}
	pipex(argv, envp, pipe_fd);
	return (0);
}
