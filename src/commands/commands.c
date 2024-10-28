/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:23:24 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/28 15:37:18 by mvidal-h         ###   ########.fr       */
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
