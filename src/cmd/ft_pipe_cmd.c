/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:55:01 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/31 09:39:36 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	pipe_commands(t_command *cmd1, t_command *cmd2)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (!cmd1 || !cmd2)
		return ;
	if (pipe(pipefd) == -1)
		ft_error("Error al crear el pipe\n", 1);
	pid1 = fork();
	if (pid1 == -1)
		ft_error("Error al hacer fork\n", 1);
	if (pid1 == 0)
		create_child(cmd1, pipefd, 1);
	pid2 = fork();
	if (pid2 == -1)
		ft_error("Error al hacer fork\n", 1);
	if (pid2 == 0)
		create_child(cmd2, pipefd, 2);
	handle_parent(pipefd, pid1, pid2);
}
