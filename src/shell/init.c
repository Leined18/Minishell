/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:11:29 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/07 12:31:59 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "shell.h"

static int	init_node(t_node **node, t_list **lst)
{
	(*node) = malloc(sizeof(t_node));
	if (!(*node))
		return (0);
	ft_lstadd_front(lst, ft_lstnew((void **)node));
	(*node)->data = NULL;
	(*node)->tree = NULL;
	(*node)->next = NULL;
	(*node)->list = *lst;
	return (1);
}

static int	init_tree(t_tree **tree, t_list **lst)
{
	(*tree) = malloc(sizeof(t_tree));
	if (!(*tree))
		return (0);
	ft_lstadd_front(lst, ft_lstnew((void **)tree));
	(*tree)->data = NULL;
	(*tree)->left = NULL;
	(*tree)->right = NULL;
	(*tree)->list = *lst;
	return (1);
}
static int	init_data(t_data **data, t_list **lst)
{
	(*data) = malloc(sizeof(t_data));
	if (!(*data))
		return (0);
	ft_lstadd_front(lst, ft_lstnew((void **)data));
	(*data)->envp = NULL;
	(*data)->list = *lst;
	(*data)->pid = 0;
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
	if (!init_data(&mem->data, &mem->list))
		return (0);
	if (!copy_envp(&mem->data->envp, envp, &mem->list))
		return (0);
	if (!init_tree(&mem->tree, &mem->list))
		return (0);
	if (!init_node(&mem->node, &mem->list))
		return (0);
	if (!link_memory(mem))
		return (0);
	return (1);
}
