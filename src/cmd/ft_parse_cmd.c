/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:10:02 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/08 23:54:54 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

t_command	*parse_command(char *input, char **environ, t_list **lst)
{
	t_command	*cmd;
	char		**args;

	(void)lst;
	cmd = malloc(sizeof(t_command));
	if (!cmd)
		return (NULL);
	ft_memset(cmd, 0, sizeof(t_command));
	args = ft_split(input, ' ');
	if (!args || !args[0])
		return (free_null((void **)&cmd), NULL);
	if (environ)
		cmd->cmd_path = get_cmd_path(args[0], environ);
	if ((access(args[0], X_OK) && !cmd->cmd_path) || access(cmd->cmd_path,
			X_OK))
		return (free_null((void **)&cmd->cmd_path), free_2d(cmd->args),
			free_null((void **)&cmd), NULL);
	cmd->command = args[0];
	cmd->args = args;
	return (cmd);
}
