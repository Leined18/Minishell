/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:11:29 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/13 13:13:17 by danpalac         ###   ########.fr       */
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
	(*tree) = chaosmatrix(1, sizeof(t_tree), 0);
	if (!(*tree))
		return (0);
	return (1);
}
static int	init_data(t_data **data)
{
	(*data) = chaosmatrix(1, sizeof(t_data), 0);
	if (!(*data))
		return (0);
	return (1);
}

static int	link_memory(t_memory *mem)
{
	mem->tree->data = mem->data;
	mem->node->tree = mem->tree;
	mem->node->data = mem->data;
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
