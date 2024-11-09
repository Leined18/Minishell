/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:33:24 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/09 13:49:57 by danpalac         ###   ########.fr       */
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
	cmd = malloc(sizeof(t_command)); // ejemplo de como se añade una nueva referencia a la lista a travez de ref[0] o ref[1] o ref[2] ...
	ref = ft_refnew((void **)&cmd, "cmd", 1); // crea un nuevo nodo de referencia de cmd
	ft_refadd_back(&mem->ref[0], ref); // añade el nodo de referencia al final de la lista ref que ya esta incluida en list
	return (1);
}
