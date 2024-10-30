/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:23:24 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/30 10:45:21 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_command(t_command **cmd)
{
	if (cmd && *cmd)
	{
		if ((*cmd)->args)
			free_2d(&(*cmd)->args);
		if ((*cmd)->cmd_path)
			free_null((void *)&(*cmd)->cmd_path);
		free_null((void *)&(*cmd));
	}
}
