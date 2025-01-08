/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:14:31 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/08 10:24:30 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	insert_ptr(t_hash_table *mem, char *parent, char *aux, void *data,
		void (*free_func)(void **))
{
	mem->methods.insert_aux(mem, parent, aux, data, PTR);
	if (free_func)
		mem->methods.set_free_func(mem, aux, free_func);
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
		mem->methods.insert_aux(mem, key, new_key, ft_strdup(data), PTR);
		free(new_key);
	}
	else
		ft_replace_data(node, ft_strdup(data), STRING);
}

void	ft_set_priority(t_mt *list, void *param, void (*func)(t_mt *, void *))
{
	if (!list || !func)
		return ;
	ft_mtiter(list, param, func);
}

int	pred(t_mt *lst, void *p)
{
	if (!lst)
		return (-1);
	if (lst->values.priority == *(int *)p && lst->values.state != END)
		return (1);
	return (0);
}
