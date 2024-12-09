/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:14:31 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/09 10:44:54 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	insert_ptr(t_hash_table *mem, char *parent, char *child, void *data,
		void (*free_func)(void **))
{
	mem->methods.insert_child(mem, parent, child, data, PTR);
	if (free_func)
		mem->methods.set_free_func(mem, child, free_func);
}

void	insert_description(t_hash_table *mem, char *key, char *data)
{
	t_mt	*node;
	char	*new_key;

	node = mem->methods.search(mem, key);
	if (!node)
		return ;
	if (node->data)
	{
		new_key = ft_mtnew_key(node->key, "-description");
		mem->methods.insert_child(mem, key, new_key, ft_strdup(data), PTR);
		free(new_key);
	}
	else
		ft_replace(node, ft_strdup(data), STRING);
}
