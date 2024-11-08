/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:11:29 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/08 17:38:57 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "shell.h"

static int	init_node(t_node **node, t_ref **ref)
{
	(*node) = ft_calloc_ref(1, sizeof(t_node), ref, "node");
	if (!(*node))
		return (0);
	return (1);
}

static int	init_tree(t_tree **tree, t_ref **ref)
{
	(*tree) = ft_calloc_ref(1, sizeof(t_tree), ref, "tree");
	if (!(*tree))
		return (0);
	return (1);
}
static int	init_data(t_data **data, t_ref **ref)
{
	(*data) = ft_calloc_ref(1, sizeof(t_data), ref, "data");
	if (!(*data))
		return (0);
	return (1);
}

static int	link_memory(t_memory *mem)
{
	mem->tree->data = mem->data;
	mem->node->tree = mem->tree;
	mem->node->data = mem->data;
	ft_lstadd_ref(&mem->list, mem->ref);
	mem->data->list = mem->list;
	mem->tree->list = mem->list;
	mem->node->list = mem->list;
	return (1);
}

int	init_memory(t_memory *mem, int ac, char **av, char **envp)
{
	mem->ac = ac;
	mem->av = av;
	if (!init_data(&mem->data, &mem->ref))
		return (0);
	if (!copy_envp(&mem->data->envp, envp, &mem->ref))
		return (0);
	if (!init_tree(&mem->tree, &mem->ref))
		return (0);
	if (!init_node(&mem->node, &mem->ref))
		return (0);
	if (!link_memory(mem))
		return (0);
	return (1);
}
