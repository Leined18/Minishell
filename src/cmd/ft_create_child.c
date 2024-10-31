/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_child.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:54:54 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/31 09:26:55 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	create_child(t_command *cmd, int *pipefd, int child_num)
{
	if (child_num == 1)
	{
		close(pipefd[0]);
		redirect_output(pipefd[1]);
	}
	else if (child_num == 2)
	{
		close(pipefd[1]);
		redirect_input(pipefd[0]);
	}
	execute_command(cmd);
}
