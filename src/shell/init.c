/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:11:29 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/31 13:49:01 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	init_node(t_node **node)
{
	(*node) = malloc(sizeof(t_node));
	if (!(*node))
		return (0);
	(*node)->data = NULL;
	(*node)->tree = NULL;
	(*node)->next = NULL;
	return (1);
}

static int	init_tree(t_tree **tree)
{
	(*tree) = malloc(sizeof(t_tree));
	if (!(*tree))
		return (0);
	(*tree)->data = NULL;
	(*tree)->left = NULL;
	(*tree)->right = NULL;
	return (1);
}

static int	init_data(t_data **data)
{
	(*data) = malloc(sizeof(t_data));
	if (!(*data))
		return (0);
	(*data)->command = NULL;
	return (1);
}

static int	link_memory(t_memory *mem)
{
	ft_hold_mem(3, &mem->list, &mem->data, &mem->tree, &mem->node);
	mem->tree->data = mem->data;
	mem->node->tree = mem->tree;
	mem->node->data = mem->data;
	return (1);
}

int	init_memory(t_memory *mem, int ac, char **av, char **envp)
{
	mem->ac = ac;
	mem->av = av;
	mem->envp = envp;
	if (!init_data(&mem->data))
		return (0);
	if (!init_tree(&mem->tree))
		return (0);
	if (!init_node(&mem->node))
		return (0);
	if (!link_memory(mem))
		return (0);
	return (1);
}
