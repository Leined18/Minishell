/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:11:29 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/09 14:01:57 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "shell.h"
#define TOTAL_REFS 3

static int	init_node(t_node **node, t_ref **ref)
{
	(*node) = ft_calloc_ref(1, sizeof(t_node), ref, "node");
	// crea un nodo de referencia de node ref[2] y le asigna la direccion de memoria de node
	if (!(*node))
		return (0);
	return (1);
}

static int	init_tree(t_tree **tree, t_ref **ref)
{
	(*tree) = ft_calloc_ref(1, sizeof(t_tree), ref, "tree");
	// crea un nodo de referencia de tree ref[1] y le asigna la direccion de memoria de tree
	if (!(*tree))
		return (0);
	return (1);
}
static int	init_data(t_data **data, t_ref **ref)
{
	(*data) = ft_calloc_ref(1, sizeof(t_data), ref, "data");
	// crea un nodo de referencia de data ref[0] y le asigna la direccion de memoria de data
	if (!(*data))
		return (0);
	return (1);
}

static int	link_memory(t_memory *mem, t_ref **ref, int i)
{
	mem->tree->data = mem->data;
	mem->node->tree = mem->tree;
	mem->node->data = mem->data;
	while (i < TOTAL_REFS)
		ft_lstadd_ref(&mem->list, ref[i++]);
	// aqui estamos añadiendo las referencias a la lista; lista->content es el nodo de referencia
	mem->data->list = mem->list;
	mem->tree->list = mem->list;
	mem->node->list = mem->list;
	mem->data->ref = mem->ref; // ref es array de referencias
	mem->tree->ref = mem->ref; // ref[0] es data, ref[1] es tree, ref[2] es node
	mem->node->ref = mem->ref;
	// entonces puedes añadir a ref[0] todo lo que quieras y se eliminara en lista
	return (1);
}

int	init_memory(t_memory *mem, int ac, char **av, char **envp)
{
	mem->ac = ac;
	mem->av = av;
	mem->ref = ft_calloc(TOTAL_REFS, sizeof(t_ref *));
	// crea un array de referencias donde se guardara la direccion de memoria de los nodos de referencia
	if (!init_data(&mem->data, &mem->ref[0]))
		// crea un nodo de referencia de data ref[0] y le asigna la direccion de memoria de data
		return (0);
	if (!copy_envp(&mem->data->envp, envp, &mem->ref[0]))
		// copia el envp a la estructura data->envp y le asigna la direccion de memoria de data->envp a ref[0] que es la referencia de data
		return (0);
	if (!init_tree(&mem->tree, &mem->ref[1]))
		// crea un nodo de referencia de tree ref[1] y le asigna la direccion de memoria de tree a ref[1] que es la referencia de tree
		return (0);
	if (!init_node(&mem->node, &mem->ref[2]))
		// crea un nodo de referencia de node ref[2] y le asigna la direccion de memoria de node a ref[2] que es la referencia de node
		return (0);
	if (!link_memory(mem, mem->ref, 0)) // añade las referencias a la lista
		return (0);
	// ref [0] es data, ref[1] es tree, ref[2] es node,
	//son los 3 principales nodos de referencia que detras se añadirán los nuevos nodos de referencia que se creen por ejemplo,
	//envp se añade a ref[0]
	//
	//
	// list[0]->content->[Struct ref] -> [Struct ref] -> [Struct ref]->NULL
	//   |
	// list[1]->content->[Struct ref] -> [Struct ref] -> [Struct ref]->NULL
	//   |
	// list[2]->content->[Struct ref] -> [Struct ref] -> [Struct ref]->NULL
	//   |
	// list[3]->content->[Struct ref] -> [Struct ref] -> [Struct ref]-> NULL
	//   |
	//  NULL
		return (1);
}
