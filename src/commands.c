/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:23:24 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/17 12:46:52 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_command(t_command *cmd)
{
	if (cmd)
	{
		if (cmd->args)
			free_2d(cmd->args);
		if (cmd->cmd_path)
			free(cmd->cmd_path);
		free(cmd);
	}
}
