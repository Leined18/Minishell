/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:11:29 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/13 11:38:29 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	init_data(t_data **data, char **envp)
{
	(*data) = ft_calloc(1, sizeof(t_data));
	if (!(*data))
		return (0);
	(*data)->envp = copy_envp(envp);
	(*data)->pid = getpid();
	return (1);
}

t_hash_table	*init_memory(char **envp, int size)
{
	t_hash_table	*mem;
	t_data			*data;

	data = NULL;
	mem = NULL;
	mem = ft_mthash_new_table(size, "memory");
	if (!(mem))
		return (0);
	if (!init_data(&data, envp))
		return (0);
	insert_ptr(mem, "structs", "data", data, NULL);
	insert_ptr(mem, "data", "envp", data->envp, ft_env_free_func);
	insert_description(mem, "structs", "arbol de datos");
	insert_description(mem, "data", "estructura de datos");
	return (mem);
}
