/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:21:58 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/28 16:02:07 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "config.h"
#include "minishell.h"

int	init_node(t_node **node)
{
	(*node) = malloc(sizeof(t_node));
	if (!(*node))
		return (0);
	(*node)->data = NULL;
	(*node)->tree = NULL;
	(*node)->next = NULL;
	return (1);
}

int	init_tree(t_tree **tree)
{
	(*tree) = malloc(sizeof(t_tree));
	if (!(*tree))
		return (0);
	(*tree)->data = NULL;
	(*tree)->left = NULL;
	(*tree)->right = NULL;
	return (1);
}

int	init_data(t_data **data)
{
	(*data) = malloc(sizeof(t_data));
	if (!(*data))
		return (0);
	(*data)->command = NULL;
	return (1);
}

int	link_memory(t_memory *mem)
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

int	clean_up(t_memory *mem)
{
	if (mem->data)
		free_null(mem->data);
	if (mem->tree)
		free_null(mem->tree);
	if (mem->node)
		free_null(mem->node);
	mem->data = NULL;
	mem->tree = NULL;
	mem->node = NULL;
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_memory mem;

	mem = (t_memory){0};

	if (argc >= 2)
	{
		write(1, "Usage: ./minishell\n", 19);
		return (1);
	}
	if (!init_memory(&mem, argc, argv, envp))
		ft_error("Error in memory allocation\n", 0);
	clean_up(&mem);
	printf(HOLA);
	ft_successful(SUCCESS, 0);
	return (0);
}