/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:22:11 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/31 09:28:40 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	free_command(t_command **cmd)
{
	if (cmd)
	{
		if ((*cmd)->args)
			free_2d((*cmd)->args);
		if ((*cmd)->cmd_path)
			free_null((void *)&(*cmd)->cmd_path);
		free(*cmd);
		*cmd = NULL;
	}
}
