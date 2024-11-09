/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:33:24 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/09 14:04:43 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"
#include "input.h"

int	parse_arguments(t_memory *mem, int ac, char **av, char **ev)
{
	t_ref		*ref;
	t_command	*cmd;

	if (ac >= 3)
	{
		write(1, "Usage: ./minishell\n", 19);
		return (0);
	}
	if (!init_memory(mem, ac, av, ev))
		return (0);
	return (1);
}
