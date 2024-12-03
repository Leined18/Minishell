/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:11:29 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/03 12:31:32 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	init_data(t_data **data, int ac, char **av, char **envp)
{
	(*data) = ft_calloc(1, sizeof(t_data));
	if (!(*data))
		return (0);
	(*data)->ac = ac;
	(*data)->av = av;
	(*data)->envp = envp;
	return (1);
}

t_memory	*init_memory(int ac, char **av, char **envp)
{
	t_data		*data;
	t_memory	*mem;

	data = NULL;
	mem = NULL;
	mem = ft_calloc(1, sizeof(t_memory));
	if (!(mem))
		return (0);
	if (!init_data(&data, ac, av, envp))
		return (0);
	mem->ht = ft_mthash_new_table(5, "memory");
	insert_ptr(mem->ht, "structs", "tree structs", data, "data");
	return (mem);
}
