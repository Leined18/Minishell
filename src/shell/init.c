/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:11:29 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/03 13:45:06 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	init_data(t_data **data, char **envp)
{
	(*data) = ft_calloc(1, sizeof(t_data));
	if (!(*data))
		return (0);
	(*data)->envp = copy_envp(envp);
	(*data)->pid = 0;
	return (1);
}

void	ft_mtset_free_func(t_mt *node, void (*free_func)(void **))
{
	node->free_data = free_func;
}

void	ft_mthash_set_free_func(t_hash_table *ht, char *key,
		void (*free_func)(void **))
{
	t_mt	*node;

	node = ht->methods.search(ht, key);
	if (node)
		ft_mtset_free_func(node, free_func);
}

t_memory	*init_memory(char **envp)
{
	t_data		*data;
	t_memory	*mem;

	data = NULL;
	mem = NULL;
	mem = ft_calloc(1, sizeof(t_memory));
	if (!(mem))
		return (0);
	if (!init_data(&data, envp))
		return (0);
	mem->ht = ft_mthash_new_table(5, "memory");
	insert_ptr(mem->ht, "structs", "tree structs", data, "data");
	insert_ptr(mem->ht, "data", NULL, data->envp, "envp");
	ft_mthash_set_free_func(mem->ht, "envp", ft_env_free);
	return (mem);
}
