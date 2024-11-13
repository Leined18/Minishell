/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:11:29 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/13 10:19:55 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	init_node(t_node **node)
{
	(*node) = chaosmatrix(1, sizeof(t_node), 0);
	if (!(*node))
		return (0);
	return (1);
}

static int	init_tree(t_tree **tree)
{
	(*tree) = ft_calloc(1, sizeof(t_tree));
	if (!(*tree))
		return (0);
	return (1);
}
static int	init_data(t_data **data)
{
	(*data) = ft_calloc(1, sizeof(t_data));
	if (!(*data))
		return (0);
	return (1);
}

static int	link_memory(t_memory *mem)
{
	mem->tree->data = mem->data;
	mem->node->tree = mem->tree;
	mem->node->data = mem->data;
	mem->data->list = mem->list;
	mem->tree->list = mem->list;
	mem->node->list = mem->list;
	return (1);
}

int	init_memory(t_memory *mem, int ac, char **av, char **envp)
{
	mem->ac = ac;
	mem->av = av;
	(void)envp;
	if (!init_data(&mem->data))
		return (0);
	/* if (!copy_envp(&mem->data->envp, envp))
		return (0); */
	if (!init_tree(&mem->tree))
		return (0);
	if (!init_node(&mem->node))
		return (0);
	if (!link_memory(mem))
		return (0);
	return (1);
}
