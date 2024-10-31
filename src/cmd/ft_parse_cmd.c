/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:10:02 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/31 10:10:54 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

t_command	*parse_command(char *input, char **environ)
{
	t_command	*cmd;
	char		**args;

	args = ft_split(input, ' ');
	if (!args || !args[0])
		return (NULL);
	cmd = malloc(sizeof(t_command));
	if (!cmd)
		return (free_2d(args), NULL);
	cmd->cmd_path = NULL;
	if (environ)
		cmd->cmd_path = get_cmd_path(args[0], environ);
	if ((access(args[0], X_OK) && !cmd->cmd_path) || access(cmd->cmd_path,
			X_OK))
		return (free_2d(args), ft_memdel(2, NULL, &cmd->cmd_path, &cmd), NULL);
	cmd->command = args[0];
	cmd->args = args;
	return (cmd);
}
