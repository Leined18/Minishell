/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:11:29 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/30 13:02:57 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	init_data(t_data **data, char **envp)
{
	(*data) = ft_calloc(1, sizeof(t_data));
	if (!(*data))
		return (0);
	(*data)->envp = copy_envp(envp);
	(*data)->pid = 0;
	return (1);
}

t_memory	*init_memory(char **envp)
{
	t_memory	*mem;
	t_data		*data;

	data = NULL;
	mem = NULL;
	mem = ft_calloc(1, sizeof(t_memory));
	if (!(mem))
		return (0);
	if (!init_data(&data, envp))
		return (0);
	mem->ht = ft_mthash_new_table(5, "memory");
	insert_ptr(mem->ht, "structs", "data", data, NULL);
	insert_ptr(mem->ht, "data", "envp", data->envp, ft_env_free_func);
	insert_description(mem->ht, "structs", "arbol de datos");
	insert_description(mem->ht, "data", "estructura de datos");
	return (mem);
}
